package oop.optional_homework.zadaca6;

import java.time.LocalDate;

/*
 * definirati aps raz Gradjevina sa atributima: vrsta gradjevine (clan), ispis gradjevine (metoda). Kreirati raz. Zgrada koja moze biti Stambena ili Poslovna, i ima atribute: status (Izgradjena, ili U Gradnji, odredi se na temelju atributa godinaIzgradnje). Zgrada ima atribute visina i broj katova. Kreirati razred Cesta (nasljeduje Gradjevina) sa atributima: duljina i odakle dokle vodi ta cesta (2 clana). Kreirati dodatna 2 razreda Kuca i StambenaZgrada koje nasljedjuju Zgrada. StambenaZgrada ima atribut broj stanova. Za sve klase dodati konstruktore, i metode za get i set.
 */

abstract class Gradjevina {
	private String vrsta;

	protected Gradjevina(String vrsta) {
		this.vrsta = vrsta;
	}

	public String getVrsta() {
		return vrsta;
	}

	public void setVrsta(String vrsta) {
		this.vrsta = vrsta;
	}

	public String toString() {
		return "Gradjevina je visoka " + this.vrsta + " metara.";
	}
}

class Zgrada extends Gradjevina {
	private String tip;
	private String status;
	private int godinaIzgradnje;
	private double visina;
	private int brojKatova;

	public Zgrada(String tip, int godinaIzgradnje, double visina, int brojKatova) {
		super("Zgrada");

		LocalDate danas = LocalDate.now();
		LocalDate godinaIzgradjeDate = LocalDate.of(godinaIzgradnje, 1, 1);

		this.status = godinaIzgradjeDate.isBefore(danas) ? "Izgradjena" : "U gradnji";
		this.tip = tip;
		this.godinaIzgradnje = godinaIzgradnje;
		this.visina = visina;
		this.brojKatova = brojKatova;
	}

	public String getTip() {
		return tip;
	}

	public void setTip(String tip) {
		this.tip = tip;
	}

	public String getStatus() {
		return status;
	}

	public void setStatus(String status) {
		this.status = status;
	}

	public int getGodinaIzgradnje() {
		return godinaIzgradnje;
	}

	public void setGodinaIzgradnje(int godinaIzgradnje) {
		this.godinaIzgradnje = godinaIzgradnje;
	}

	public double getVisina() {
		return visina;
	}

	public void setVisina(double visina) {
		this.visina = visina;
	}

	public int getBrojKatova() {
		return brojKatova;
	}

	public void setBrojKatova(int brojKatova) {
		this.brojKatova = brojKatova;
	}

	@Override
	public String toString() {
		if (this.status.equals("U gradnji")) {
			return "Zgrada (" + this.getTip() + ") je visoka " + this.visina + " metara, ima " + this.brojKatova
					+ " katova i izgradnja ce poceti "
					+ this.godinaIzgradnje + ". godine.";
		} else {
			return "Zgrada (" + this.getTip() + ") je visoka " + this.visina + " metara, ima " + this.brojKatova
					+ " katova i izgradnja je pocela "
					+ this.godinaIzgradnje + ". godine.";
		}
	}
}

class Cesta extends Gradjevina {
	private double duljina;
	private String odakle;
	private String dokle;

	public Cesta(double duljina, String odakle, String dokle) {
		super("Cesta");

		this.duljina = duljina;
		this.odakle = odakle;
		this.dokle = dokle;
	}

	public double getDuljina() {
		return duljina;
	}

	public void setDuljina(double duljina) {
		this.duljina = duljina;
	}

	public String getOdakle() {
		return odakle;
	}

	public void setOdakle(String odakle) {
		this.odakle = odakle;
	}

	public String getDokle() {
		return dokle;
	}

	public void setDokle(String dokle) {
		this.dokle = dokle;
	}

	@Override
	public String toString() {
		return "Cesta je duga " + this.duljina + " metara, i vodi od '" + this.odakle + "' do '" + this.dokle + "'.";
	}
}

class Kuca extends Zgrada {
	public Kuca(int godinaIzgradnje, double visina, int brojKatova) {
		super("Stambena", godinaIzgradnje, visina, brojKatova);

		super.setVrsta("Kuca");
	}

	@Override
	public String toString() {
		if (super.getStatus().equals("U gradnji")) {
			return "Kuca je visoka " + super.getVisina() + " metara, ima " + super.getBrojKatova()
					+ " katova i izgradnja ce poceti "
					+ super.getGodinaIzgradnje() + ". godine.";
		} else {
			return "Kuca je visoka " + super.getVisina() + " metara, ima " + super.getBrojKatova()
					+ " katova i izgradnja je pocela "
					+ super.getGodinaIzgradnje() + ". godine.";
		}
	}
}

class StambenaZgrada extends Zgrada {
	private int brojStanova;

	public StambenaZgrada(int godinaIzgradnje, double visina, int brojKatova, int brojStanova) {
		super("Stambena", godinaIzgradnje, visina, brojKatova);

		super.setVrsta("Stambena zgrada");

		this.brojStanova = brojStanova;
	}

	public int getBrojStanova() {
		return brojStanova;
	}

	public void setBrojStanova(int brojStanova) {
		this.brojStanova = brojStanova;
	}

	@Override
	public String toString() {
		if (super.getStatus().equals("U gradnji")) {
			return "Stambena zgrada je visoka " + super.getVisina() + " metara, ima " + super.getBrojKatova()
					+ " katova i izgradnja ce poceti "
					+ super.getGodinaIzgradnje() + ". godine.";
		} else {
			return "Stambena zgrada je visoka " + super.getVisina() + " metara, ima " + super.getBrojKatova()
					+ " katova te " + this.getBrojStanova() + " stanova, i izgradnja je pocela "
					+ super.getGodinaIzgradnje() + ". godine.";
		}
	}
}

public class Zadatak1 {
	public static void main(String[] args) {
		Zgrada zgrada = new Zgrada("Stambena", 2025, 20, 5);
		System.out.println(zgrada);

		Kuca kuca = new Kuca(2020, 20, 5);
		System.out.println(kuca);

		StambenaZgrada stambenaZgrada = new StambenaZgrada(2020, 20, 5, 10);
		System.out.println(stambenaZgrada);

		Cesta cesta = new Cesta(1000, "Zagreb", "Split");
		System.out.println(cesta);
	}
}
