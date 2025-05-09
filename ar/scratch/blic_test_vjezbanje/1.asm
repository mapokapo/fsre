// Napisati program koji racuna sumu svih brojeva od 1 do N, gdje je N proizvoljna konstanta.

.equ N, 10

.global _start

.text
_start:
	MOV r0, #0
	MOV r1, #N
	MOV r2, #0

petlja:
	CMP r0, r1
	BGE stop

	ADD r0, #1

	ADD r2, r0

	B petlja

stop:
	B stop

.end
