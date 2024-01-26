package oop.homework.zadaca4;

import java.util.Arrays;

/*
 * Leo Petrović - 2174/RR
 * 
 * Zadatak 1.
 */

// Napisati konstruktore za sve razrede, pri čemu konstruktori izvedenih razreda koriste konstruktor osnovnog razreda.
// Napisati get i set metode za sve podatkovne članove, te preopteretiti metodu toString() u svim razredima. 

// Definirati apstraktni razred Racunalo.
abstract class Racunalo {
	// Klasa Racunalo sadrzi podatkovne clanove za zapis modela racunala,
	// proizvodjaca, i koristenog OS-a (tekstualni podaci).
	private String proizvodjac;
	private String model;
	private String os;

	protected Racunalo(
			String proizvodjac,
			String model,
			String os) {
		this.proizvodjac = proizvodjac;
		this.model = model;
		this.os = os;
	}

	public String getModel() {
		return model;
	}

	public void setModel(String model) {
		this.model = model;
	}

	public String getProizvodjac() {
		return proizvodjac;
	}

	public void setProizvodjac(String proizvodjac) {
		this.proizvodjac = proizvodjac;
	}

	public String getOs() {
		return os;
	}

	public void setOs(String os) {
		this.os = os;
	}

	// Apstraktni razred Racunalo sadrži apstraktnu metodu dohvatiTipRacunala()
	// (bez ulaznih parametara, koja vraća tekstualni podatak o vrsti računala, tj.
	// "stolno računalo" ili "prijenosno računalo").
	public abstract String dohvatiTipRacunala();

	// Apstraktni razred Racunalo sadrži apstraktnu metodu izracunajPrenosivost()
	// (bez ulaznih parametara, koja vraća cjelobrojni podatak o kategoriji
	// prenosivosti uređaja na način da za prijenosna računala vraća njihovu težinu
	// zaokruženu na cijeli broj, a za stolna računala ju računa po formuli 5 +
	// volumen kučišta / 30).
	public abstract int izracunajPrenosivost();
}

// Definirati razrede StolnoRacunalo i PrijenosnoRacunalno koji nasljedjuju
// Racunalo.

class StolnoRacunalo extends Racunalo {
	// StolnoRacunalo dodatno sadrzi podatkovne clanove za zapis dimenzija kucista
	// (niz od 3 realna broja: visina, sirina, i dubina).
	private double[] dimenzije;

	public StolnoRacunalo(String proizvodjac, String model,
			String os) {
		super(proizvodjac, model, os);

		this.dimenzije = new double[3];
	}

	public StolnoRacunalo(
			String proizvodjac, String model,
			String os, double[] dimenzije) throws IllegalArgumentException {
		super(proizvodjac, model, os);

		if (dimenzije == null) {
			throw new IllegalArgumentException("Niz 'dimenzije' ne moze biti null.");
		}

		if (dimenzije.length != 3) {
			throw new IllegalArgumentException(
					"Niz 'dimenzije' mora imati tocno 3 elementa: visina, sirina, i dubina.");
		}

		this.dimenzije = Arrays.copyOf(dimenzije, dimenzije.length);
	}

	public double[] getDimenzije() {
		return dimenzije;
	}

	public void setDimenzije(double[] dimenzije) throws IllegalArgumentException {
		if (dimenzije == null) {
			throw new IllegalArgumentException("Niz 'dimenzije' ne moze biti null.");
		}

		if (dimenzije.length != 3) {
			throw new IllegalArgumentException(
					"Niz 'dimenzije' mora imati tocno 3 elementa: visina, sirina, i dubina.");
		}

		this.dimenzije = dimenzije;
	}

	public String dohvatiTipRacunala() {
		return "Stolno Racunalo";
	}

	public int izracunajPrenosivost() {
		return 5 + (int) ((dimenzije[0] * dimenzije[1] * dimenzije[2]) / 30);
	}

	@Override
	public String toString() {
		return String.format(
				"%s sa dimenzijama %.2fx%.2fx%.2f. Prenosivost: %d. Informacije: %s, %s, %s",
				this.dohvatiTipRacunala(), this.getDimenzije()[0], this.getDimenzije()[1],
				this.getDimenzije()[2],
				this.izracunajPrenosivost(),
				this.getProizvodjac(),
				this.getModel(),
				this.getOs());
	}
}

class PrijenosnoRacunalno extends Racunalo {
	// PrijenosnoRacunalo sadrzi podatkovne clanove za zapis podataka o kapacitetu
	// baterije (cijeli broj) i tezini racunala (realan broj).
	private int kapacitetBaterije;
	private double tezina;

	public PrijenosnoRacunalno(
			String proizvodjac,
			String model,
			String os, int kapacitetBaterije, double tezina) throws IllegalArgumentException {
		super(proizvodjac, model, os);

		if (kapacitetBaterije < 0) {
			throw new IllegalArgumentException("Broj 'kapacitetBaterije' mora biti pozitivan.");
		}

		if (tezina < 0) {
			throw new IllegalArgumentException("Realni broj 'tezina' mora biti pozitivan.");
		}

		this.kapacitetBaterije = kapacitetBaterije;
		this.tezina = tezina;
	}

	public int getKapacitetBaterije() {
		return kapacitetBaterije;
	}

	public void setKapacitetBaterije(int kapacitetBaterije) throws IllegalArgumentException {
		if (kapacitetBaterije < 0) {
			throw new IllegalArgumentException("Broj 'kapacitetBaterije' mora biti pozitivan.");
		}

		this.kapacitetBaterije = kapacitetBaterije;
	}

	public double getTezina() {
		return tezina;
	}

	public void setTezina(double tezina) throws IllegalArgumentException {
		if (tezina < 0) {
			throw new IllegalArgumentException("Realni broj 'tezina' mora biti pozitivan.");
		}

		this.tezina = tezina;
	}

	public String dohvatiTipRacunala() {
		return "Prijenosno Racunalo";
	}

	public int izracunajPrenosivost() {
		return (int) this.tezina;
	}

	@Override
	public String toString() {
		return String.format(
				"%s sa tezinom %.2fg. Kapacitet baterije je %d a prenosivost: %d. Informacije: %s, %s, %s",
				this.dohvatiTipRacunala(), this.getTezina(), this.getKapacitetBaterije(),
				this.izracunajPrenosivost(),
				this.getProizvodjac(),
				this.getModel(),
				this.getOs());
	}
}

// Definirati razred Netbook koja nasljedjuje PrijenosnoRacunalo.
// Dodatno je potrebno onemoguciti daljnje nasljeđivanje razreda Netbook.
final class Netbook extends PrijenosnoRacunalno {
	public Netbook(
			String proizvodjac, String model,
			String os, int kapacitetBaterije, double tezina) {
		super(proizvodjac, model, os, kapacitetBaterije, tezina);
	}

	// Metoda dohvatiTipRacunala() vraća "netbook prijenosno računalo" koristeći
	// metodu nadređenog razreda.
	@Override
	public String dohvatiTipRacunala() {
		return "Netbook " + super.dohvatiTipRacunala();
	}

	// Metoda izracunajPrenosivost() u ovom razredu uvijek vraća 1.
	@Override
	public int izracunajPrenosivost() {
		return 1;
	}

	@Override
	public String toString() {
		return super.toString();
	}
}

// Definirati razred Zadatak1 koji sadrži metodu main() u kojoj će se
// inicijalizirati po jedan objekt svakog od razreda i prikazati sve ostvarene
// funkcionalnosti.
public class Zadatak1 {
	public static void main(String[] args) {
		/*
		 * STOLNA RACUNALA
		 */

		System.out.println("\nSTOLNA RACUNALA");
		System.out.println("---------------\n");

		// Konstruktori
		StolnoRacunalo stolno1 = new StolnoRacunalo("proizvodjac1", "stolno_model1", "os1");
		System.out.println("Stolno racunalo 1: " + stolno1);

		StolnoRacunalo stolno2 = new StolnoRacunalo("Dell", "MX-100", "Windows 10", new double[] { 50, 30, 60 });
		System.out.println("Stolno racunalo 2: " + stolno2);

		// Nevazeci argumenti
		try {
			StolnoRacunalo stolno = new StolnoRacunalo("Nevazeci Proizvodjac", "Nevazeci Model", "Nevazeci OS",
					new double[] { 40, 20 });
			System.out.println("Stolno racunalo 4: " + stolno);
		} catch (IllegalArgumentException e) {
			System.out.println("Pokusali ste konstruirati StolnoRacunalo sa nevazecim argumentima!");
		}

		System.out.println();

		// Getteri i setteri
		System.out.println("[PRIJE] Stolno racunalo 1: " + stolno1);
		stolno1.setDimenzije(new double[] { 60, 40, 70 });
		stolno1.setProizvodjac("proizvodjac2");
		stolno1.setModel("stolno_model2");
		stolno1.setOs("os2");
		System.out.println("[POSLIJE] Stolno racunalo 1: " + stolno1);

		// Nevazeci setter
		try {
			stolno1.setDimenzije(new double[] { 0.6, 0.4 });
		} catch (IllegalArgumentException e) {
			System.out.println("Pokusali ste postaviti nevazeci niz dimenzija!");
		}

		System.out.println();

		// dohvatiTipRacunala
		System.out.println("Tip racunala stolno1: " + stolno1.dohvatiTipRacunala());

		// izracunajPrenosivost
		System.out.println("Prenosivost stolno1: " + stolno1.izracunajPrenosivost());

		/*
		 * PRIJENOSNA RACUNALA
		 */

		System.out.println("\nPRIJENOSNA RACUNALA");
		System.out.println("------------------\n");

		// Konstruktori
		PrijenosnoRacunalno prijenosno1 = new PrijenosnoRacunalno("proizvodjac1", "prijenosno_model1", "os1", 100, 500);
		System.out.println("Prijenosno racunalo 1: " + prijenosno1);

		PrijenosnoRacunalno prijenosno2 = new PrijenosnoRacunalno("HP", "Envy", "Windows 10", 200, 700);
		System.out.println("Prijenosno racunalo 2: " + prijenosno2);

		// Nevazeci argumenti
		try {
			PrijenosnoRacunalno prijenosno = new PrijenosnoRacunalno("Nevazeci Proizvodjac", "Nevazeci Model",
					"Nevazeci OS", -100, -500);
			System.out.println("Prijenosno racunalo 4: " + prijenosno);
		} catch (IllegalArgumentException e) {
			System.out.println("Pokusali ste konstruirati PrijenosnoRacunalo sa nevazecim argumentima!");
		}

		System.out.println();

		// Getteri i setteri
		System.out.println("[PRIJE] Prijenosno racunalo 1: " + prijenosno1);
		prijenosno1.setKapacitetBaterije(200);
		prijenosno1.setTezina(700);
		prijenosno1.setProizvodjac("proizvodjac2");
		prijenosno1.setModel("prijenosno_model2");
		prijenosno1.setOs("os2");
		System.out.println("[POSLIJE] Prijenosno racunalo 1: " + prijenosno1);

		// Nevazeci setter
		try {
			prijenosno1.setKapacitetBaterije(-200);
		} catch (IllegalArgumentException e) {
			System.out.println("Pokusali ste postaviti nevazeci kapacitet baterije!");
		}

		System.out.println();

		// dohvatiTipRacunala
		System.out.println("Tip racunala prijenosno1: " + prijenosno1.dohvatiTipRacunala());

		// izracunajPrenosivost
		System.out.println("Prenosivost prijenosno1: " + prijenosno1.izracunajPrenosivost());

		/*
		 * NETBOOK
		 */

		System.out.println("\nNETBOOK");
		System.out.println("-------\n");

		// Konstruktori
		Netbook netbook1 = new Netbook("proizvodjac1", "netbook_model1", "os1", 100, 500);
		System.out.println("Netbook 1: " + netbook1);

		Netbook netbook2 = new Netbook("Lenovo", "Thinkpad", "Windows 10", 200, 700);
		System.out.println("Netbook 2: " + netbook2);

		// Nevazeci argumenti
		try {
			Netbook netbook = new Netbook("Nevazeci Proizvodjac", "Nevazeci Model", "Nevazeci OS", -100, -500);
			System.out.println("Netbook 4: " + netbook);
		} catch (IllegalArgumentException e) {
			System.out.println("Pokusali ste konstruirati Netbook sa nevazecim argumentima!");
		}

		System.out.println();

		// Getteri i setteri
		System.out.println("[PRIJE] Netbook 1: " + netbook1);
		netbook1.setKapacitetBaterije(200);
		netbook1.setTezina(700);
		netbook1.setProizvodjac("proizvodjac2");
		netbook1.setModel("netbook_model2");
		netbook1.setOs("os2");
		System.out.println("[POSLIJE] Netbook 1: " + netbook1);

		// Nevazeci setter
		try {
			netbook1.setKapacitetBaterije(-200);
		} catch (IllegalArgumentException e) {
			System.out.println("Pokusali ste postaviti nevazeci kapacitet baterije!");
		}

		System.out.println();

		// dohvatiTipRacunala
		System.out.println("Tip racunala netbook1: " + netbook1.dohvatiTipRacunala());

		// izracunajPrenosivost
		System.out.println("Prenosivost netbook1: " + netbook1.izracunajPrenosivost());

		/*
		 * POLIMORFIZAM
		 */

		System.out.println("\nPOLIMORFIZAM");
		System.out.println("------------\n");

		// Polimorfizam
		Racunalo[] racunala = new Racunalo[] { stolno1, stolno2, prijenosno1, prijenosno2, netbook1, netbook2 };

		for (Racunalo racunalo : racunala) {
			System.out.println(racunalo);
		}

		System.out.println();

		// Polimorfizam - dohvatiTipRacunala
		for (Racunalo racunalo : racunala) {
			System.out.println(racunalo.dohvatiTipRacunala());
		}
	}
}
