	.module crt0_ti73_mlrd1

	;; Ordering of segments for the linker.
	.area _HOME
	.area _CODE
	.area _GSINIT
	.area _GSFINAL
	.area _DATA
	.area _BSS
	.area _HEAP

	.globl start

	.area _CODE
	.db 0xd9, 0x00
	.ascii "Duck"
	.dw start
