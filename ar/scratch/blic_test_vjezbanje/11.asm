/* Napisati potprogram koji ce uvecati dva broja za 2. Napisati i glavni program koji ucitava brojeve iz memorije potom poziva takav potprogram i po zavrsetku potprograma sprema nove brojeve u isti niz.*/

.global _start

.text
_start:
	ADR r0, niz

	LDR r1, [r0], #4
	LDR r2, [r0], #4

	BL potprogram

	STR r1, [r0], #4
	STR r2, [r0], #4

	B stop

potprogram:
	ADD r1, r1, #2
	ADD r2, r2, #2

	MOV PC, LR

stop:
	B stop

niz:
	.word 5, 10

.end
