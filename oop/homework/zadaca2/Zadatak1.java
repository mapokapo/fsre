package oop.homework.zadaca2;

import java.util.Scanner;

/*
 * Leo Petrović - 2174/RR
 * 
 * Zadatak 1. - Napisati program u Javi koji od korisnika traži unos 10 imena i pohranjuje ih u niz razreda String. Nakon toga kreira dva nova niza tako da u prvi pohranjuje sva imena kojima je početno slovo jednako završnom, a u drugi ostala imena iz unesenog niza. Konačno, program treba ispisati vrijednosti svih nizova. 
*/

public class Zadatak1 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		String[] imena = new String[10];
		for (int i = 0; i < 10; i++) {
			System.out.print("Unesite " + (i + 1) + ". ime: ");
			imena[i] = scanner.nextLine();
		}

		scanner.close();

		String[] prvi = new String[10];
		String[] drugi = new String[10];
		int prviBrojac = 0;
		int drugiBrojac = 0;
		for (int i = 0; i < 10; i++) {
			if (Character.toLowerCase(imena[i].charAt(0)) == Character.toLowerCase(imena[i].charAt(imena[i].length() - 1))) {
				prvi[prviBrojac] = imena[i];
				prviBrojac++;
			} else {
				drugi[drugiBrojac] = imena[i];
				drugiBrojac++;
			}
		}

		System.out.println("Imena kojima je prvo i zadnje slovo isto:");
		for (int i = 0; i < prviBrojac; i++) {
			System.out.println(prvi[i]);
		}

		System.out.println("Ostala imena:");
		for (int i = 0; i < drugiBrojac; i++) {
			System.out.println(drugi[i]);
		}
	}
}
