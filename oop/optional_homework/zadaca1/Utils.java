package oop.optional_homework.zadaca1;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.time.LocalDate;
import java.time.ZoneId;
import java.util.Date;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Utils {
	private static final String NEISPRAVAN_UNOS = "Unos nije ispravan.";

	private Utils() {
	}

	public static Float getFloat(Scanner scanner, String message) {
		while (true) {
			System.out.print(message);
			try {
				return scanner.nextFloat();
			} catch (InputMismatchException e) {
				System.out.println(NEISPRAVAN_UNOS);
				scanner.next();
			}
		}
	}

	public static Integer getInt(Scanner scanner, String message) {
		while (true) {
			System.out.print(message);
			try {
				return scanner.nextInt();
			} catch (InputMismatchException e) {
				System.out.println(NEISPRAVAN_UNOS);
				scanner.next();
			}
		}
	}

	public static LocalDate getDate(Scanner scanner, String message) {
		while (true) {
			System.out.print(message);
			try {
				SimpleDateFormat format = new SimpleDateFormat("dd.MM.yyyy");
				format.setLenient(false);
				return convertDateToLocalDate(format.parse(scanner.next()));
			} catch (ParseException e) {
				System.out.println(NEISPRAVAN_UNOS);
			}
		}
	}

	public static LocalDate convertDateToLocalDate(Date date) {
		return date.toInstant().atZone(ZoneId.systemDefault()).toLocalDate();
	}
}