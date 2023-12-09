package oop.homework.zadaca1;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/*
 * Leo Petrović - 2174/RR
 * 
 * Zadatak 5. - Napisati program u Javi koji unosi decimalne brojeve sve dok se ne unese broj ciji je cijeli dio barem 100 puta veci od njegovog decimalnog dijela. Nakon toga ispisuje se ona znamenka koja se ponavlja najvise puta u cijelim dijelovima svih unesenih brojeva i to onoliko puta koliko se puta ponovila.
*/

public class Zadatak5 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		List<Float> brojevi = new ArrayList<>();
		float broj;
		do {
			System.out.print("Unesite broj: ");
			broj = scanner.nextFloat();
			brojevi.add(broj);
		} while ((int) broj <= ((broj - ((int) broj)) * 100));

		List<Integer> cijeliBrojevi = brojevi.stream().map(b -> (int) (float) b).toList();

		List<List<Integer>> znamenke2d = cijeliBrojevi.stream()
				.map(b -> List.of(String.valueOf(b).split("")).stream().map(Integer::parseInt).toList()).toList();

		List<Integer> znamenke = new ArrayList<>();
		for (int i = 0; i < znamenke2d.size(); i++) {
			for (int j = 0; j < znamenke2d.get(i).size(); j++) {
				znamenke.add(znamenke2d.get(i).get(j));
			}
		}

		Integer najcescaZnamenka = null;
		int brojPonavljanjaNajcesceZnamenke = 0;
		for (int i = 0; i < znamenke.size(); i++) {
			int brojPonavljanja = 0;
			for (int j = 0; j < znamenke.size(); j++) {
				if (znamenke.get(i).equals(znamenke.get(j))) {
					brojPonavljanja++;
				}
			}

			if (brojPonavljanja > brojPonavljanjaNajcesceZnamenke) {
				najcescaZnamenka = znamenke.get(i);
				brojPonavljanjaNajcesceZnamenke = brojPonavljanja;
			}
		}

		System.out.println("Najcesca znamenka je " + najcescaZnamenka + " i ponavlja se " + brojPonavljanjaNajcesceZnamenke
				+ " puta.");

		scanner.close();
	}
}
