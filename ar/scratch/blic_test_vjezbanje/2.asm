// Napisati program koji u zadanom nizu zamjenjuje sva velika slova sa malim i obratno.

// veliko => [65, 90]
// malo => [97, 122]

.global _start

.text
_start:
	ADR r0, string

petlja:
	LDRB r1, [r0], #1

	CMP r1, #0
	BEQ stop

	CMP r1, #97
	BGE malo

	CMP r1, #90
	BLE veliko

	B petlja

stop:
	B stop

veliko:
	CMP r1, #65
	BLT petlja

	ADD r1, r1, #32
	STRB r1, [r0, #-1]
	B petlja

malo:
	CMP r1, #122
	BGT petlja

	SUB r1, r1, #32
	STRB r1, [r0, #-1]
	B petlja

string:
	.byte 'H', 'e', 'l', 'l', 'o', 0x00000000

.end
