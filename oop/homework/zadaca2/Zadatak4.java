package oop.homework.zadaca2;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

/*
 * Leo Petrović - 2174/RR
 * 
 * Zadatak 4. - Napisati program u Javi koji unosi ime i prezime te ocjenu s ispita za 15 studenata. Potom kreirati niz polozili u koji se spremaju studenti koji su položili ispit. Program ispisuje podatke o studentima koji su položili ispit sortirane po abecedi. Za navedene nizove koristiti razred ArrayList.
*/

class Student2 {
	private String imePrezime;
	private int ocjena;

	public Student2() {
	}

	public Student2(String imePrezime, int ocjena) {
		this.imePrezime = imePrezime;
		this.ocjena = ocjena;
	}

	public String getImePrezime() {
		return imePrezime;
	}

	public int getOcjena() {
		return ocjena;
	}

	public void setImePrezime(String imePrezime) {
		this.imePrezime = imePrezime;
	}

	public void setOcjena(int ocjena) {
		this.ocjena = ocjena;
	}

	@Override
	public String toString() {
		return this.imePrezime + " (" + this.ocjena + ")";
	}
}

public class Zadatak4 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		List<Student2> studenti = new ArrayList<>();

		int i = 0;
		while (i < 15) {
			Student2 student = new Student2();

			System.out.print("Unesite ime, prezime, i ocjenu sa ispita za studenta: ");

			student.setImePrezime(scanner.next() + " " + scanner.next());
			try {
				student.setOcjena(Integer.parseInt(scanner.next()));
			} catch (NumberFormatException e) {
				System.out.println("Broj nije validan.");
				continue;
			}

			studenti.add(student);

			i++;
		}

		scanner.close();

		List<Student2> polozili = new ArrayList<>();

		for (Student2 student : studenti) {
			if (student.getOcjena() > 1) {
				polozili.add(student);
			}
		}

		Collections.sort(polozili, Comparator.comparing(s -> s.getImePrezime()));

		System.out.println("Studenti koji su polozili ispit:");
		for (i = 0; i < polozili.size(); i++) {
			System.out.println(" - " + polozili.get(i));
		}
	}
}
