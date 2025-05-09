package oop.homework.zadaca5;

import javax.swing.*;
import java.awt.*;

/*
 * Leo Petrović - 2174/RR
 * 
 * Zadatak 1. - Napisati program koji prikazuje formu sa tekstualnim okvirom za unos podataka, gumbom
za potvrdu i tekstualnim područjem. U tekstualni okvir se unosi proizvoljni tekst. Pritiskom
na gumb za potvrdu, tekst se dodaje kao novi redak u tekstualno područje, ali tako da se
sva velika slova zamijene malima i obratno.
*/

public class Zadatak1 {
	public static void main(String[] args) {
		JFrame frame = new JFrame();
		JTextField textField = new JTextField();
		JButton button = new JButton("Potvrdi");
		JTextArea textArea = new JTextArea();
		JScrollPane scrollPane = new JScrollPane();

		// Prozor aplikacije
		frame.setTitle("Zadatak 1");
		frame.setSize(new Dimension(800, 600));

		// Tekstualni okvir za unos podataka
		textField.setBounds(20, 20, 760, 80);

		// Gumb za potvrdu
		button.setBounds(20, 120, 760, 80);
		button.addActionListener(e -> {
			String text = Zadatak1.zamjeniSlova(textField.getText());
			textField.setText("");
			textArea.append(text + "\n");
		});

		// Tekstualno područje
		textArea.setEditable(false);
		textArea.setLineWrap(true);

		// Scroll lista
		scrollPane.setBounds(20, 220, 760, 360);
		scrollPane.setViewportView(textArea);

		frame.add(textField);
		frame.add(button);
		frame.add(scrollPane);
		frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
		frame.setLayout(null);
		frame.setVisible(true);
	}

	private static String zamjeniSlova(String text) {
		StringBuilder sb = new StringBuilder();
		for (char c : text.toCharArray()) {
			if (Character.isUpperCase(c)) {
				sb.append(Character.toLowerCase(c));
			} else {
				sb.append(Character.toUpperCase(c));
			}
		}
		return sb.toString();
	}
}
