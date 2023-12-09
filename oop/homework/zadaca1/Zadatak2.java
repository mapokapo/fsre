package oop.homework.zadaca1;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;
import java.time.temporal.ChronoUnit;
import java.util.Scanner;

/*
 * Leo Petrović - 2174/RR
 * 
 * Zadatak 2. - Napisati program u Javi koji unosi ime i prezime osobe i datum njenog rodenja te ispisuje pozdravnu poruku za tu osobu i informaciju koliko je dana preostalo do njenog sljedeceg rođendana.
*/

public class Zadatak2 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		System.out.print("Unesite ime i prezime: ");
		String imeIPrezime = scanner.nextLine();

		System.out.print("Unesite datum rodenja u formatu (d.M.yyyy): ");
		String datumString = scanner.nextLine();

		scanner.close();

		LocalDate datum;
		try {
			DateTimeFormatter formatter = DateTimeFormatter.ofPattern("d.M.yyyy");
			datum = LocalDate.parse(datumString, formatter);
		} catch (DateTimeParseException e) {
			System.out.println("Uneseni datum nije ispravan.");
			return;
		}

		// Npr. ako je rodendan 22.07.2003., onda ga ovdje postavljamo na 22.07.2023. (trenutna godina)
		datum = datum.withYear(LocalDate.now().getYear());
		
		// Ako je rodendan vec prosao u trenutnoj godini, onda gledamo kada ce biti sljedece godine
		if (datum.isBefore(LocalDate.now())) {
			datum = datum.plusYears(1);
		}

		// Racunamo razliku u danima
		long brojDanaDoSljedecegRodendana = ChronoUnit.DAYS.between(LocalDate.now(), datum);

		System.out.println("Pozdrav " + imeIPrezime + "!");
		System.out.println("Vas sljedeci rodendan je za " + brojDanaDoSljedecegRodendana + "dana.");
	}
}
