package oop.homework.zadaca3;

import java.util.InputMismatchException;
import java.util.Scanner;

/*
* Leo Petrović - 2174/RR
* 
* Zadatak 3. - Definirajte razred ProgramskiJezik sa sljedećim članovima: podatkovni član tipa double postotak, metode za dohvaćanje i postavljenje člana postotak. Definirajte razrede Proceduralni, Objektni, i Funkcionalni, izvedene iz razreda ProgramskiJezik. Definirajte tri objekta procedura, objekt i funkcija tipova Proceduralni, Objektni i Funkcionalni redom, te zatražite od korisnika da unese vrijednosti postotka za pojedini objekt. Ako je zbroj postotaka različit od 100, ispišite poruku o neispravnom unosu podataka i svaki od unesenih podataka proporcionalno umanjite kako bi njihov zbroj iznosio 100. Nakon toga odredite koja je vrsta programskog jezika najzastupljenija.
*/

class ProgramskiJezik {
	private double postotak;

	public ProgramskiJezik(double postotak) {
		this.postotak = postotak;
	}

	public double getPostotak() {
		return postotak;
	}

	public void setPostotak(double postotak) {
		this.postotak = postotak;
	}

	@Override
	public String toString() {
		return String.format("ProgramskiJezik: {%n\tpostotak = %.2f%%%n}", this.postotak);
	}
}

class Proceduralni extends ProgramskiJezik {
	public Proceduralni(double postotak) {
		super(postotak);
	}

	@Override
	public String toString() {
		return String.format("Proceduralni: {%n\tpostotak = %.2f%%%n}", this.getPostotak());
	}
}

class Objektni extends ProgramskiJezik {
	public Objektni(double postotak) {
		super(postotak);
	}

	@Override
	public String toString() {
		return String.format("Objektni: {%n\tpostotak = %.2f%%%n}", this.getPostotak());
	}
}

class Funkcionalni extends ProgramskiJezik {
	public Funkcionalni(double postotak) {
		super(postotak);
	}

	@Override
	public String toString() {
		return String.format("Funkcionalni: {%n\tpostotak = %.2f%%%n}", this.getPostotak());
	}
}

public class Zadatak3 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		Proceduralni procedura = new Proceduralni(0);
		Objektni objekt = new Objektni(0);
		Funkcionalni funkcija = new Funkcionalni(0);

		procedura.setPostotak(
				Zadatak3.unesiPostotak(scanner, "Unesite postotak proceduralnih jezika (bez '%' na kraju): "));
		objekt.setPostotak(
				Zadatak3.unesiPostotak(scanner, "Unesite postotak objektnih jezika (bez '%' na kraju): "));
		funkcija.setPostotak(
				Zadatak3.unesiPostotak(scanner, "Unesite postotak funkcionalnih jezika (bez '%' na kraju): "));

		double zbroj = procedura.getPostotak() + objekt.getPostotak() + funkcija.getPostotak();

		if (zbroj != 100) {
			System.out.println(
					"Zbroj postotaka nije jednak 100! Izvrsiti ce se proporcionalno podesavanje postotaka da bi zbroj bio 100.");

			procedura.setPostotak(procedura.getPostotak() / zbroj * 100);
			objekt.setPostotak(objekt.getPostotak() / zbroj * 100);
			funkcija.setPostotak(funkcija.getPostotak() / zbroj * 100);
		}

		System.out.println("Uneseni programski jezici su:");
		System.out.println(procedura);
		System.out.println(objekt);
		System.out.println(funkcija);

		ProgramskiJezik najzastupljeniji = procedura;
		for (ProgramskiJezik jezik : new ProgramskiJezik[] { objekt, funkcija }) {
			if (jezik.getPostotak() > najzastupljeniji.getPostotak()) {
				najzastupljeniji = jezik;
			}
		}

		System.out
				.println(String.format("Najzastupljeniji jezik je %s (%.2f%%).", najzastupljeniji.getClass().getSimpleName(),
						najzastupljeniji.getPostotak()));
	}

	private static double unesiPostotak(Scanner scanner, String upit) {
		Double postotak = null;

		do {
			System.out.print(upit);

			try {
				postotak = scanner.nextDouble();
				if (postotak < 0) {
					System.out.println("Postotak ne moze biti negativan!");
					postotak = null;
				}
			} catch (InputMismatchException e) {
				System.out.println("Unijeli ste nevazeci postotak!");
				scanner.next();
			}
		} while (postotak == null);

		return postotak;
	}
}
