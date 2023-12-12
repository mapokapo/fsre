package oop.optional_homework.zadaca1;

/*
	Leo Petrović - 2174/RR

	Zadatak 1. - Dozvoliti korisniku unos datuma rodjenja. Nakon sto korisnik unese, treba ispisati je li korisnik punoljetan.
*/

import java.util.Scanner;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.time.LocalDate;

public class Zadatak1 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int day = Utils.getInt(scanner, "Unesite dan rodjenja: ");
		int month = Utils.getInt(scanner, "Unesite mjesec rodjenja: ");
		int year = Utils.getInt(scanner, "Unesite godinu rodjenja: ");

		scanner.close();

		try {
			SimpleDateFormat df = new SimpleDateFormat("dd.MM.yyyy");
			df.setLenient(false);
			df.parse(String.format("%d.%d.%d", day, month, year));
		} catch (ParseException e) {
			System.out.println("Unos nije ispravan.");
			return;
		}

		if (LocalDate.of(year, month, day).plusYears(18).isBefore(LocalDate.now())) {
			System.out.println("Korisnik je punoljetan.");
		} else {
			System.out.println("Korisnik nije punoljetan.");
		}
	}
}