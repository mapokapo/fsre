package oop.homework.zadaca2;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

/*
 * Leo Petrović - 2174/RR
 * 
 * Zadatak 2. - Napisati program u Javi koji unosi ime i prezime i datum rođenja za 5 osoba (kreirati razred Osoba) spremajući ih u niz koristeći razred List. Nakon unosa, ispisati podatke sortirane abecednim redom.
*/

class Osoba {
	public String imePrezime;
	public LocalDate datumRodjenja;

	public Osoba() {
	}

	public Osoba(String imePrezime, LocalDate datumRodjenja) {
		this.imePrezime = imePrezime;
		this.datumRodjenja = datumRodjenja;
	}
}

public class Zadatak2 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.println(scanner.delimiter());

		List<Osoba> osobe = new ArrayList<>();

		int i = 0;
		while (i < 5) {
			Osoba osoba = new Osoba();
			System.out.print("Unesite ime, prezime, i datum rodjenja osobe odvojene razmakom: ");
			osoba.imePrezime = scanner.next() + " " + scanner.next();
			try {
				DateTimeFormatter formatter = DateTimeFormatter.ofPattern("d.M.yyyy");
				osoba.datumRodjenja = LocalDate.parse(scanner.next(), formatter);
			} catch (DateTimeParseException e) {
				System.out.println("Uneseni datum nije ispravan.");
				continue;
			}

			osobe.add(osoba);

			i++;
		}

		scanner.close();

		Collections.sort(osobe, Comparator.comparing(o -> o.imePrezime));

		for (i = 0; i < 5; i++) {
			System.out.println("Osoba " + (i + 1) + ": " + osobe.get(i).imePrezime + ", datum rodjenja: "
					+ osobe.get(i).datumRodjenja.format(DateTimeFormatter.ofPattern("d.M.yyyy")));
		}
	}
}
