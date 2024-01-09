package oop.homework.zadaca2;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

/*
 * Leo Petrović - 2174/RR
 * 
 * Zadatak 3. - Napisati program u Javi koji unosi ime, prezime, studij, godinu studija te broj indeksa za 10 studenata (kreirati razred Student). Spremati ih u niz koristeći razred ArrayList. Program potom treba ispisati podatke o studentima grupirane po studijima i sortirane po godini studija uzlazno.
*/

class Student {
	public String imePrezime;
	public String studij;
	public int godinaStudija;
	public int brojIndeksa;

	public Student() {
	}

	public Student(String imePrezime, String studij, int godinaStudija, int brojIndeksa) {
		this.imePrezime = imePrezime;
		this.studij = studij;
		this.godinaStudija = godinaStudija;
		this.brojIndeksa = brojIndeksa;
	}

	@Override
	public String toString() {
		return imePrezime + ", " + brojIndeksa + " (" + studij + ", " + godinaStudija
				+ " godina)";
	}

}

public class Zadatak3 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		ArrayList<Student> studenti = new ArrayList<>();

		int i = 0;
		while (i < 10) {
			Student student = new Student();

			System.out.print("Unesite ime, prezime, studij, godinu studija, i broj indeksa studenta: ");

			student.imePrezime = scanner.next() + " " + scanner.next();
			student.studij = scanner.next();
			try {
				student.godinaStudija = Integer.parseInt(scanner.next());
				student.brojIndeksa = Integer.parseInt(scanner.next());
			} catch (NumberFormatException e) {
				System.out.println("Broj nije validan.");
				continue;
			}

			studenti.add(student);

			i++;
		}

		scanner.close();

		ArrayList<ArrayList<Student>> studentiPoStudijima = new ArrayList<>();

		for (i = 0; i < studenti.size(); i++) {
			Integer indeksPronadjenog = null;
			for (int j = 0; j < studentiPoStudijima.size(); j++) {
				if (studentiPoStudijima.get(j).get(0).studij.equals(studenti.get(i).studij)) {
					indeksPronadjenog = j;
					break;
				}
			}

			if (indeksPronadjenog != null) {
				studentiPoStudijima.get(indeksPronadjenog).add(studenti.get(i));
			} else {
				ArrayList<Student> studentiZaStudij = new ArrayList<>();
				studentiZaStudij.add(studenti.get(i));
				studentiPoStudijima.add(studentiZaStudij);
			}
		}

		for (i = 0; i < studentiPoStudijima.size(); i++) {
			Collections.sort(studentiPoStudijima.get(i), Comparator.comparing(o -> o.godinaStudija));
		}

		for (i = 0; i < studentiPoStudijima.size(); i++) {
			System.out.println("Studenti za studij " + studentiPoStudijima.get(i).get(0).studij + ":");
			for (int j = 0; j < studentiPoStudijima.get(i).size(); j++) {
				System.out.println(" - " + studentiPoStudijima.get(i).get(j));
			}
		}
	}
}
