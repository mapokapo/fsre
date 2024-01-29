<?php

/*
	Leo Petrović - 2174/RR
*/

// Zadatak 3. - Deklarirati objekt "person" koja ce imati svojstva ime, prezime, i masa u kg.  Deklarirati i metodu koja ce racunati kolika je tezina te osobe u kg (u pozivu i ispisite u browser). Zatim deklarirati metodu koja će računati koliku tezinu ta osoba ima na Mjesecu. Inicijalizirati nekoliko razlicitih osoba.

class Person
{
	private String $ime;
	private String $prezime;
	private int $tezina;

	public function __construct($ime, $prezime, $tezina)
	{
		$this->ime = $ime;
		$this->prezime = $prezime;
		$this->tezina = $tezina;
	}

	public function dobijTezinu()
	{
		return $this->tezina;
	}

	public function dobijTezinuNaMjesecu()
	{
		return $this->tezina / 6;
	}

	public function __toString()
	{
		return sprintf("%s %s (%.2fkg, na Mjesecu %.2fkg)", $this->ime, $this->prezime, $this->dobijTezinu(), $this->dobijTezinuNaMjesecu());
	}
}

$p1 = new Person("Ante", "Antic", 70);
$p2 = new Person("Jure", "Juric", 50);
$p3 = new Person("Jozo", "Jozic", 100);
$p4 = new Person("Marko", "Markic", 60);
$p5 = new Person("Ivo", "Ivic", 90);

echo $p1;
echo "\n";
echo $p2;
echo "\n";
echo $p3;
echo "\n";
echo $p4;
echo "\n";
echo $p5;
