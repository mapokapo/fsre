package oop.practice;

import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;

abstract class Osoba {
	public String ime;
	public String datum;
	public String adresa;

	public Osoba(String ime, String datum, String adresa) {
		this.ime = ime;
		this.datum = datum;
		this.adresa = adresa;
	}

	public abstract void oznaka();

	public String toString() {
		return String.format("{%n\time = %s,%n\tdatum = %s,%n\tadresa = %s%n}", this.ime, this.datum, this.adresa);
	}
}

class Ucenik extends Osoba {
	private String skola;
	private int razred;
	private double prosjek;

	public static int broj_ucenika = 0;
	public static double zbroj_prosjeka = 0;

	public Ucenik(String ime, String datum, String adresa, String skola, int razred, double prosjek) {
		super(ime, datum, adresa);
		this.skola = skola;
		this.razred = razred;
		this.prosjek = prosjek;

		Ucenik.broj_ucenika++;
		Ucenik.zbroj_prosjeka += prosjek;
	}

	public void oznaka() {
		System.out.println("Oznaka ucenika");
	}

	public static double prosjek() {
		if (Ucenik.broj_ucenika == 0)
			return 0;
		return Ucenik.zbroj_prosjeka / Ucenik.broj_ucenika;
	}

	public String toString() {
		return String.format(
				"{%n\time = %s,%n\tdatum = %s,%n\tadresa = %s,%n\tskola = %s,%n\trazred = %d,%n\tprosjek = %.2f%n}", this.ime,
				this.datum, this.adresa, this.skola, this.razred, this.prosjek);
	}
}

class Student extends Osoba {
	public String fakultet;
	public int godina_upisa;
	public int godina_studija;

	public static int broj_studenata = 0;
	public static int zbroj_prosjeka = 0;

	public Student(String ime, String datum, String adresa, String fakultet, int godina_upisa, int godina_studija) {
		super(ime, datum, adresa);
		this.fakultet = fakultet;
		this.godina_upisa = godina_upisa;
		this.godina_studija = godina_studija;

		Student.broj_studenata++;
		Student.zbroj_prosjeka++;
	}

	public void oznaka() {
		System.out.println("Oznaka studenta");
	}

	public static double prosjek() {
		if (Student.broj_studenata == 0)
			return 0;
		return Student.zbroj_prosjeka / Student.broj_studenata;
	}

	public String toString() {
		return String.format(
				"{%n\time = %s,%n\tdatum = %s,%n\tadresa = %s,%n\tfakultet = %s,%n\tgodina_upisa = %d,%n\tgodina_studija = %d%n}",
				this.ime, this.datum, this.adresa, this.fakultet, this.godina_upisa, this.godina_studija);
	}
}

class Test {
	public List<Osoba> osobe = new ArrayList<>();

	public void upisiOsobe() {
		Scanner scanner = new Scanner(System.in);

		int N = 5;
		for (int i = 0; i < N; i++) {
			String tip;

			System.out.print("Radi li se o [U]ceniku ili o [S]tudentu? ");
			tip = scanner.nextLine();

			System.out.print("Unesite ime osobe: ");
			String ime = scanner.nextLine();
			System.out.print("Unesite datum rodjenja osobe: ");
			String datum = scanner.nextLine();
			System.out.print("Unesite adresu osobe: ");
			String adresa = scanner.nextLine();

			if (tip.equals("U")) {
				System.out.print("Unesite ime skole ucenika: ");
				String skola = scanner.nextLine();
				System.out.print("Unesite razred ucenika: ");
				int razred = scanner.nextInt();
				scanner.nextLine();
				System.out.print("Unesite prosjek ucenika: ");
				double prosjek = scanner.nextDouble();
				scanner.nextLine();

				Ucenik ucenik = new Ucenik(ime, datum, adresa, skola, razred, prosjek);
				osobe.add((Osoba) ucenik);
			} else if (tip.equals("S")) {
				System.out.print("Unesite fakultet studenta: ");
				String fakultet = scanner.nextLine();
				System.out.print("Unesite godinu upisa studenta: ");
				int godina_upisa = scanner.nextInt();
				scanner.nextLine();
				System.out.print("Unesite godinu studija studenta: ");
				int godina_studija = scanner.nextInt();
				scanner.nextLine();

				Student student = new Student(ime, datum, adresa, fakultet, godina_upisa, godina_studija);
				osobe.add((Osoba) student);
			} else {
				System.out.println("Unijeli ste nevalidan tip osobe!");
				continue;
			}
		}

		scanner.close();
	}
}

class Kolokvij1 {
	public static void main(String[] args) {
		Test test = new Test();

		test.upisiOsobe();

		for (Osoba osoba : test.osobe) {
			System.out.println(osoba);
		}

		System.out.print("Srednji prosjek za ucenike je: ");
		System.out.println(Ucenik.prosjek());
		System.out.print("Srednji prosjek za studente je: ");
		System.out.println(Student.prosjek());
	}
}