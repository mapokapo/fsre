package oop.homework.zadaca4;

/*
 * Leo Petrović - 2174/RR
 * 
 * Zadatak 2.
 */

// Napisati konstruktore za sve razrede, pri čemu konstruktori izvedenih razreda koriste konstruktor osnovnog razreda.
// Napisati get i set metode za sve podatkovne članove.
// Preopteretiti metodu toString() u svim razredima.

// Definirati sucenje Dokument koje sadrži metodu dajPeriodPosudbe().
interface Dokument {
	public void dajPeriodPosudbe();
}

// Definirati abstraktni razred DokumentKnjiznice koji implementira sučelje
// Dokument.
abstract class DokumentKnjiznice {
	// Razred DokumentKnjiznice ima podatkovne članove ID (cijeli broj) i
	// nazivDokumenta (tekstualni podatak).
	private int ID;
	private String nazivDokumenta;

	protected DokumentKnjiznice(int ID, String nazivDokumenta) {
		this.ID = ID;
		this.nazivDokumenta = nazivDokumenta;
	}

	public int getID() {
		return ID;
	}

	public void setID(int iD) {
		ID = iD;
	}

	public String getNazivDokumenta() {
		return nazivDokumenta;
	}

	public void setNazivDokumenta(String nazivDokumenta) {
		this.nazivDokumenta = nazivDokumenta;
	}

	// Razred DokumentKnjiznice sadrži metodu dajPeriodPosudbe() bez parametara koja
	// za objekte različitih izvedenih razreda vraća različite cjelobrojne
	// vrijednosti (za knjige je period posudbe 14 dana, osim za udžbenike za koje
	// je 120 dana, za časopise 7 dana, a za digitalne i e-dokumente 30 dana).
	public int dajPeriodPosudbe() {
		if (this instanceof Knjiga) {
			if (this instanceof Udzbenik) {
				return 120;
			}

			return 14;
		} else if (this instanceof Casopis) {
			return 7;
		} else if (this instanceof DigitalniDokument || this instanceof E_Dokument) {
			return 30;
		} else {
			throw new RuntimeException("Nepoznati dokument");
		}
	}

	// Razred DokumentKnjiznice sadrži apstraktnu metodu jeLiPotrebanPolog() (koja
	// vraća logičku vrijednost true za udžbenike i digitalne sadržaje, odnosno
	// vrijednost false).
	public abstract boolean jeLiPotrebanPolog();

	// Razred DokumentKnjiznice sadrži apstraktnu metodu dajIznosPologa() koji vraća
	// različite (proizvoljne) vrijednosti za sve vrste dokumena.
	public abstract double dajIznosPologa();

	public String toString() {
		return String.format("Nepoznati dokument (ID: %d): %s", this.getID(), this.getNazivDokumenta());
	}
}

// Napraviti razrede Knjiga, Casopis, DigitalniDokument i E_Dokument koji
// nasljeđuju razred DokumentKnjiznice.

class Knjiga extends DokumentKnjiznice {
	// Razred Knjiga ima podatkovni član autor (tekstualni podatak).
	private String autor;

	public Knjiga(int ID, String nazivDokumenta, String autor) {
		super(ID, nazivDokumenta);

		this.autor = autor;
	}

	public String getAutor() {
		return autor;
	}

	public void setAutor(String autor) {
		this.autor = autor;
	}

	public boolean jeLiPotrebanPolog() {
		return false;
	}

	public double dajIznosPologa() {
		return 50;
	}

	@Override
	public String toString() {
		return String.format("Knjiga (ID: %d): %s - %s", this.getID(), this.getNazivDokumenta(), this.getAutor());
	}
}

class Casopis extends DokumentKnjiznice {
	// Razred Casopis ima podatkovne članove kategorijaSadrzaja (tekstualni podatak)
	// i izdanje (cijeli broj).
	private String kategorijaSadrzaja;
	private int izdanje;

	public Casopis(int ID, String nazivDokumenta, String kategorijaSadrzaja, int izdanje) {
		super(ID, nazivDokumenta);

		this.kategorijaSadrzaja = kategorijaSadrzaja;
		this.izdanje = izdanje;
	}

	public String getKategorijaSadrzaja() {
		return kategorijaSadrzaja;
	}

	public void setKategorijaSadrzaja(String kategorijaSadrzaja) {
		this.kategorijaSadrzaja = kategorijaSadrzaja;
	}

	public int getIzdanje() {
		return izdanje;
	}

	public void setIzdanje(int izdanje) {
		this.izdanje = izdanje;
	}

	public boolean jeLiPotrebanPolog() {
		return false;
	}

	public double dajIznosPologa() {
		return 15;
	}

	@Override
	public String toString() {
		return String.format("Casopis (ID: %d, Kategorija: %s): %s (Izdanje #%d)", this.getID(),
				this.getKategorijaSadrzaja(), this.getNazivDokumenta(), this.getIzdanje());
	}
}

// Razred DigitalniDokument opisuje digitalni medij za pohranu podataka.
class DigitalniDokument extends DokumentKnjiznice {
	// Razred DigitalniDokument ima podatkovni član tip (tekstualni podatak, npr. CD
	// ili VHS).
	private String tip;

	public DigitalniDokument(int ID, String nazivDokumenta, String tip) {
		super(ID, nazivDokumenta);

		this.tip = tip;
	}

	public String getTip() {
		return tip;
	}

	public void setTip(String tip) {
		this.tip = tip;
	}

	public boolean jeLiPotrebanPolog() {
		return true;
	}

	public double dajIznosPologa() {
		return 10;
	}

	@Override
	public String toString() {
		return String.format("Digitalni Dokument (ID: %d): %s [%s]", this.getID(),
				this.getNazivDokumenta(), this.getTip());
	}
}

// Razred E_Dokument opisuje sadržaj kojeg je moguće preuzeti na neki
// elektronski uređaj
class E_Dokument extends DokumentKnjiznice {
	// Razred E_Dokument ima podatkovni član (tekstualni podatak).
	private String nesto;

	public E_Dokument(int ID, String nazivDokumenta, String nesto) {
		super(ID, nazivDokumenta);

		this.nesto = nesto;
	}

	public String getNesto() {
		return nesto;
	}

	public void setNesto(String nesto) {
		this.nesto = nesto;
	}

	public boolean jeLiPotrebanPolog() {
		return false;
	}

	public double dajIznosPologa() {
		return 10;
	}

	@Override
	public String toString() {
		return String.format("E-Dokument (ID: %d): %s [%s]", this.getID(),
				this.getNazivDokumenta(), this.getNesto());
	}
}

// Definirati razred Udzbenik koji nasjeđuje razred Knjiga.
class Udzbenik extends Knjiga {
	// Razred Udzbenik ima podatkovni član predmet (tekstualni podatak).
	private String predmet;

	public Udzbenik(int ID, String nazivDokumenta, String autor, String predmet) {
		super(ID, nazivDokumenta, autor);

		this.predmet = predmet;
	}

	public String getPredmet() {
		return predmet;
	}

	public void setPredmet(String predmet) {
		this.predmet = predmet;
	}

	@Override
	public boolean jeLiPotrebanPolog() {
		return true;
	}

	@Override
	public double dajIznosPologa() {
		return 30;
	}

	@Override
	public String toString() {
		return String.format("Udzbenik za predmet \"%s\" (knjiga, ID: %d): %s - %s", this.getPredmet(), this.getID(),
				this.getNazivDokumenta(), this.getAutor());
	}
}

// Definirati Rjecnik Udzbenik koji nasjeđuje razred Knjiga.
class Rjecnik extends Knjiga {
	// Razred Rjecnik ima podatkovne članove prviJezik i drugiJezik (tekstualni
	// podaci).
	private String prviJezik;
	private String drugiJezik;

	public Rjecnik(int ID, String nazivDokumenta, String autor, String prviJezik, String drugiJezik) {
		super(ID, nazivDokumenta, autor);

		this.prviJezik = prviJezik;
		this.drugiJezik = drugiJezik;
	}

	public String getPrviJezik() {
		return prviJezik;
	}

	public void setPrviJezik(String prviJezik) {
		this.prviJezik = prviJezik;
	}

	public String getDrugiJezik() {
		return drugiJezik;
	}

	public void setDrugiJezik(String drugiJezik) {
		this.drugiJezik = drugiJezik;
	}

	@Override
	public String toString() {
		return String.format("Rjecnik za %s i %s jezik (knjiga, ID: %d): %s - %s", this.getPrviJezik(),
				this.getDrugiJezik(), this.getID(),
				this.getNazivDokumenta(), this.getAutor());
	}
}

// Definirati razred Zadatak2 koji sadrži metodu main() u kojoj će se
// instancirati 50 objekata različitih razreda (slučajnim izborom se određuje
// razred čiji će se objekt inicijalizirati) te se ispisuju podaci za svakog od
// njih.
public class Zadatak2 {
	public static void main(String[] args) {

	}
}