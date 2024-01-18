package oop.practice;

import java.util.InputMismatchException;
import java.util.Scanner;

abstract class Razlika {
	public Funkcija funkcija;

	public Razlika(Funkcija funkcija) {
		this.funkcija = funkcija;
	}

	public abstract double razlika();

	public Funkcija getF() {
		return this.funkcija;
	}

	public String toString() {
		return funkcija.toString();
	}
}

class Funkcija {
	public String ime;
	public double a, b;

	public Funkcija(String ime, double a, double b) {
		this.ime = ime;
		this.a = a;
		this.b = b;
	}

	public String getIme() {
		return ime;
	}

	public double getA() {
		return a;
	}

	public double getB() {
		return b;
	}

	public double vrijednost(double x) {
		switch (ime) {
			case "sin":
				return Math.sin(x);
			case "cos":
				return Math.cos(x);
			case "exp":
				return Math.exp(x);
			default:
				return 0;
		}
	}

	public String toString() {
		return String.format("%s(x) definirane na [%.2f, %.2f]", this.ime, this.a, this.b);
	}
}

class VrijednostRazlike extends Razlika {
	public VrijednostRazlike(Funkcija funkcija) {
		super(funkcija);
	}

	public double razlika() {
		Funkcija f = this.getF();

		return f.vrijednost(f.getB()) - f.vrijednost(f.getA());
	}
}

class Test2 {
	public void unos() {
		Scanner scanner = new Scanner(System.in);

		String ime;
		double a, b;
		while (true) {
			System.out.print("Unesite ime funkcije (sin, cos, exp): ");
			ime = scanner.nextLine();

			if (ime.equals("sin") || ime.equals("cos") || ime.equals("exp")) {
				break;
			} else {
				System.out.println("Nevazece ime funkcije!");
			}
		}

		while (true) {
			System.out.print("Unesite a: ");
			try {
				a = scanner.nextDouble();
				scanner.nextLine();
				break;
			} catch (InputMismatchException e) {
				System.out.println("To nije vazeci broj!");
				scanner.nextLine();
			}
		}

		while (true) {
			System.out.print("Unesite b: ");
			try {
				b = scanner.nextDouble();
				scanner.nextLine();
				break;
			} catch (InputMismatchException e) {
				System.out.println("To nije vazeci broj!");
				scanner.nextLine();
			}
		}

		Funkcija funkcija = new Funkcija(ime, a, b);

		VrijednostRazlike vrijednostRazlike = new VrijednostRazlike(funkcija);

		System.out.println("Razlika je: " + vrijednostRazlike.razlika());
	}
}

public class Kolokvij2 {
	public static void main(String[] args) {
		Test2 test = new Test2();

		test.unos();
	}
}
