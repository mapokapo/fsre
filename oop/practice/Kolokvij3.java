package oop.practice;

import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

class Zivotinja {
	public String obrana() {
		return "bjezim";
	}
}

class Macka extends Zivotinja {
	public String ime;

	public Macka(String ime) {
		this.ime = ime;
	}

	public String obrana() {
		return "grebem";
	}

	public String toString() {
		return this.ime;
	}
}

class Pas extends Zivotinja {
	public String ime;

	public Pas(String ime) {
		this.ime = ime;
	}

	public String obrana() {
		return "grizem";
	}

	public String toString() {
		return this.ime;
	}
}

class Mis extends Zivotinja {
	public String ime;

	public Mis(String ime) {
		this.ime = ime;
	}

	public String toString() {
		return this.ime;
	}
}

class App {
	Zivotinja[] zivotinje = new Zivotinja[10];

	public App() {
		Random random = new Random();
		String[] obrana1 = new String[10];

		int brojMacaka = 0, brojPasa = 0, brojMiseva = 0;
		for (int i = 0; i < zivotinje.length; i++) {
			int n = random.nextInt(0, 3);
			switch (n) {
				case 0:
					zivotinje[i] = new Macka("Macka" + (brojMacaka + 1));
					brojMacaka++;
					break;
				case 1:
					zivotinje[i] = new Pas("Pas" + (brojPasa + 1));
					brojPasa++;
					break;
				case 2:
					zivotinje[i] = new Mis("Mis" + (brojMiseva + 1));
					brojMiseva++;
					break;
				default:
					break;
			}
		}

		for (int i = 0; i < zivotinje.length; i++) {
			obrana1[i] = zivotinje[i].obrana();
		}

		System.out.println(Arrays.toString(zivotinje));
		System.out.println(Arrays.toString(obrana1));
	}
}

public class Kolokvij3 {
	public static void Zadatak1(String[] args) {
		for (int i = 0; i < args.length; i++) {
			System.out.println(args[i]);
		}
	}

	public static void Zadatak2() {
		Random rd = new Random();
		int a = rd.nextInt(100, 150);
		System.out.println("a = " + a);
	}

	public static void Zadatak3() {
		int[] niz1 = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		int[] niz2 = new int[] { 0, 2, 4, 6, 8, 10, 12, 14, 16, 18 };

		int[] niz3 = new int[10];

		for (int i = 0; i < 10; i++) {
			niz3[i] = (int) (Math.pow(niz1[i], 2) + Math.pow(niz2[i], 2));
		}

		System.out.println("Niz:");
		for (int i : niz3) {
			System.out.print(i + ", ");
		}
		System.out.println();
	}

	public static void Zadatak4() {
		Scanner scanner = new Scanner(System.in);

		System.out.print("Unesite broj: ");
		int broj = scanner.nextInt();

		String string = "Broj " + broj;

		System.out.println(string);
	}

	public static void Zadatak5() {
		Macka macka = new Macka("Micka");
		Pas pas = new Pas("Reks");
		Mis mis = new Mis("Misko");

		System.out.println(macka.obrana());
		System.out.println(pas.obrana());
		System.out.println(mis.obrana());

		System.out.println(macka);
		System.out.println(pas);
		System.out.println(mis);
	}

	public static void Zadatak6() {
		new App();
	}

	public static void main(String[] args) {
		Zadatak1(args);
		Zadatak2();
		Zadatak3();
		Zadatak4();
		Zadatak5();
		Zadatak6();
	}
}
