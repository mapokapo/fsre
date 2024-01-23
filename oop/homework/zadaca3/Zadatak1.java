package oop.homework.zadaca3;

/*
* Leo Petrović - 2174/RR
* 
* Zadatak 1. - Definirajte razred GeometrijskoTijelo sa sljedećim članovima: podatkovni članovi tipa double Volumen i Oplosje, statički podatkovni član tipa int BrojacTijela, konstruktor koji podatkovnim članovima daje proslijeđene vrijednosti, i metodu koja nadjačava metodu toString() ispisujući podatkovne članove objekta te njegov redni broj. Definirajte razrede Kugla i Kvadar izvedene iz razreda GeometrijskoTijelo. Definirajte razred Kocka izvedenog iz klase Kvadar. Definirajte objekte kugla, kvadar i kocka razreda Kugla, Kvadar i Kocka i povećajte vrijednost varijable BrojacTijela za 1 sa svakom definicijom objekta.
*/

class GeometrijskoTijelo {
	private static int BrojacTijela = 0;

	private double Volumen;
	private double Oplosje;

	public GeometrijskoTijelo(double volumen, double oplosje) {
		this.Volumen = volumen;
		this.Oplosje = oplosje;

		GeometrijskoTijelo.BrojacTijela++;
	}

	public static int getBrojacTijela() {
		return BrojacTijela;
	}

	public double getVolumen() {
		return Volumen;
	}

	public void setVolumen(double volumen) {
		Volumen = volumen;
	}

	public double getOplosje() {
		return Oplosje;
	}

	public void setOplosje(double oplosje) {
		Oplosje = oplosje;
	}

	@Override
	public String toString() {
		return String.format("Tijelo #%d: {%n\tVolumen = %.2f,%n\tOplosje = %.2f%n}", GeometrijskoTijelo.BrojacTijela,
				this.Volumen, this.Oplosje);
	}
}

class Kugla extends GeometrijskoTijelo {
	public Kugla(double volumen, double oplosje) {
		super(volumen, oplosje);
	}
}

class Kvadar extends GeometrijskoTijelo {
	public Kvadar(double volumen, double oplosje) {
		super(volumen, oplosje);
	}
}

class Kocka extends Kvadar {
	public Kocka(double volumen, double oplosje) {
		super(volumen, oplosje);
	}
}

public class Zadatak1 {
	public static void main(String[] args) {
		Kugla kugla = new Kugla(((double) 4 / 3) * Math.PI, 4 * Math.PI); // jedinicna kugla
		System.out.println("Kugla = " + kugla);

		Kvadar kvadar = new Kvadar(2, 10); // kvadar dimenzija 2x1x1
		System.out.println("Kvadar = " + kvadar);

		Kocka kocka = new Kocka(1, 6); // jedinicna kocka
		System.out.println("Kocka = " + kocka);
	}
}
