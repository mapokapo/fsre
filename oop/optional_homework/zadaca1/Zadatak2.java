package oop.optional_homework.zadaca1;

import java.util.InputMismatchException;

/*
	Leo Petrović - 2174/RR

	Zadatak 2. - Ispisivati korisniku poruku da unese 2 broja (nebitan tip). Nakon sto korisnik unese 2 broja ispisati mu izbornik za racunske operacije (sve dok ne unese ispravan unos).
*/

import java.util.Scanner;

public class Zadatak2 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		Float a = null;
		Float b = null;

		do {
			a = getNumber(scanner, "Unesite prvi broj");
		} while (a == null);

		do {
			b = getNumber(scanner, "Unesite drugi broj");
		} while (b == null);

		while (true) {
			printMenu();
			
			String operation = scanner.next();
			if ("+-*/".indexOf(operation) == -1) {
				System.out.println("Unos nije ispravan.");
				continue;
			}
			
			Float result = handleOperation(a, b, operation);

			if (result == null) {
				System.out.println("Nije moguće izvršiti operaciju.");
				continue;
			}

			System.out.println("Rezultat: " + result);
			break;
		}
	}

	private static Float getNumber(Scanner scanner, String message) {
		System.out.println(message);
		try {
			return scanner.nextFloat();
		} catch (InputMismatchException e) {
			System.out.println("Unos nije ispravan.");
			scanner.next();
			return null;
		}
	}

	private static void printMenu() {
		System.out.println("Izaberite operaciju:");
		System.out.println("+ (Zbrajanje)");
		System.out.println("- (Oduzimanje)");
		System.out.println("* (Množenje)");
		System.out.println("/ (Dijeljenje)");
	}

	private static Float handleOperation(Float a, Float b, String operation) {
		switch (operation) {
			case "+":
				return a + b;
			case "-":
				return a - b;
			case "*":
				return a * b;
			case "/":
				if (b == 0) {
					return null;
				}
				return a / b;
			default:
				return null;
		}
	}
}