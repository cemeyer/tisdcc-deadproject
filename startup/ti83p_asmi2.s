	.module crt0_ti83p_asmi2

	ld (exitSP), sp
	di
	ld hl, #interrupt
	ld (0x8A3F), hl                 ; 
	ld (0x8A7F), hl
	ld (0x8ABF), hl
	ld (0x8AFF), hl
	ld a, #0x8A
	ld i, a
	im 2
	ei

	call gsinit
	.globl _main
	call _main
_exit::
	ld sp,(exitSP)
	ld iy,#0x89F0
	im 1
	ret

interrupt:                        ; mini interrupt wrapper
	di
	ex af, af'
	exx
	ld (saveIY), iy
	ld iy, #0x89F0
cont_int:
	call #0x003A                    ; jump to TI-OS interrupt
	ld iy, (saveIY)                 ; during this command, an interrupt can accure!?!?!?
	ret

	.area _GSINIT
gsinit:
	.area _GSFINAL
	ret

	.area _CONST

	.area _DATA
exitSP:
	.ds 2
saveIY:
	.ds 2

