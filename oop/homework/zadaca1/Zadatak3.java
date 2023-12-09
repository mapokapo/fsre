package oop.homework.zadaca1;

import java.util.Scanner;

/*
 * Leo Petrović - 2174/RR
 * 
 * Zadatak 3. - Napisati program u Javi koji unosi recenicu i pronalazi najveci podstring unesene recenice koji je palindrom, zanemarujuci sve znakove koji nisu slova te zanemarujuci razliku izmedu velikih i malih slova.
*/

public class Zadatak3 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		System.out.print("Unesite recenicu: ");
		String recenica = scanner.nextLine();

		scanner.close();

		// Recenica bez razmaka i interpunkcijskih znakova - samo slova
		String normaliziranaRecenica = recenica.strip().toLowerCase().replaceAll("[^a-z]", "");

		String najveciPalindrom = null;
		int duzinaNajvecegPalindroma = 0;

		for (int i = 0; i < normaliziranaRecenica.length(); i++) {
			for (int j = i + 1; j < normaliziranaRecenica.length(); j++) {
				String substring = normaliziranaRecenica.substring(i, j);
				if (substring.equals(new StringBuilder(substring).reverse().toString())
						&& (substring.length() > duzinaNajvecegPalindroma)) {
					najveciPalindrom = substring;
					duzinaNajvecegPalindroma = substring.length();
				}
			}
		}

		if (najveciPalindrom == null) {
			System.out.println("Nije pronaden nijedan palindrom u recenici.");
		} else {
			System.out.println(
					"Najveci palindrom u recenici je '" + najveciPalindrom + "', i ima " + duzinaNajvecegPalindroma + " slova.");
		}
	}
}
