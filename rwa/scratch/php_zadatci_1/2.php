<?php
class Test
{
	private String $ime;
	private String $prezime;
	private int $ostvareni_bodovi;
	private int $max_bodovi;
	private int $ocjena = -1;

	public function __construct(String $ime, String $prezime, int $ostvareni_bodovi, int $max_bodovi)
	{
		$this->ime = $ime;
		$this->prezime = $prezime;
		$this->ostvareni_bodovi = $ostvareni_bodovi;
		$this->max_bodovi = $max_bodovi;
	}

	public function izracunajOcjenu()
	{
		$postotak = ($this->ostvareni_bodovi / $this->max_bodovi) * 100;

		if ($postotak < 50) {
			return 1;
		} else if ($postotak >= 50 && $postotak < 66) {
			return 2;
		} else if ($postotak >= 66 && $postotak < 78) {
			return 3;
		} else if ($postotak >= 78 && $postotak < 90) {
			return 4;
		} else if ($postotak >= 90) {
			return 5;
		}
	}

	public function dobijOcjenu()
	{
		if ($this->ocjena === -1) {
			$this->ocjena = $this->izracunajOcjenu();
		}

		return $this->ocjena;
	}

	public function __toString()
	{
		return sprintf("%s %s (%.2f / %.2f) => %d (%.2f%%)", $this->ime, $this->prezime, $this->ostvareni_bodovi, $this->max_bodovi, $this->dobijOcjenu(), ($this->ostvareni_bodovi / $this->max_bodovi) * 100);
	}
}

$t1 = new Test("Jozo", "Jozic", rand(0, 100), 100);
$t2 = new Test("Jure", "Juric", rand(0, 100), 100);
$t3 = new Test("Ivo", "Ivic", rand(0, 100), 100);
$t4 = new Test("Jozo", "Jozic", rand(0, 100), 100);
$t5 = new Test("Ante", "Antic", rand(0, 60), 60);

echo ($t1);
echo "\n";
echo ($t2);
echo "\n";
echo ($t3);
echo "\n";
echo ($t4);
echo "\n";
echo ($t5);
echo "\n";
