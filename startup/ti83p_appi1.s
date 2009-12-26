	.module crt0_ti83p_appi1

	;; Ordering of segments for the linker.
	.area _HOME
	.area _CODE
	.area _GSINIT
	.area _GSFINAL
	.area _DATA
	.area _BSS
	.area _HEAP

	.area _CODE
	.db 0x80,0x0F                                   ; Field:                 Program length
	.db 0x00,0x00,0x00,0x00 ; Length=0 (N/A for unsigned apps)
	.db 0x80,0x12                   ; Field:                 Program type
	.db 0x01,0x04                   ; Type= Shareware, TI-83Plus
	.db 0x80,0x21                   ; Field:                 App ID
	.db 0x01                        ; Id = 1
	.db 0x80,0x31                   ; Field:                 App Build
	.db 0x01                        ; Build = 1
	.db 0x80,0x48                   ; Field:                 App Name
	;; .db 0x53,0x79,0x6c,0x6c,0x6f,0x20,0x20,0x20 ;Name = "Hello   " must be 8 characters
	;; name.o must follow this file
