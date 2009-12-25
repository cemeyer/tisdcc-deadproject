#   libtisdcc.py - Compiles C programs targetting TI z80 calculators
#   Copyright (C) 2009 Conrad Meyer <konrad@tylerc.org>
#
#   This program is free software: you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation, either version 3 of the License, or
#   (at your option) any later version.
#
#   This program is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License for more details.
#
#   You should have received a copy of the GNU General Public License
#   along with this program.  If not, see <http://www.gnu.org/licenses/>.



import os
import shutil
import subprocess
import tempfile



VERSION = "0.2"



PLATFORMS = ("ti83", \
             "ti83_ion", \
             "ti83p", \
             "ti83p_ion", \
             "ti83p_mirage", \
             "ti85_zshell", \
             "ti85_usgard", \
             "ti82_ace", 
             "ti86")

CODELOC = {"ti83": "0x9327", \
           "ti83_ion": "0x9327", \
           "ti83p": "0x9D93", \
           "ti83p_ion": "0x9D93", \
           "ti83p_mirage": "0x9D93", \
           "ti85_zshell": "0x", \
           "ti85_usgard": "0x", \
           "ti82_ace": "0x", \
           "ti86": "0xD748"}

DATALOC = {"ti83": "0x8265",
           "ti83_ion": "0x8265", \
           "ti83p": "0x9872", \
           "ti83p_ion": "0x9872", \
           "ti83p_mirage": "0x9872", \
           "ti85_zshell": "0x80DF", \
           "ti85_usgard": "0x", \
           "ti82_ace": "0x", \
           "ti86": "0x9872"}



class CodeType:
  C = 1
  ASM = 2
  OBJECT = 3
  LIBRARY = 4
  IHX = 5
  PROGRAM = 6
  UNKNOWN = 7



class CodeObject(object):
  """
  CodeObjects represent bodies of code, be it C, asm, object, or linked
  binaries.
  """


  def __init__(self, type, contents, fromfile="<None>"):
    self.type = type
    self.contents = contents
    self.srcfile = fromfile


  def writetofile(self, filename):
    print "Wrote: %s" % filename
    fh = open(filename, "wb")
    fh.write(self.contents)
    fh.close()


  def replaceext(self, newext):
    loc = self.srcfile.rfind(".")
    if loc < 0:
      raise Exception("Source filename '%s' has no extension." % \
          self.srcfile)

    return self.srcfile[:loc] + newext



def infer_type_from_file(filename):
  type = CodeType.UNKNOWN
  if filename.endswith(".c"):
    type = CodeType.C
  elif filename.endswith(".asm"):
    type = CodeType.ASM
  elif filename.endswith(".o"):
    type = CodeType.OBJECT
  elif filename.endswith(".lib"):
    type = CodeType.LIBRARY
  elif filename.endswith(".ihx"):
    type = CodeType.IHX
  elif filename[-4:-2] == ".8":
    type = CodeType.PROGRAM
  return type



def codeobject_from_file(filename, tempfile=False):
  """
  Loads a codeobject from file.
  """

  fh = open(filename, "rb")
  type = infer_type_from_file(filename)
  if not tempfile:
    return CodeObject(type, fh.read(), fromfile=filename)
  else:
    return CodeObject(type, fh.read())



def binary_extension(calc_name):
  parts = calc_name.split("_", 1)
  ctype = 'p'
  if len(parts) > 1 and parts[1] == "app":
    ctype = 'k'

  model = parts[0]
  if model == "ti83":
    return '83p'
  elif model == "ti82":
    return '82p'
  elif model == "ti83p":
    return '8x' + ctype
  elif model == "ti85p":
    return '85p'
  elif model == "ti86":
    return '86p'

  raise Exception("unknown calculator model '%s'" % calc_name)



def compile(codeobj, extraflags=[]):
  assert(codeobj.type == CodeType.C)

  cwd = os.getcwd()
  wd = None
  try:
    wd = tempfile.mkdtemp()

    assert(len(wd) > 4)
    os.chdir(wd)

    osfh, tempsrc = tempfile.mkstemp(suffix=".c", dir=wd)
    os.close(osfh)
    fh = open(tempsrc, "wb")
    fh.write(codeobj.contents)
    fh.close()

    proc = subprocess.Popen(["sdcc", "-mz80", "--opt-code-size", \
        "--peep-asm", "--stack-auto", "--std-sdcc99", "--portmode=z80"] + \
        extraflags + ["-c", tempsrc], \
        shell=False, close_fds=True, stderr=subprocess.PIPE, \
        stdout=subprocess.PIPE, stdin=subprocess.PIPE)
    stdout, stderr = proc.communicate()

    if os.path.exists(tempsrc.replace(".c",".o")):
      return codeobject_from_file(tempsrc.replace(".c",".o"), \
          tempfile=True)

    print "stdout:"
    print stdout
    print "stderr:"
    print stderr
    raise Exception("failed to compile")

  finally:
    os.chdir(cwd)

    # clean up after ourselves
    if wd is not None:
      shutil.rmtree(wd)



def link(codeobjlist, target, libdir, extraflags=[]):
  assert(len(codeobjlist) >= 1)
  assert(target in PLATFORMS)
  for codeobj in codeobjlist:
    assert(codeobj.type == CodeType.OBJECT)

  cwd = os.getcwd()
  wd = None
  try:
    wd = tempfile.mkdtemp()

    assert(len(wd) > 4)
    os.chdir(wd)

    srcfiles = []
    for codeobj in codeobjlist:
      osfh, tempsrc = tempfile.mkstemp(suffix=".o", dir=wd)
      os.close(osfh)
      fh = open(tempsrc, "wb")
      fh.write(codeobj.contents)
      fh.close()
      srcfiles.append(tempsrc)
    
    outfile = "empty.ihx"

    startupobjfile1 = "%s/%s1.o" % (libdir, target)
    startupobjfile2 = "%s/%s2.o" % (libdir, target)
    emptyobj = "%s/empty.o" % libdir
    program = ["sdcc", "-mz80", "--no-std-crt0", "--code-loc", \
        CODELOC[target], "--data-loc", DATALOC[target]] + extraflags + \
        ["-Wl" + startupobjfile1] + \
        ["-Wl" + fn for fn in srcfiles] + \
        ["-Wl" + startupobjfile2] + [emptyobj]
    proc = subprocess.Popen(program, \
        shell=False, close_fds=True, stderr=subprocess.PIPE, \
        stdout=subprocess.PIPE, stdin=subprocess.PIPE)
    stdout, stderr = proc.communicate()

    if os.path.exists(outfile):
      return codeobject_from_file(outfile, tempfile=True)

    print "stdout:"
    print stdout
    print "stderr:"
    print stderr
    raise Exception("failed to link")
  finally:
    os.chdir(cwd)

    # clean up after ourselves
    if wd is not None:
      shutil.rmtree(wd)
