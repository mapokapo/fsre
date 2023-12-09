package oop.optional_homework.zadaca1;
/*
	Leo Petrović - 2174/RR

	Zadatak 2. - Dozvoliti korisniku unos datuma. Nakon sto korisnik unese datum, treba ga ispisati tako sto ce se mjesec ispisati rjecju te ispisati koliko mjesec ima dana.
*/

import java.util.Scanner;

public class Zadatak3 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("Unesite datum u formatu dd.mm.yyyy");
		String datumString = scanner.next();
		scanner.close();

		String[] datum = datumString.split("\\.");
		if (datum.length != 3) {
			System.out.println("Unos nije ispravan.");
			return;
		}

		int dan = 0;
		int mjesec = 0;
		int godina = 0;

		try {
			dan = Integer.parseInt(datum[0]);
			mjesec = Integer.parseInt(datum[1]);
			godina = Integer.parseInt(datum[2]);
		} catch (NumberFormatException e) {
			System.out.println("Unos nije ispravan.");
			return;
		}

		if (dan < 1 || dan > 31 || mjesec < 1 || mjesec > 12 || godina < 1) {
			System.out.println("Unos nije ispravan.");
			return;
		}

		int brojDana = 0;
		if (mjesec == 2) {
			brojDana = 28;
		} else if (mjesec % 2 == 0) {
			brojDana = 30;
		} else {
			brojDana = 31;
		}

		System.out.println("Datum: " + dan + ". " + getMonthName(mjesec) + " " + godina + ".");
		System.out.println("Mjesec " + getMonthName(mjesec) + " ima " + brojDana + " dana.");
	}

	private static String getMonthName(int mjesec) {
		final String[] mjeseci = {"Siječanj", "Veljača", "Ožujak", "Travanj", "Svibanj", "Lipanj",
			"Srpanj", "Kolovoz", "Rujan", "Listopad", "Studeni", "Prosinac"};

		return mjeseci[mjesec - 1];
	}
}