package oop.optional_homework.zadaca2;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.time.LocalDate;
import java.time.ZoneId;
import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Scanner;

/*
	Leo Petrović - 2174/RR

	Zadatak 1. - Napisati program koji definira klasu Student koja ima sljedece podatkovne clanove: ime i prezime, datum rodjenja, studij, broj indeksa, i spol. Klasa definira sljdece metode: metoda za ispis pojedinacnih podatkovnih clanova, konstruktori (vrijednosti za sve clanove, samo ime i prezime). Instancirati 3 studenta i ispisati studente od najstarijeg do najmladjeg. Uz to ispisati koliko je muskih a koliko zenskih studenata. Svi podatci se unose od korisnika.
*/

public class Zadatak1 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		List<Student> studenti = new ArrayList<>();

		for (int i = 0; i < 3; i++) {
			studenti.add(upitajZaStudenta(scanner));
		}

		studenti.sort((a, b) -> a.getDatumRodjenja().isBefore(b.getDatumRodjenja()) ? -1 : 1);

		System.out.println("Studenti:");
		for (Student student : studenti) {
			System.out.println(student.toString());
		}

		int brojMuskih = 0;
		for (Student student : studenti) {
			if (student.getSpol() == 'M') {
				brojMuskih++;
			}
		}
		System.out.println("Broj muskih studenata je " + brojMuskih + ", a zenskih " + (studenti.size() - brojMuskih));
	}

	private static Student upitajZaStudenta(Scanner scanner) {
		String ime;
		String prezime;
		String studij;
		int brojIndeksa;
		char spol;
		LocalDate datumRodjenja;

		System.out.println("PODATCI ZA STUDENTA:");

		System.out.print("Ime: ");
		ime = scanner.next();

		System.out.print("Prezime: ");
		prezime = scanner.next();

		System.out.print("Studij: ");
		studij = scanner.next();

		while (true) {
			System.out.print("Broj indeksa: ");
			try {
				brojIndeksa = scanner.nextInt();
				break;
			} catch (InputMismatchException e) {
				System.out.println("Nevazeci broj!");
			}
		}

		System.out.print("Spol: ");
		spol = scanner.next().charAt(0); // prvo slovo unosa

		while (true) {
			System.out.print("Datum rodjenja: ");
			try {
				datumRodjenja = new SimpleDateFormat("dd.MM.yyyy").parse(scanner.next()).toInstant()
						.atZone(ZoneId.systemDefault())
						.toLocalDate();
				break;
			} catch (ParseException e) {
				System.out.println("Nevazeci datum!");
			}
		}
		System.out.println();

		return new Student(ime, prezime, studij, brojIndeksa, spol, datumRodjenja);
	}
}
