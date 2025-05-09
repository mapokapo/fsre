/*
int x, y, z;
do {
	z= x*x-2;
	y++;
	x++;
} while (y<10);
*/

.equ x, 2
.equ y, 1

.global _start

.text
_start:
	MOV r0, #x
	MOV r1, #y

dowhile:
	MUL r3, r0, r0
	SUB r2, r3, #2

	ADD r1, r1, #1

	ADD r0, r0, #1

	CMP r1, #10
	BLT dowhile

stop:
	B stop

.end
