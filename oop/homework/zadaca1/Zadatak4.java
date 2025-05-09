package oop.homework.zadaca1;

import java.util.Scanner;

/*
 * Leo Petrović - 2174/RR
 * 
 * Zadatak 4. - Napisati program u Javi koji unosi broj u dekadskom obliku te izracunava i ispisuje njegovu heksadekadsku vrijednost (npr. 2548 -> 9F4).
*/

public class Zadatak4 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		System.out.print("Unesite broj u dekadskom obliku: ");
		int broj = scanner.nextInt();

		scanner.close();

		StringBuilder hexBroj = new StringBuilder();
		do {
			hexBroj.append(decToHex(broj % 16));
			broj = broj / 16;
		} while (broj > 0);

		System.out.println("Vas broj u heksadekadskom zapisu je: " + hexBroj.reverse().toString());
	}

	private static String decToHex(int broj) {
		if (broj >= 0 && broj <= 9) {
			return String.valueOf(broj);
		}

		switch (broj) {
			case 10:
				return "A";
			case 11:
				return "B";
			case 12:
				return "C";
			case 13:
				return "D";
			case 14:
				return "E";
			case 15:
				return "F";
			default:
				return null;
		}
	}
}
