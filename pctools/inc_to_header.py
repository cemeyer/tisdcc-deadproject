# This reads from stdin, writes to stdout.

import re,sys

defvars = {}
macro = False

for line in sys.stdin:
  if ";" in line:
    line = line[:line.find(";")]
  line = line.strip()

  if line == "": continue

  if macro and line == ".endm":
    macro = False
    continue
  elif macro:
    continue

  defin = line.split(None, 2)

  if len(defin) < 2:
    print "not2", defin
    sys.exit(1)

  equ = defin[1]
  if equ == "macro":
    macro = True
    continue

  if len(defin) != 3:
    print "not3", defin
    sys.exit(1)

  var, equ, expr = defin

  if equ.upper() != "EQU":
    print "equ", defin
    sys.exit(1)

  # expr can be:
  #   * binary value '0001101b'
  #   * decimal value '23426'
  #   * hex '25h'
  #   * combination of equs and const in expr

  def converthex(matchobj):
    str = matchobj.group(0)
    prefix = ""
    suffix=""
    if str[0] in ("+", "-"):
      prefix = str[0]
      str = str[1:]
    if str[-1] in (" ", "+", "-"):
      suffix = str[-1]
      str = str[:-1]
    return prefix + ("%d" % int(str[:-1], 16)) + suffix

  def convertbin(matchobj):
    str = matchobj.group(0)
    prefix = ""
    suffix=""
    if str[0] in ("+", "-"):
      prefix = str[0]
      str = str[1:]
    if str[-1] in (" ", "+", "-"):
      suffix = str[-1]
      str = str[:-1]
    return prefix + ("%d" % int(str[:-1], 2)) + suffix

  def convertdec(matchobj):
    str = matchobj.group(0)
    prefix = ""
    suffix=""
    if str[0] in ("+", "-"):
      prefix = str[0]
      str = str[1:]
    if str[-1] in (" ", "+", "-"):
      suffix = str[-1]
      str = str[:-1]
    return prefix + ("%d" % int(str, 10)) + suffix

  expr = re.sub("(^|[+-])[0-9A-Fa-f]+[hH]($|[ +\-])", converthex, expr)
  expr = re.sub("(^|[+-])[01]+[bB]($|[ +\-])", convertbin, expr)
  expr = re.sub("(^|[+-])[0]+[0-9]+($|[ +\-])", convertdec, expr)

  exprval = eval(expr, defvars)
  defvars[var] = exprval

  try:
    if exprval > 255 and exprval < 2**16:
      print "#define %s___db 0x%02x, 0x%02x" % (var, exprval % 256, exprval / 256)
      print "#define %s___dw 0x%04x" % (var, exprval)
    elif exprval >= 0 and exprval < 256:
      print "#define %s___ 0x%02x" % (var, exprval)
    else:
      print "failed", exprval
      sys.exit(1)
  except:
    print str(var), str(exprval), type(exprval)
    raise
