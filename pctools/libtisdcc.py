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



class CodeType:
  C = 1
  ASM = 2
  OBJECT = 3
  LIBRARY = 4
  BINARY = 5



class CodeObject(object):
  """
  CodeObjects represent bodies of code, be it C, asm, object, or linked
  binaries.
  """

  def __init__(self, type, contents, fromfile="<None>"):
    self.type = type
    self.contents = contents
    self.srcfile = fromfile



def infer_type_from_file(filename):
  type = CodeType.BINARY
  if filename.endswith(".c"):
    type = CodeType.C
  elif filename.endswith(".asm"):
    type = CodeType.ASM
  elif filename.endswith(".o"):
    type = CodeType.OBJECT
  elif filename.endswith(".lib"):
    type = CodeType.LIBRARY
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



def link(codeobjlist, extraflags=[]):
  assert(len(codeobjlist) >= 1)
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
    
    outfile = srcfiles[0].replace(".o", ".ihx")

    program = ["sdcc", "-mz80"] + extraflags + srcfiles
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



if __name__ == "__main__":
  a = codeobject_from_file("a.c")
  b = codeobject_from_file("b.c")

  ac = compile(a)
  bc = compile(b)
  
  bin = link([bc, ac])
  fh = open("./tmp-OUTPUT", "wb")
  fh.write(bin.contents)
  fh.close()
