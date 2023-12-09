package oop.optional_homework.zadaca1;

/*
	Leo Petrović - 2174/RR

	Zadatak 1. - Dozvoliti korisniku unos datuma rodjenja. Nakon sto korisnik unese, treba ispisati je li korisnik punoljetan.
*/

import java.util.Scanner;
import java.time.LocalDate;

public class Zadatak1 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		System.out.print("Unesite dan rodjenja: ");
		int day = scanner.nextInt();

		System.out.print("Unesite mjesec rodjenja: ");
		int month = scanner.nextInt();

		System.out.print("Unesite godinu rodjenja: ");
		int year = scanner.nextInt();

		scanner.close();

		if (LocalDate.of(year, month, day).plusYears(18).isBefore(LocalDate.now())) {
			System.out.println("Korisnik je punoljetan.");
		} else {
			System.out.println("Korisnik nije punoljetan.");
		}
	}
}