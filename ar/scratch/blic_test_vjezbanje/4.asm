// Napisati program koji broji broj neparnih brojeva u zadanom nizu.

.global _start

.text
_start:
	ADR r0, podaci
	MOV r1, #0

petlja:
	LDR r2, [r0], #4

	CMP r2, #0
	BEQ stop

	AND r3, r2, #1
	CMP r3, #1
	ADDEQ r1, #1

	B petlja
stop:
	B stop

podaci:
.word 2, 3, -1, -2, 1, 15, 0

.end
