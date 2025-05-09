package oop.optional_homework.zadaca5;

/*
 * Napisati program u kojem definirate klasu Sportas koji ima sljedece atribute: ime, sport. Definirati klasu Atleticar koja je izvedena iz klase Sportas. Definirati klase Trkac i BacacKugle koji se extendaju iz Atleticar. Potrebno je ispisati kojim se sportom sportas bavi, koliko je ukupno sportasa iz tog sporta. Definirati klasu Test koja ce testirati sve te klase.
 */

class Sportas {
	private String ime;
	private String sport;

	public Sportas(String ime, String sport) {
		this.ime = ime;
		this.sport = sport;
	}

	public String getIme() {
		return ime;
	}

	public void setIme(String ime) {
		this.ime = ime;
	}

	public String getSport() {
		return sport;
	}

	public void setSport(String sport) {
		this.sport = sport;
	}
}

class Atleticar extends Sportas {
	public Atleticar(String ime, String sport) {
		super(ime, sport);
	}
}

class Trkac extends Atleticar {
	private static int brojTrkaca = 0;

	public Trkac(String ime) {
		super(ime, "Trkanje");

		Trkac.brojTrkaca++;
	}

	public static int getBrojTrkaca() {
		return Trkac.brojTrkaca;
	}

	public static void setBrojTrkaca(int brojTrkaca) {
		Trkac.brojTrkaca = brojTrkaca;
	}

	@Override
	public String toString() {
		return String.format("%s se bavi sportom %s.", this.getIme(), this.getSport());
	}
}

class BacacKugle extends Atleticar {
	private static int brojBacacaKugle = 0;

	public BacacKugle(String ime) {
		super(ime, "Bacanje kugle");

		BacacKugle.brojBacacaKugle++;
	}

	public static int getBrojBacacaKugle() {
		return BacacKugle.brojBacacaKugle;
	}

	public static void setBrojBacacaKugle(int brojBacacaKugle) {
		BacacKugle.brojBacacaKugle = brojBacacaKugle;
	}

	@Override
	public String toString() {
		return String.format("%s se bavi sportom %s.", this.getIme(), this.getSport());
	}
}

class Test {
	public static void testiraj() {
		Trkac trkac1 = new Trkac("Jure Juric");
		Trkac trkac2 = new Trkac("Brzi Brzic");
		Trkac trkac3 = new Trkac("Munja Munjic");
		BacacKugle bacacKugle1 = new BacacKugle("Kuglof Kuglic");
		BacacKugle bacacKugle2 = new BacacKugle("Baco Bacac");

		System.out.println(trkac1);
		System.out.println(trkac2);
		System.out.println(trkac3);
		System.out.println(String.format("Na trkanju je trenutno %d ljudi.", Trkac.getBrojTrkaca()));
		System.out.println(bacacKugle1);
		System.out.println(bacacKugle2);
		System.out.println(String.format("Na bacanju kugle je trenutno %d ljudi.", BacacKugle.getBrojBacacaKugle()));
	}
}

public class Zadatak1 {
	public static void main(String[] args) {
		Test.testiraj();
	}
}
