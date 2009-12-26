	.module crt0_ti83p_ion2

	.area _CODE
	.db 0
start::
	ld (exitSP), sp
	di
	call gsinit
	.globl _main
	call _main
_exit::
	ld sp,(exitSP)
	ld iy,#0x89F0
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

