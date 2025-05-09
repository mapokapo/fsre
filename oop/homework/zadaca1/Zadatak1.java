package oop.homework.zadaca1;

import java.util.Scanner;

/*
 * Leo Petrović - 2174/RR
 * 
 * Zadatak 1. - Napisati program u Javi skoji unosi string i provjerava radi li se o ispravnoj e-mail adresi. Ispravnom e-mail adresom smatra se onaj string koji sadrzi proizvoljno korisnicko ime sastavljeno od slova engleskog alfabeta, znamenki te znakova točke (.) i donje crte (_) nakon kojeg slijedi znak @ te iz toga domenu koja mora imati barem jednu točku u sredini teksta. Nakon provjere dojavljuje se poruka o ispravnosti unesene e-mail adrese.
*/

public class Zadatak1 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		System.out.print("Unesite e-mail adresu: ");
		String unos = scanner.nextLine();

		scanner.close();

		if (unos.indexOf("@") == -1) {
			System.out.println("Nevazeca e-mail adresa! Nedostaje vam znak '@'.");
			return;
		}

		String[] dijeloviAdrese = unos.split("@");
		if (dijeloviAdrese.length != 2) {
			System.out.println("Nevazeca e-mail adresa! Znak '@' ne dijeli adresu na dva dijela.");
			return;
		}

		String prviDioAdrese = dijeloviAdrese[0];
		String drugiDioAdrese = dijeloviAdrese[1];
		if (prviDioAdrese == null || prviDioAdrese.isEmpty() || drugiDioAdrese == null || drugiDioAdrese.isEmpty()) {
			System.out.println("Nevazeca e-mail adresa! Dijelovi adrese nisu vazeci.");
			return;
		}

		for (int i = 0; i < prviDioAdrese.length(); i++) {
			char c = prviDioAdrese.charAt(i);

			if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || (c == '.') || (c == '_'))) {
				System.out.println("Nevazeca e-mail adresa! Vase korisnicko ne smije imati posebne znakove!");
				return;
			}
		}

		if (drugiDioAdrese.indexOf(".") == -1) {
			System.out.println("Nevazeca e-mail adresa! Domena mora imati tocku.");
			return;
		}

		String[] dijeloviDomene = drugiDioAdrese.split("\\.");
		if (dijeloviDomene.length != 2) {
			System.out.println("Nevazeca e-mail adresa! Znak '.' ne dijeli domenu na dva dijela.");
			return;
		}

		String prviDioDomene = dijeloviDomene[0];
		String drugiDioDomene = dijeloviDomene[1];
		if (prviDioDomene == null || prviDioDomene.isEmpty() || drugiDioDomene == null || drugiDioDomene.isEmpty()) {
			System.out.println("Nevazeca e-mail adresa! Dijelovi domene nisu vazeci.");
			return;
		}

		System.out.println("Vasa email adresa je vazeca.");
	}
}
