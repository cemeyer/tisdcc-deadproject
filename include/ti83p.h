#define BCALL(__foobarbaz) .db 0xEF, __foobarbaz
#define BJUMP(__foobarbaz) .db 0xCD, BRT_JUMP0___, 0x00, __foobarbaz
