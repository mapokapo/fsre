package oop.optional_homework.zadaca3;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Zadatak1 {
	// napisat program koji sadrzava klasu student sa sljedecim poljima: ime,
	// prezime, studij, godina studija. Dozvoliti korisniku unos imena i prezimena,
	// i provjeriti jesu li unosi valjani (prvo pocetno slovo veliko). Korisnik
	// unosi podatke sve dok ne unese dva puta za redom isto ime i prezime.
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		List<Student> studenti = new ArrayList<>();

		do {
			System.out.print("Unesite ime studenta: ");
			String ime = scanner.nextLine();
			if (!validnoIme(ime)) {
				System.out.println("Ime nije validno!");
				continue;
			}

			System.out.print("Unesite prezime studenta: ");
			String prezime = scanner.nextLine();
			if (!validnoIme(prezime)) {
				System.out.println("Prezime nije validno!");
				continue;
			}

			System.out.print("Unesite studij: ");
			String studij = scanner.nextLine();

			System.out.print("Unesite godinu studija: ");
			int godinaStudija = scanner.nextInt();
			scanner.nextLine();
			if (godinaStudija < 1 || godinaStudija > 5) {
				System.out.println("Godina studija nije validna!");
				continue;
			}

			studenti.add(new Student(ime, prezime, studij, godinaStudija));
		} while (!dvaputZaredomIstoImePrezime(studenti));

		scanner.close();

		System.out.println("\nUnijeli ste 2 puta za redom studenta sa istim imenom i prezimenom!\n");
		System.out.println("Informacije o zadnja 2 studenta:");
		System.out.println(studenti.get(studenti.size() - 1).toString());
		System.out.println(studenti.get(studenti.size() - 2).toString());
	}

	private static boolean dvaputZaredomIstoImePrezime(List<Student> studenti) {
		return studenti.size() >= 2 && studenti.get(studenti.size() - 1).ime.equals(studenti.get(studenti.size() - 2).ime)
				&& studenti.get(studenti.size() - 1).prezime.equals(studenti.get(studenti.size() - 2).prezime);
	}

	private static boolean validnoIme(String ime) {
		for (int i = 0; i < ime.length(); i++) {
			if (!Character.isAlphabetic(ime.charAt(i))) {
				return false;
			}
		}

		return ime.length() > 0 && ime.charAt(0) == Character.toUpperCase(ime.charAt(0));
	}
}