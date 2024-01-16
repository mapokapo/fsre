// Napisati program koji ce poredati niz brojeva tako da su svi negativni brojevi na pocetku a pozitivni na kraju.

.global _start

.text
_start:
	ADR r0, podaci
	ADR r1, podaci

// nacin rada:
//    idi kroz niz sve dok se ne pronadje negativan broj. Kada se pronadje, zamjeni ga sa adresom na koju pokazuje r1.
//    zatim povecaj r1 da pokazuje na sljedeci element, za koji smo sigurni da je pozitivan broj jer smo ga upravo postavili.
petlja:
	LDR r2, [r0], #4

	CMP r2, #0 // zaustavi petlju ako smo dosli na kraj niza (broj 0)
	BEQ stop

	CMP r2, #0
	BGT petlja

	LDR r3, [r1]
	STR r2, [r1]
	STR r3, [r0, #-4]
	ADD r1, r1, #4

	B petlja

stop:
	B stop

podaci:
.word 1, -2, 3, -14, 24, -4, 2, 5, -7, -3, 0

.end
