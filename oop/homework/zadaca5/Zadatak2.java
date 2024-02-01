package oop.homework.zadaca5;

import javax.swing.*;
import java.awt.*;

/*
 * Leo Petrović - 2174/RR
 * 
 * Zadatak 2. - Napisati program koji prikazuje formu sa dva tekstualna okvira za unos podataka,
gumbom za potvrdu i labelom. U dva tekstualna okvira se unose proizvoljni cijeli brojevi.
Pritiskom na gumb za potvrdu određuje se koji je od dva broj manji, a koji veći. Labeli se
dodjeljuje sadržaj: "Prosti brojevi između <manji od dva unesena broja> i <veći od dva
unesena broja> su <svi prosti brojevi između unesenih brojeva, odvojeni zarezom i s
točkom na kraju>"
*/

public class Zadatak2 {
	public static void main(String[] args) {
		JFrame frame = new JFrame();
		JTextField textField1 = new JTextField();
		JTextField textField2 = new JTextField();
		JButton button = new JButton("Potvrdi");
		JLabel label = new JLabel();

		// Prozor aplikacije
		frame.setTitle("Zadatak 2");
		frame.setSize(new Dimension(800, 600));

		// Tekstualni okviri za unos podataka
		textField1.setBounds(20, 20, 370, 80);
		textField2.setBounds(410, 20, 370, 80);

		// Gumb za potvrdu
		button.setBounds(20, 120, 760, 80);
		button.addActionListener(e -> label.setText(Zadatak2.ispisiProste(textField1, textField2)));

		// Label
		label.setBounds(20, 220, 760, 360);
		label.setVerticalAlignment(SwingConstants.TOP);

		frame.add(textField1);
		frame.add(textField2);
		frame.add(button);
		frame.add(label);
		frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
		frame.setLayout(null);
		frame.setVisible(true);
	}

	private static String ispisiProste(JTextField textField1, JTextField textField2) {
		int broj1;
		try {
			broj1 = Integer.parseInt(textField1.getText());
		} catch (NumberFormatException e) {
			return "Prvi broj nije cijeli broj.";
		}

		int broj2;
		try {
			broj2 = Integer.parseInt(textField2.getText());
		} catch (NumberFormatException e) {
			return "Drugi broj nije cijeli broj.";
		}

		int manji = Math.min(broj1, broj2);
		int veci = Math.max(broj1, broj2);

		StringBuilder rezultatBuilder = new StringBuilder("Prosti brojevi između " + manji + " i " + veci + " su: ");

		for (int i = manji; i <= veci; i++) {
			if (Zadatak2.jestProst(i)) {
				rezultatBuilder.append(i).append(", ");
			}
		}

		String rezultat = rezultatBuilder.toString();
		rezultat = rezultat.substring(0, rezultat.length() - 2) + ".";

		return rezultat;
	}

	private static boolean jestProst(int broj) {
		if (broj < 2) {
			return false;
		}

		for (int i = 2; i <= Math.sqrt(broj); i++) {
			if (broj % i == 0) {
				return false;
			}
		}

		return true;
	}
}
