package oop.optional_homework.zadaca3;

public class Student {
	public String ime;
	public String prezime;
	public String studij;
	public int godinaStudija;

	public Student(String ime, String prezime, String studij, int godinaStudija) {
		this.ime = ime;
		this.prezime = prezime;
		this.studij = studij;
		this.godinaStudija = godinaStudija;
	}

	@Override
	public String toString() {
		return "Student [ime=" + ime + ", prezime=" + prezime + ", studij=" + studij + ", godinaStudija="
				+ godinaStudija + "]";
	}
}
