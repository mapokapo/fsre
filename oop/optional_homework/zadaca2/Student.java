package oop.optional_homework.zadaca2;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class Student {
	private String ime;
	private String prezime;
	private String studij;
	private int brojIndeksa;
	private char spol;
	private LocalDate datumRodjenja;

	public Student(String ime, String prezime, String studij, int brojIndeksa, char spol, LocalDate datumRodjenja) {
		this.ime = ime;
		this.prezime = prezime;
		this.studij = studij;
		this.brojIndeksa = brojIndeksa;
		this.spol = spol;
		this.datumRodjenja = datumRodjenja;
	}

	public Student(String ime, String prezime) {
		this.ime = ime;
		this.prezime = prezime;
	}

	public String getIme() {
		return ime;
	}

	public String getPrezime() {
		return prezime;
	}

	public String getStudij() {
		return studij;
	}

	public int getBrojIndeksa() {
		return brojIndeksa;
	}

	public char getSpol() {
		return spol;
	}

	public LocalDate getDatumRodjenja() {
		return datumRodjenja;
	}

	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		sb.append("Student: " + ime + " " + prezime + "\n");
		sb.append("Datum rođenja: " + datumRodjenja.format(DateTimeFormatter.ofPattern("dd.MM.yyyy")) + "\n");
		sb.append("Studij: " + studij + "\n");
		sb.append("Broj indeksa: " + brojIndeksa + "\n");
		sb.append("Spol: " + spol + "\n");
		return sb.toString();
	}
}
