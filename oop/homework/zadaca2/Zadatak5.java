package oop.homework.zadaca2;

import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Scanner;

/*
 * Leo Petrović - 2174/RR
 * 
 * Zadatak 5. - Napisati program u Javi koji unosi 20 cijelih brojeva u niz koristeći razred List te ispisati uneseni niz brojeva. Potom sve neparne brojeve na parnim mjestima zamijeniti najvećim neparnim unesenim brojem te ispisati novo stanje niza.
*/

public class Zadatak5 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		List<Integer> brojevi = new ArrayList<>();

		int i = 0;
		while (i < 20) {
			int broj;

			System.out.print("Unesite broj: ");

			try {
				broj = scanner.nextInt();
			} catch (InputMismatchException e) {
				System.out.println("Broj nije validan.");
				continue;
			}

			brojevi.add(broj);

			i++;
		}

		scanner.close();

		System.out.println("Uneseni brojevi su:");
		for (i = 0; i < brojevi.size(); i++) {
			int broj = brojevi.get(i);
			System.out.print(broj + (i < brojevi.size() - 1 ? ", " : "\n"));
		}

		Integer najveciNeparni = null;
		for (int broj : brojevi) {
			if (broj % 2 == 1 && (najveciNeparni == null || broj > najveciNeparni)) {
				najveciNeparni = broj;
			}
		}

		if (najveciNeparni != null) {
			for (i = 0; i < brojevi.size(); i++) {
				boolean parnoMjesto = (i + 1) % 2 == 0;
				int broj = brojevi.get(i);
				if (parnoMjesto && broj % 2 == 1) {
					brojevi.set(i, najveciNeparni);
				}
			}
		}

		System.out.println("Novi niz brojeva je:");
		for (i = 0; i < brojevi.size(); i++) {
			int broj = brojevi.get(i);
			System.out.print(broj + (i < brojevi.size() - 1 ? ", " : "\n"));
		}
	}
}
