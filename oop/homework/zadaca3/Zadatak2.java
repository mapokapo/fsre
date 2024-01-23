package oop.homework.zadaca3;

/*
* Leo Petrović - 2174/RR
* 
* Zadatak 2. - Definirajte razred NebeskoTijelo sa sljedećim članovima: podatkovni članovi tipa double BrzinaOkoOsi i BrzinaOkoSunca, konstruktor koji podatkovnim članovima daje proslijeđene vrijednosti, i metodu koja nadjačava metodu toString() ispisujući podatkovne članove. Definirajte razrede Planet i Satelit izvedene iz razreda NebeskoTijelo koji imaju dodatni podatkovni član tipa String Naziv, te im definirajte sljedeće konstruktore sa jednim String i dva double parametra koji će dodijeliti vrijednosti proslijeđenih argumenata nazivu tijela i naslijeđenim podatkovnim članovima. Definirajte dva objekta Zemlja i Mjesec tipova Planet i Satelit.
*/

class NebeskoTijelo {
	private double BrzinaOkoOsi;
	private double BrzinaOkoSunca;

	public NebeskoTijelo(double brzinaOkoOsi, double brzinaOkoSunca) {
		BrzinaOkoOsi = brzinaOkoOsi;
		BrzinaOkoSunca = brzinaOkoSunca;
	}

	public double getBrzinaOkoOsi() {
		return BrzinaOkoOsi;
	}

	public void setBrzinaOkoOsi(double brzinaOkoOsi) {
		BrzinaOkoOsi = brzinaOkoOsi;
	}

	public double getBrzinaOkoSunca() {
		return BrzinaOkoSunca;
	}

	public void setBrzinaOkoSunca(double brzinaOkoSunca) {
		BrzinaOkoSunca = brzinaOkoSunca;
	}

	@Override
	public String toString() {
		return String.format("Nebesko Tijelo: {%n\tBrzina Oko Osi = %.2f,%n\tBrzina Oko Sunca = %.2f%n}", this.BrzinaOkoOsi,
				this.BrzinaOkoSunca);
	}
}

class Planet extends NebeskoTijelo {
	private String Naziv;

	public Planet(double brzinaOkoOsi, double brzinaOkoSunca, String naziv) {
		super(brzinaOkoOsi, brzinaOkoSunca);
		Naziv = naziv;
	}

	public String getNaziv() {
		return Naziv;
	}

	public void setNaziv(String naziv) {
		Naziv = naziv;
	}

	@Override
	public String toString() {
		return String.format("Planet: {%n\tNaziv = %s%n\tBrzina Oko Osi = %.2f,%n\tBrzina Oko Sunca = %.2f%n}", this.Naziv,
				this.getBrzinaOkoOsi(), this.getBrzinaOkoSunca());
	}
}

class Satelit extends NebeskoTijelo {
	private String Naziv;

	public Satelit(double brzinaOkoOsi, double brzinaOkoSunca, String naziv) {
		super(brzinaOkoOsi, brzinaOkoSunca);
		Naziv = naziv;
	}

	public String getNaziv() {
		return Naziv;
	}

	public void setNaziv(String naziv) {
		Naziv = naziv;
	}

	@Override
	public String toString() {
		return String.format("Satelit: {%n\tNaziv = %s%n\tBrzina Oko Osi = %.2f,%n\tBrzina Oko Zemlje = %.2f%n}",
				this.Naziv, this.getBrzinaOkoOsi(), this.getBrzinaOkoSunca());
	}
}

public class Zadatak2 {
	public static void main(String[] args) {
		Planet Zemlja = new Planet(460, 30000, "Zemlja");
		Satelit Mjesec = new Satelit(4.61, 1022, "Mjesec");

		System.out.println(Zemlja);
		System.out.println(Mjesec);
	}
}
