	.module crt0_ti83_ion1

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

	ret
	jr nc, start
