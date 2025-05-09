// Napisati program koji ce iz zadanog niza pronaci najveci i najmanji clan

.global _start

.text
_start:
	ADR r0, podaci
	MOV r1, #0 // counter

	LDR r3, [r0] // r3 = min
	LDR r4, [r0] // r4 = max

petlja:
	LDR r2, [r0], #4

	CMP r2, #0
	BEQ stop

	CMP r2, r3
	MOVLT r3, r2

	CMP r2, r4
	MOVGT r4, r2

	B petlja

stop:
	B stop

podaci:
.word 1, 2, -4, 8, -5, 6, 0

.end
