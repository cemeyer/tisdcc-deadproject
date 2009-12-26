	.module crt0_ti83_asm2

	ld (exitSP), sp
	di
	call gsinit
	.globl _main
	call _main
_exit::
	ld sp,(exitSP)
	ld iy,#0x8567
	ei
	ret


	.area _GSINIT
gsinit:
	.area _GSFINAL
	ret

	.area _CONST

	.area _DATA
exitSP:
	.ds 2

