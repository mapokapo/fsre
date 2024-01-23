// Napisati program koji ce svako drugi clan zadanog niza podijeliti sa 4 i spremiti na novu lokaciju pocevsi na memorijskoj lokaciji 0x00001000.

.global _start

.text
_start:
	ADR r0, podaci
	MOV sp, #0x00001000
	MOV r1, #0 // counter

petlja:
	LDR r2, [r0], #4

	CMP r2, #0
	BEQ stop

	ADD r1, r1, #1

	AND r1, #1
	CMP r1, #1
	BEQ upisi

	B petlja

upisi:
	MOV r2, r2, LSR #2
	STR r2, [sp], #4
	B petlja

stop:
	B stop

podaci:
.word 12, 16, 8, -8, 20, 20, 0

.end
