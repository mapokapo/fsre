/*
int a,b,c;
if(a<0 && b<0) {
	c=a+b;
} else if (a==0 || b==0) {
	c++;
} else {
	c=b-a;
}
*/

.equ a, 0
.equ b, 0
.equ c, 3

.global _start

.text
_start:
	MOV r0, #a
	MOV r1, #b
	MOV r2, #c

	// IF
	CMP r0, #0
	BLT if
	CMP r1, #0
	BLT if

checkelseif:
	// ELSE IF
	CMP r0, #0
	BEQ elseif
	CMP r1, #0
	BEQ elseif

	//ELSE
else:
	SUB r2, r1, r0

	B stop

if:
	CMP r1, #0
	BGE checkelseif
	CMP r0, #0
	BGE checkelseif

	ADD r2, r0, r1

	B stop

elseif:
	ADD r2, r2, #1

	B stop

stop:
	B stop

.end
