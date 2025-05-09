<?php

/*
	Leo Petrović - 2174/RR
*/

// Zadatak 4. - Napravite PHP program Kalkulator sa sljedecim zahtjevima: OO pristup, klasa naziva Kalkulator koja sadrzi sve potrebne metode i atribute za realizaciju kalkulatora za 4 operacije (+ - / *). Uraditi nekoliko poziva kalkulatora s razlicitim operacijama i ulaznim argumentima.

class Kalkulator
{
	private $a;
	private $b;
	private $operacija;

	public function __construct($a, $b, $operacija)
	{
		$this->a = $a;
		$this->b = $b;
		$this->operacija = $operacija;
	}

	public function izracunaj()
	{
		$rezultat = 0;

		switch ($this->operacija) {
			case "+":
				$rezultat = $this->a + $this->b;
				break;
			case "-":
				$rezultat = $this->a - $this->b;
				break;
			case "*":
				$rezultat = $this->a * $this->b;
				break;
			case "/":
				if ($this->b === 0) {
					die("Dijeljenje s nulom nije dozvoljeno");
					break;
				}
				$rezultat = $this->a / $this->b;
				break;
			default:
				die("Nepoznata operacija");
				break;
		}

		return $rezultat;
	}

	public function __toString()
	{
		return sprintf("%d %s %d = %d", $this->a, $this->operacija, $this->b, $this->izracunaj());
	}
}

$k1 = new Kalkulator(1, 2, "+");
$k2 = new Kalkulator(1, 2, "-");
$k3 = new Kalkulator(1, 2, "*");
$k4 = new Kalkulator(1, 2, "/");

echo $k1;
echo "\n";
echo $k2;
echo "\n";
echo $k3;
echo "\n";
echo $k4;
