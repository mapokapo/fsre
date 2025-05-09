<?php
/*
	Leo Petrović - 2174/RR
*/

// Zadatak 3. - Napisati php skriptu s pripadajucom PHP funkcijom koja ima jedan ulazni argumenta (niz brojcanih vrijednosti kao string, odvojenih zarezom).
// Funkcija zatim ispisuje aritmeticku i geometrijsku sredinu između tih brojeva. Izvrsiti nekoliko poziva funkcije s proizvoljnim nizom vrijednostima!
// Primjer ulaznog niza vrijednosti:
// $skup = "1,3,6,7,8,4,4,16,18,14,19";
echo "Zadatak 3 - rješenje:<br />";

function aritmeticka_sredina($niz) {
	$zbroj = 0;

	foreach ($niz as $broj) {
		$zbroj += $broj;
	}

	return $zbroj / count($niz);
}

function geometrijska_sredina($niz) {
	$produkt = 1;

	foreach ($niz as $broj) {
		$produkt *= $broj;
	}
	
	return pow($produkt, 1 / count($niz));
}

function ispisi_sredine($str) {
	$niz = array_map("intval", explode(",", $str));

	echo "Aritmetička sredina brojeva " . $str . " je: " . aritmeticka_sredina($niz) . ".<br />";
	echo "Geometrijska sredina brojeva " . $str . " je: " . geometrijska_sredina($niz) . ".<br /><br />";
}

ispisi_sredine("1,3,6,7,8,4,4,16,18,14,19");
ispisi_sredine("1,2,3,4,5,6,7,8,9,10");
ispisi_sredine("1,2,3,4,5,6,7,8,9,10,11,12,13,14,15");
ispisi_sredine("1, 2");
ispisi_sredine("1, 9");
?>