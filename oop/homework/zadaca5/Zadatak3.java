package oop.homework.zadaca5;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;

/*
 * Leo Petrović - 2174/RR
 * 
 * Zadatak 3. - Napisati program koji prikazuje formu koja predstavlja jednostavni kalkulator sa gumbima
sa znamenkama od 0 do 9, četiri osnovne računske operacije (+, -, * i /) i provođenje
operacije (=), resetiranje zadnjeg unosa (C) i gašenje aplikacije (X) te tekstualnim okvirom
za prikaz unesenih operanada i rezultata. Pritiskom na gumbe sa znamenkama unosi se
operand (npr. za pritisnute tipke 4, 3 i 7 u tekstualnom okviru prikazuje se operand 437).
Pritiskom na gumb neke od računskih operacija briše se tekstualni okvir i potvrđuje prvi
operand. Nakon toga unosi se drugi operand. Pritiskom na gumb za provođenje operacije
briše se tekstualni okvir i potvrđuje drugi operand, provodi računska operacija i u
tekstualni okvir upisuje rezultat. Pritisak na gumb za resetiranje zadnjeg unosa briše se
tekstualni okvir. Pritiskom na gumb za gašenje aplikacije zatvara se forma.
*/

public class Zadatak3 {
	public static ResultPanel resultPanel;
	public static KeypadPanel keypadPanel;

	public static void main(String[] args) {
		JFrame frame = new JFrame();

		ResultPanel resultPanel = new ResultPanel();
		Zadatak3.resultPanel = resultPanel;

		KeypadPanel keypadPanel = new KeypadPanel();
		Zadatak3.keypadPanel = keypadPanel;

		// Prozor aplikacije
		frame.setTitle("Zadatak 3");
		frame.setSize(new Dimension(580, 770));
		frame.setResizable(false);

		// Panel za rezultat i gumbe za gasenje aplikacije i resetiranje unosa
		resultPanel.setLayout(null);
		resultPanel.setBounds(20, 20, 560, 170);

		// Panel za gumbe sa znamenkama i osnovnim racunskim operacijama
		keypadPanel.setLayout(null);
		keypadPanel.setBounds(20, 210, 560, 560);

		frame.add(resultPanel);
		frame.add(keypadPanel);
		frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
		frame.setLayout(null);
		frame.setVisible(true);
	}
}

class ResultPanel extends JPanel {
	public JTextField textField;
	public JButton exitButton;
	public JButton clearButton;

	public ResultPanel() {
		this.textField = new JTextField();
		this.exitButton = new JButton("X");
		this.clearButton = new JButton("C");

		// Tekstualni okvir za prikaz unesenih operanada i rezultata
		this.textField.setBounds(0, 0, 400, 170);
		this.textField.setEditable(false);
		this.textField.setHorizontalAlignment(SwingConstants.RIGHT);
		this.textField.setFont(new Font("Arial", Font.PLAIN, 30));

		// Gumb za gašenje aplikacije
		this.exitButton.setBounds(420, 0, 120, 75);
		this.exitButton.setFont(new Font("Arial", Font.PLAIN, 30));
		this.exitButton.addActionListener(e -> System.exit(0));

		// Gumb za resetiranje zadnjeg unosa
		this.clearButton.setBounds(420, 95, 120, 75);
		this.clearButton.setFont(new Font("Arial", Font.PLAIN, 30));
		this.clearButton.addActionListener(e -> {
			this.textField.setText("");
			Zadatak3.keypadPanel.firstOperand = "";
			Zadatak3.keypadPanel.secondOperand = "";
			Zadatak3.keypadPanel.operator = "";
		});

		this.add(this.textField);
		this.add(this.exitButton);
		this.add(this.clearButton);
	}
}

class KeypadPanel extends JPanel {
	public java.util.List<JButton> numberButtons = new ArrayList<>();
	public JButton plusButton = new JButton("+");
	public JButton minusButton = new JButton("-");
	public JButton multiplyButton = new JButton("*");
	public JButton divideButton = new JButton("/");
	public JButton equalsButton = new JButton("=");

	public String firstOperand = "";
	public String secondOperand = "";
	public String operator = "";

	public KeypadPanel() {
		// Gumbi sa znamenkama od 0 do 9
		int[] brojevi = new int[] { 7, 8, 9, 4, 5, 6, 1, 2, 3, 0 };
		for (int i = 0; i < 10; i++) {
			int broj = brojevi[i];

			JButton button = new JButton(String.valueOf(broj));
			button.setBounds((int) ((i % 3) * 120 + (i % 3) * 20), (int) ((i / 3) * 120 + (i / 3) * 20), 120,
					120);
			button.setFont(new Font("Arial", Font.PLAIN, 30));
			button.addActionListener(e -> {
				if (this.operator.equals("")) {
					this.firstOperand += button.getText();
					Zadatak3.resultPanel.textField.setText(this.firstOperand);
				} else {
					this.secondOperand += button.getText();
					Zadatak3.resultPanel.textField.setText(this.secondOperand);
				}
			});
			this.numberButtons.add(button);
		}

		// Gumbi za osnovne računske operacije
		this.plusButton.setFont(new Font("Arial", Font.PLAIN, 30));
		this.minusButton.setFont(new Font("Arial", Font.PLAIN, 30));
		this.multiplyButton.setFont(new Font("Arial", Font.PLAIN, 30));
		this.divideButton.setFont(new Font("Arial", Font.PLAIN, 30));

		this.plusButton.addActionListener(e -> {
			this.operator = "+";
			Zadatak3.resultPanel.textField.setText("");
		});
		this.minusButton.addActionListener(e -> {
			this.operator = "-";
			Zadatak3.resultPanel.textField.setText("");
		});
		this.multiplyButton.addActionListener(e -> {
			this.operator = "*";
			Zadatak3.resultPanel.textField.setText("");
		});
		this.divideButton.addActionListener(e -> {
			this.operator = "/";
			Zadatak3.resultPanel.textField.setText("");
		});

		// Gumb za provođenje operacije
		this.equalsButton.setFont(new Font("Arial", Font.PLAIN, 30));
		this.equalsButton.addActionListener(e -> {
			if (this.firstOperand.equals("") || this.secondOperand.equals("")) {
				return;
			}

			String rezultat = izracunajRezultat();
			Zadatak3.resultPanel.textField.setText(rezultat);

			this.firstOperand = rezultat;
			this.secondOperand = "";
			this.operator = "";
		});

		// Postavljanje gumba na odgovarajuću poziciju
		this.divideButton.setBounds(420, 0, 120, 120);
		this.multiplyButton.setBounds(420, 140, 120, 120);
		this.minusButton.setBounds(420, 280, 120, 120);
		this.plusButton.setBounds(420, 420, 120, 120);

		this.equalsButton.setBounds(140, 420, 260, 120);

		this.add(this.numberButtons.get(7));
		this.add(this.numberButtons.get(8));
		this.add(this.numberButtons.get(9));
		this.add(this.divideButton);
		this.add(this.numberButtons.get(4));
		this.add(this.numberButtons.get(5));
		this.add(this.numberButtons.get(6));
		this.add(this.multiplyButton);
		this.add(this.numberButtons.get(1));
		this.add(this.numberButtons.get(2));
		this.add(this.numberButtons.get(3));
		this.add(this.minusButton);
		this.add(this.numberButtons.get(0));
		this.add(this.equalsButton);
		this.add(this.plusButton);
	}

	private String izracunajRezultat() {
		double firstOperandInt = Double.parseDouble(this.firstOperand);
		double secondOperandInt = Double.parseDouble(this.secondOperand);

		double resultInt = 0;
		String result = null;

		switch (this.operator) {
			case "+":
				resultInt = firstOperandInt + secondOperandInt;
				break;
			case "-":
				resultInt = firstOperandInt - secondOperandInt;
				break;
			case "*":
				resultInt = firstOperandInt * secondOperandInt;
				break;
			case "/":
				if (secondOperandInt == 0) {
					result = "ERROR";
					break;
				}
				resultInt = firstOperandInt / secondOperandInt;
				break;
			default:
				break;
		}

		result = result == null ? String.valueOf(resultInt) : result;

		return result;
	}
}