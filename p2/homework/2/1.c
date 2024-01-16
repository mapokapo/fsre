#include <stdio.h>

/*
	Leo Petrovic 2174/RR

	Zadatak 1. - Napisati program koji definira strukturu za zapis podataka o kompleksnim brojevima:
	realni i imaginarni dio (float), unosi podatke za dva kompleksna broja i u posebnim
	funkcijama računa njihov zbroj, razliku, umnožak i količnik (sve funkcije imaju dva
	kompleksna broja kao ulazne parametre i vraćaju kompleksni broj koji predstavlja
	rezultat računske operacije). Svi rezultati se ispisuju u glavnom programu.
*/

struct kompleksni
{
	float realni;
	float imaginarni;
};

struct kompleksni zbroji_kompleksne_brojeve(struct kompleksni a, struct kompleksni b)
{
	struct kompleksni zbroj = {
			a.realni + b.realni,
			a.imaginarni + b.imaginarni,
	};

	return zbroj;
}

struct kompleksni oduzmi_kompleksne_brojeve(struct kompleksni a, struct kompleksni b)
{
	struct kompleksni razlika = {
			a.realni - b.realni,
			a.imaginarni - b.imaginarni,
	};

	return razlika;
}

struct kompleksni pomnozi_kompleksne_brojeve(struct kompleksni a, struct kompleksni b)
{
	struct kompleksni umnozak = {
			a.realni * b.realni - a.imaginarni * b.imaginarni,
			a.realni * b.imaginarni + a.imaginarni * b.realni,
	};

	return umnozak;
}

struct kompleksni podijeli_kompleksne_brojeve(struct kompleksni a, struct kompleksni b)
{
	struct kompleksni kolicnik = {
			(a.realni * b.realni + a.imaginarni * b.imaginarni) / (b.realni * b.realni + b.imaginarni * b.imaginarni),
			(a.imaginarni * b.realni - a.realni * b.imaginarni) / (b.realni * b.realni + b.imaginarni * b.imaginarni),
	};

	return kolicnik;
}

int main()
{
	struct kompleksni broj1, broj2, zbroj, razlika, umnozak, kolicnik;

	printf("Unesite prvi kompleksni broj: \n");
	printf(" - realni dio: ");
	scanf("%f", &broj1.realni);
	printf(" - imaginarni dio: ");
	scanf("%f", &broj1.imaginarni);

	printf("Unesite drugi kompleksni broj: \n");
	printf(" - realni dio: ");
	scanf("%f", &broj2.realni);
	printf(" - imaginarni dio: ");
	scanf("%f", &broj2.imaginarni);

	zbroj = zbroji_kompleksne_brojeve(broj1, broj2);
	printf("Zbroj: (%.2f, %.2fi) + (%.2f, %.2fi) = (%.2f, %.2fi)\n", broj1.realni, broj1.imaginarni, broj2.realni, broj2.imaginarni, zbroj.realni, zbroj.imaginarni);

	razlika = oduzmi_kompleksne_brojeve(broj1, broj2);
	printf("Razlika: (%.2f, %.2fi) - (%.2f, %.2fi) = (%.2f, %.2fi)\n", broj1.realni, broj1.imaginarni, broj2.realni, broj2.imaginarni, razlika.realni, razlika.imaginarni);

	umnozak = pomnozi_kompleksne_brojeve(broj1, broj2);
	printf("Umnozak: (%.2f, %.2fi) * (%.2f, %.2fi) = (%.2f, %.2fi)\n", broj1.realni, broj1.imaginarni, broj2.realni, broj2.imaginarni, umnozak.realni, umnozak.imaginarni);

	kolicnik = podijeli_kompleksne_brojeve(broj1, broj2);
	printf("Kolicnik: (%.2f, %.2fi) / (%.2f, %.2fi) = (%.2f, %.2fi)\n", broj1.realni, broj1.imaginarni, broj2.realni, broj2.imaginarni, kolicnik.realni, kolicnik.imaginarni);

	return 0;
}