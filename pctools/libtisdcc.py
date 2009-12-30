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
import sys
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

PLATFORMDATA = {"ti83": \
                  {'codeloc': "0x9327", \
                   'dataloc': "0x8265", \
                   }, \
                "ti83_ion": \
                  {'codeloc': "0x9327", \
                   'dataloc': "0x8265", \
                   }, \
                "ti83p": \
                  {'codeloc': "0x9D93", \
                   'dataloc': "0x9872", \
                   }, \
                "ti83p_ion": \
                  {'codeloc': "0x9D93", \
                   'dataloc': "0x9872", \
                   }, \
                "ti83p_mirage": \
                  {'codeloc': "0x9D93", \
                   'dataloc': "0x9872", \
                   }, \
                "ti85_zshell": \
                  {'codeloc': "0x", \
                   'dataloc': "0x80DF", \
                   }, \
                "ti85_usgard": \
                  {'codeloc': "0x", \
                   'dataloc': "0x", \
                   }, \
                "ti82_ace": \
                  {'codeloc': "0x", \
                   'dataloc': "0x", \
                   }, \
                "ti86": \
                  {'codeloc': "0xD748", \
                   'dataloc': "0x9872", \
                   }, \
                   }



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


  def writetofile(self, filename, silent=False):
    if not silent:
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



def codeobject_for_progname(name, model):
  # dummy for ti83_asm, ti83p_asm, ti86_asm (nowhere to put a name)
  dummy = False
  if model in ("ti83", "ti83p", "ti86"):
    dummy = True

  nullterminated = 0
  if model in ("ti82_crash", "ti73_mallard", "ti83_ion", "ti83p_ion", \
      "ti83p_mirage", "ti85_zshell"):
    nullterminated = 1

  forcelength = False
  if model.endswith("_app"):
    forcelength = 8

  if forcelength and len(name) > forcelength:
    name = name[:forcelength]

  # Pad name to forcelength size
  if forcelength:
    name += " "*(forcelength - len(name))

  objbody = ""
  if dummy:
    objbody += "XL\nH 1 areas 0 global symbols\nA _CODE size 0 flags 0\n"
  else:
    objbody += "XL\nH 1 areas 1 global symbols\nM name\n"
    objbody += "A _CODE size %d flags 0\n" % (len(name) + nullterminated)
    objbody += "S name Def0000\nT 00 00"
    for c in name:
      objbody += " %2x" % ord(c)
    if nullterminated:
      objbody += " 00"

    objbody += "\nR 00 00 00 00\n"

  return CodeObject(CodeType.OBJECT, objbody)
    



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



def compile(codeobj, options):
  assert(codeobj.type == CodeType.C)

  cwd = os.getcwd()
  wd = None
  stdout = ""
  stderr = ""
  try:
    wd = tempfile.mkdtemp()

    assert(len(wd) > 4)
    os.chdir(wd)

    osfh, tempsrc = tempfile.mkstemp(suffix=".c", dir=wd)
    os.close(osfh)
    fh = open(tempsrc, "wb")
    fh.write(codeobj.contents)
    fh.close()

    extraflags = []
    if options.includes:
      for incp in options.includes:
        extraflags.append("-I%s" % incp)
    if options.defines:
      for defn in options.defines:
        extraflags.append("-D%s" % defn)

    proc = subprocess.Popen(["sdcc", "-mz80", "--opt-code-size", \
        "--peep-asm", "--stack-auto", "--std-sdcc99", "--portmode=z80"] + \
        extraflags + ["-c", tempsrc], \
        shell=False, close_fds=True, stderr=subprocess.PIPE, \
        stdout=subprocess.PIPE, stdin=subprocess.PIPE)
    stdout, stderr = proc.communicate()

    if os.path.exists(tempsrc.replace(".c",".o")):
      return codeobject_from_file(tempsrc.replace(".c",".o"), \
          tempfile=True)

    raise Exception("failed to compile")
  except:
    print "wd:", wd
    raise
  else:
    # clean up after ourselves
    if wd is not None:
      shutil.rmtree(wd)
  finally:
    sdccoutput(stdout, stderr)
    os.chdir(cwd)



def link(codeobjlist, target, libdir, name, extraflags=[]):
  assert(len(codeobjlist) >= 1)
  assert(target in PLATFORMS)
  for codeobj in codeobjlist:
    assert(codeobj.type == CodeType.OBJECT)

  cwd = os.getcwd()
  wd = None
  stdout = ""
  stderr = ""
  try:
    wd = tempfile.mkdtemp()

    assert(len(wd) > 4)
    os.chdir(wd)

    nameobj = codeobject_for_progname( \
        CodeObject(None, None, fromfile=name).replaceext(""), target)
    nameobj.writetofile("%s/name.o" % wd, silent=True)

    srcfiles = []
    for codeobj in codeobjlist:
      osfh, tempsrc = tempfile.mkstemp(suffix=".o", dir=wd)
      os.close(osfh)
      fh = open(tempsrc, "wb")
      fh.write(codeobj.contents)
      fh.close()
      srcfiles.append(tempsrc)
    
    outfile = srcfiles[0].replace(".o", ".ihx")

    startupobjfile1 = "%s/%s1.o" % (libdir, target)
    startupobjfile2 = "%s/%s2.o" % (libdir, target)
    emptyobj = "%s/empty.o" % libdir
    program = ["sdcc", "-mz80", "--no-std-crt0", "--code-loc", \
        PLATFORMDATA[target]['codeloc'], "--data-loc", \
        PLATFORMDATA[target]['dataloc']] + extraflags + \
        ["-Wl" + startupobjfile1, "-Wlname.o", "-Wl" + startupobjfile2] + \
        srcfiles
    proc = subprocess.Popen(program, \
        shell=False, close_fds=True, stderr=subprocess.PIPE, \
        stdout=subprocess.PIPE, stdin=subprocess.PIPE)
    stdout, stderr = proc.communicate()

    if os.path.exists(outfile):
      return codeobject_from_file(outfile, tempfile=True)

    raise Exception("failed to link")
  except:
    print "wd:", wd
    raise
  else:
    # clean up after ourselves
    if wd is not None:
      shutil.rmtree(wd)
  finally:
    sdccoutput(stdout, stderr)
    os.chdir(cwd)



def ihx_to_prgm(co, name, target):
  # ihx2bin
  lines = co.contents.split("\n")
  minaddr = int("ffff", 16)
  maxaddr = 0
  for line in lines:
    if line == "": continue

    addr = int(line[3:7], 16)   # skip 3 characters; next 4 make a word
    type = int(line[7:9], 16)   # next 2 characters make a byte

    if type == 0:
      if addr < minaddr:
        minaddr = addr
      if addr > maxaddr:
        maxaddr = addr

  bin = {}
  maxpos = 0

  for line in lines:
    if line == "": continue

    leng = int(line[1:3], 16)   # skip 1; next 2 make a byte
    addr = int(line[3:7], 16)   # next 4 make a word
    type = int(line[7:9], 16)   # next 2 characters make a byte

    if type == 0:
      pos = addr - minaddr
      for i in range(leng):
        bin[pos + i] = chr(int(line[9+i*2:11+i*2], 16))
      if pos + leng - 1 > maxpos:
        maxpos = pos + leng - 1

  bincontents = ""
  for i in range(maxpos + 1):
    bincontents += bin.get(i, "\x00")

  # bin2var

  # Valid var names are 8 chars (max) + null terminator ; all uppercase
  # and alphanumeric only.

  name = name.split(".", 1)[0]
  varname = ""
  for c in name:
    if not c.isalnum(): continue
    varname += c.upper()
    if len(varname) >= 8:
      break

  varcontents = ""
  n = len(bincontents)
  model = target.split("_",1)[0]
  if model == "ti82":
    varcontents += "**TI82**\x1a\x0a\x00"
  elif model == "ti83":
    varcontents += "**TI83**\x1a\x0a\x00"
  elif model == "ti83p":
    varcontents += "**TI83F*\x1a\x0a\x00"
  elif model == "ti85":
    varcontents += "**TI85**\x1a\x0c\x00"
  elif model == "ti86":
    varcontents += "**TI86**\x1a\x0a\x00"

  # var comment -- 42 characters, NUL-padded
  comment = "Created with TISDCC %s" % VERSION
  varcontents += comment
  varcontents += "\x00"*(42 - len(comment))

  ckdcontents = ""
  if model == "ti82" or model == "ti83":
    varlen = n + 17
    ckdcontents += "\x0b\x00"
  elif model == "ti83p":
    varlen = n + 19
    ckdcontents += "\x0d\x00"
  elif model == "ti85":
    varlen = n + 10 + len(varname)
    ckdcontents += chr(4 + len(varname)) + "\x00"       # 2-byte, LE-aligned
  else:
    varlen = n + 18
    ckdcontents += "\x0c\x00"

  varcontents += chr(varlen % 256) + chr(varlen / 256)  # 2-byte, LE-aligned

  i = n + 2
  ckdcontents += chr(i % 256) + chr(i / 256)            # 2-byte, LE-aligned

  if model == "ti82" or model == "ti83" or model == "ti83p":
    ckdcontents += "\x06"
  elif model == "ti86":
    ckdcontents += "\x12"
  elif model == "ti85":
    ckdcontents += "\x0c"

  i = len(varname)
  if model == "ti85" or model == "ti86":
    ckdcontents += chr(i % 256)   # single byte
  ckdcontents += varname

  if model != "ti85":
    ckdcontents += "\x00"*(8 - i)
  if model == "ti83p":
    ckdcontents += "\x00\x00"

  i = n + 2
  ckdcontents += chr(i % 256) + chr(i / 256)            # 2-byte, LE-aligned
  ckdcontents += chr(n % 256) + chr(n / 256)            # 2-byte, LE-aligned
  ckdcontents += bincontents

  varcontents += ckdcontents
  
  # calculate 16 bit checksum, add it at the end
  chk = 0
  for c in ckdcontents:
    chk = (chk + ord(c)) % (2**16)

  varcontents += chr(chk % 256) + chr(chk / 256)        # 2-byte, LE-aligned

  return CodeObject(CodeType.PROGRAM, varcontents)



def compileonly(codeobj, options):
  assert(codeobj.type == CodeType.C)

  cwd = os.getcwd()
  wd = None
  stdout = ""
  stderr = ""
  try:
    wd = tempfile.mkdtemp()

    assert(len(wd) > 4)
    os.chdir(wd)

    osfh, tempsrc = tempfile.mkstemp(suffix=".c", dir=wd)
    os.close(osfh)
    fh = open(tempsrc, "wb")
    fh.write(codeobj.contents)
    fh.close()

    extraflags = []
    if options.includes:
      for incp in options.includes:
        extraflags.append("-I%s" % incp)
    if options.defines:
      for defn in options.defines:
        extraflags.append("-D%s" % defn)

    proc = subprocess.Popen(["sdcc", "-mz80", "--opt-code-size", \
        "--peep-asm", "--stack-auto", "--std-sdcc99", "--portmode=z80"] + \
        extraflags + ["-c", tempsrc], \
        shell=False, close_fds=True, stderr=subprocess.PIPE, \
        stdout=subprocess.PIPE, stdin=subprocess.PIPE)
    stdout, stderr = proc.communicate()

    if os.path.exists(tempsrc.replace(".c",".asm")):
      return codeobject_from_file(tempsrc.replace(".c",".asm"), \
          tempfile=True)

    raise Exception("failed to compile")
  except:
    print "wd:", wd
    raise
  else:
    # clean up after ourselves
    if wd is not None:
      shutil.rmtree(wd)
  finally:
    sdccoutput(stdout, stderr)
    os.chdir(cwd)



def library(codeobjlist, options):
  assert(len(codeobjlist) >= 1)
  assert(options.platform in PLATFORMS)
  assert(options.filename is not None)
  for codeobj in codeobjlist:
    assert(codeobj.type == CodeType.OBJECT)

  cwd = os.getcwd()
  wd = None
  stdout = ""
  stderr = ""
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
    
    outfile = wd + "/" + options.filename

    program = ["sdcclib", outfile] + srcfiles
    proc = subprocess.Popen(program, \
        shell=False, close_fds=True, stderr=subprocess.PIPE, \
        stdout=subprocess.PIPE, stdin=subprocess.PIPE)
    stdout, stderr = proc.communicate()

    if os.path.exists(outfile):
      return codeobject_from_file(outfile, tempfile=True)

    raise Exception("failed to create a library")
  except:
    print "wd:", wd
    raise
  else:
    # clean up after ourselves
    if wd is not None:
      shutil.rmtree(wd)
  finally:
    sdccoutput(stdout, stderr)
    os.chdir(cwd)



def sdccoutput(stdout, stderr):
  if stdout is not None and len(stdout) > 0:
    print "SDCC stdout:"
    sys.stdout.write(stdout)
  if stderr is not None and len(stderr) > 0:
    print "SDCC stderr:"
    sys.stdout.write(stderr)
