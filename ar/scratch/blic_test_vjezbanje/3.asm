// Napisati program koji zamjeni svako slovo A i E sa velikim slovom X, bez obzira je li slovo veliko ili malo.

.global _start

.text
_start:
	ADR r0, string
	MOV r2, #'X'

petlja:
	LDRB r1, [r0], #1

	CMP r1, #0
	BEQ stop

	CMP r1, #'A'
	BEQ zamjeni
	CMP r1, #'a'
	BEQ zamjeni

	CMP r1, #'E'
	BEQ zamjeni
	CMP r1, #'e'
	BEQ zamjeni

	B petlja

zamjeni:
	STRB r2, [r0, #-1]
	B petlja

stop:
	B stop

string:
	.byte 'H', 'a', 'E', 'L', 'o', 0x00000000

.end
