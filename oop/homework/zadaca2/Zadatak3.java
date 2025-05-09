package oop.homework.zadaca2;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

/*
 * Leo Petrović - 2174/RR
 * 
 * Zadatak 3. - Napisati program u Javi koji unosi ime, prezime, studij, godinu studija te broj indeksa za 10 studenata (kreirati razred Student). Spremati ih u niz koristeći razred ArrayList. Program potom treba ispisati podatke o studentima grupirane po studijima i sortirane po godini studija uzlazno.
*/

class Student {
	private String imePrezime;
	private String studij;
	private int godinaStudija;
	private int brojIndeksa;

	public Student() {
	}

	public Student(String imePrezime, String studij, int godinaStudija, int brojIndeksa) {
		this.imePrezime = imePrezime;
		this.studij = studij;
		this.godinaStudija = godinaStudija;
		this.brojIndeksa = brojIndeksa;
	}

	public String getImePrezime() {
		return imePrezime;
	}

	public void setImePrezime(String imePrezime) {
		this.imePrezime = imePrezime;
	}

	public String getStudij() {
		return studij;
	}

	public void setStudij(String studij) {
		this.studij = studij;
	}

	public int getGodinaStudija() {
		return godinaStudija;
	}

	public void setGodinaStudija(int godinaStudija) {
		this.godinaStudija = godinaStudija;
	}

	public int getBrojIndeksa() {
		return brojIndeksa;
	}

	public void setBrojIndeksa(int brojIndeksa) {
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

		List<Student> studenti = new ArrayList<>();

		int i = 0;
		/*
		 * while (i < 10) {
		 * Student student = new Student();
		 * 
		 * System.out.
		 * print("Unesite ime, prezime, studij, godinu studija, i broj indeksa studenta: "
		 * );
		 * 
		 * student.setImePrezime(scanner.next() + " " + scanner.next());
		 * student.setStudij(scanner.next());
		 * try {
		 * student.setGodinaStudija(Integer.parseInt(scanner.next()));
		 * student.setBrojIndeksa(Integer.parseInt(scanner.next()));
		 * } catch (NumberFormatException e) {
		 * System.out.println("Broj nije validan.");
		 * continue;
		 * }
		 * 
		 * studenti.add(student);
		 * 
		 * i++;
		 * }
		 */

		studenti.add(new Student("Ivo Ivic", "Racunarstvo", 2, 2173));
		studenti.add(new Student("Mate Matic", "Racunarstvo", 3, 2913));
		studenti.add(new Student("Pero Peric", "Elektrotehnika", 3, 2001));
		studenti.add(new Student("Ante Antic", "Strojarstvo", 2, 2030));
		studenti.add(new Student("Jure Juric", "Strojarstvo", 3, 2000));
		studenti.add(new Student("Marko Markic", "Elektrotehnika", 1, 2111));
		studenti.add(new Student("Ime Prezime", "Elektrotehnika", 1, 2220));
		studenti.add(new Student("Petar Peric", "Racunarstvo", 1, 2131));
		studenti.add(new Student("Matej Matic", "Strojarstvo", 2, 2005));
		studenti.add(new Student("John Doe", "Racunarstvo", 2, 1901));

		scanner.close();

		List<List<Student>> studentiPoStudijima = new ArrayList<>();

		for (i = 0; i < studenti.size(); i++) {
			Integer indeksPronadjenog = null;
			for (int j = 0; j < studentiPoStudijima.size(); j++) {
				if (studentiPoStudijima.get(j).get(0).getStudij().equals(studenti.get(i).getStudij())) {
					indeksPronadjenog = j;
					break;
				}
			}

			if (indeksPronadjenog != null) {
				studentiPoStudijima.get(indeksPronadjenog).add(studenti.get(i));
			} else {
				List<Student> studentiZaStudij = new ArrayList<>();
				studentiZaStudij.add(studenti.get(i));
				studentiPoStudijima.add(studentiZaStudij);
			}
		}

		for (i = 0; i < studentiPoStudijima.size(); i++) {
			Collections.sort(studentiPoStudijima.get(i), Comparator.comparing(Student::getGodinaStudija));
		}

		for (i = 0; i < studentiPoStudijima.size(); i++) {
			System.out.println("Studenti za studij " + studentiPoStudijima.get(i).get(0).getStudij() + ":");
			for (int j = 0; j < studentiPoStudijima.get(i).size(); j++) {
				System.out.println(" - " + studentiPoStudijima.get(i).get(j));
			}
		}
	}
}
