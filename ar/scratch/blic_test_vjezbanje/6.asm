// Napisati program koji ce iz zadanog niza (zakljucenim podatkom 0xF0000000) svakom pozitivnom clanu zamijeniti dva okteta najmanje vrijednosti.

.global _start

.text
_start:
	ADR r0, podaci
	MOV r1, #0 // counter

petlja:
	LDR r2, [r0], #4

	CMP r2, #0xF0000000
	BEQ stop
	
	AND r5, r2, #0x80000000
	CMP r5, #0x80000000
	BNE pozitivan

	B petlja

pozitivan:
	MOV r3, r2
	MOV r4, r2

	AND r3, r3, #0xFFFFFF00
	AND r4, r4, #0xFFFF00FF

	MOV r3, r3, LSR #8
	MOV r4, r4, LSL #8

	ORR r2, r3, r4

	STR r2, [r0, #-4]

	B petlja

stop:
	B stop

podaci:
.word 37, 25, -10, 5, 265, 0xF0000000

.end
