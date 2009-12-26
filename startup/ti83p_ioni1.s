	.module crt0_ti83p_ioni1

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
	.db 0xbb, 0x6d
	ret
	jr nc, start
