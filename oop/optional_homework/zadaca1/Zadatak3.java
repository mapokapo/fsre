package oop.optional_homework.zadaca1;

import java.time.LocalDate;
import java.time.YearMonth;
import java.time.format.DateTimeFormatter;
import java.time.format.FormatStyle;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
	Leo Petrović - 2174/RR

	Zadatak 2. - Dozvoliti korisniku unos datuma. Nakon sto korisnik unese datum, treba ga ispisati tako sto ce se mjesec ispisati rjecju te ispisati koliko mjesec ima dana.
*/

import java.util.Scanner;

public class Zadatak3 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		LocalDate datum = Utils.getDate(scanner, "Unesite datum u formatu dd.MM.yyyy: ");
		scanner.close();

		int mjesec = datum.getMonthValue(); // 1-12
		int godina = datum.getYear();

		int brojDana = YearMonth.of(godina, mjesec).lengthOfMonth();

		// int brojDana;
		// List<Integer> brojDanaPoMjesecima = Arrays.asList(31, 28, 31, 30, 31, 30, 31,
		// 31, 30, 31, 30, 31);
		// if (mjesec == 2 && godina % 4 == 0 && (godina % 100 != 0 || godina % 400 ==
		// 0)) {
		// brojDana = 29;
		// } else {
		// brojDana = brojDanaPoMjesecima.get(mjesec - 1);
		// }

		System.out.println("Datum: " + datum.format(DateTimeFormatter.ofLocalizedDate(FormatStyle.LONG)));
		System.out.println("Mjesec " + datum.format(DateTimeFormatter.ofPattern("LLLL")) + " ima " + brojDana + " dana.");
	}
}