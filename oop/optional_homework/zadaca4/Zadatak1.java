package oop.optional_homework.zadaca4;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/*
 * potrebno je kreirati klasu Boksac koja sadrzi sljedece atribute: ime i kategoriju. Kategorija moze imati vrijednosti "laka", srednja i teska. Laka do 60kg, srednja od 60kg to 80kg, teska iznad 80kg. Kreirati sve potrebne metode. Kreirati niz boksaca (15) koristeci ArrayList. Potrebno je da program vrati koliko je boksaca u kojoj kategoriji.
 */

class Boksac {
	private String ime;
	private String kategorija;
	private int tezina;

	public Boksac() {
	}

	public Boksac(String ime, int tezina) {
		this.ime = ime;
		this.tezina = tezina;

		if (tezina < 60) {
			this.kategorija = "laka";
		} else if (tezina >= 60 && tezina < 80) {
			this.kategorija = "srednja";
		} else {
			this.kategorija = "teska";
		}
	}

	public String getIme() {
		return ime;
	}

	public void setIme(String ime) {
		this.ime = ime;
	}

	public String getKategorija() {
		return kategorija;
	}

	public int getTezina() {
		return tezina;
	}

	@Override
	public String toString() {
		return this.ime + ", " + this.tezina + "kg (" + this.kategorija + ")";
	}
}

public class Zadatak1 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		List<Boksac> boksaci = new ArrayList<>();

		int i = 0;
		while (i < 15) {
			String ime;
			int tezina;

			System.out.print("Unesite ime boksaca i kilazu: ");

			ime = scanner.next();
			try {
				tezina = Integer.parseInt(scanner.next());
			} catch (NumberFormatException e) {
				System.out.println("Niste unijeli broj");
				continue;
			}

			scanner.nextLine();

			boksaci.add(new Boksac(ime, tezina));

			i++;
		}

		scanner.close();

		List<Boksac> lakiBoksaci = new ArrayList<>();
		List<Boksac> srednjiBoksaci = new ArrayList<>();
		List<Boksac> teskiBoksaci = new ArrayList<>();

		for (Boksac boksac : boksaci) {
			switch (boksac.getKategorija()) {
				case "laka":
					lakiBoksaci.add(boksac);
					break;
				case "srednja":
					srednjiBoksaci.add(boksac);
					break;
				case "teska":
					teskiBoksaci.add(boksac);
					break;
				default:
					System.out.println("Nevalidna kategorija za boksaca: " + boksac.toString());
					break;
			}
		}

		System.out.println("Boksaci lake kategorije (" + lakiBoksaci.size() + "):");
		for (Boksac boksac : lakiBoksaci) {
			System.out.println(" - " + boksac);
		}

		System.out.println("Boksaci srednje kategorije (" + srednjiBoksaci.size() + "):");
		for (Boksac boksac : srednjiBoksaci) {
			System.out.println(" - " + boksac);
		}

		System.out.println("Boksaci teske kategorije (" + teskiBoksaci.size() + "):");
		for (Boksac boksac : teskiBoksaci) {
			System.out.println(" - " + boksac);
		}
	}
}
