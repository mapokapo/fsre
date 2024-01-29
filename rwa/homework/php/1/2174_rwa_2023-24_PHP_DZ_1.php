<?php
/*
	Leo Petrović - 2174/RR
*/

// 1. zadatak - Koristenjem for petlje ispisite niz brojeva od 1 do 20 i njihove kvadrate. Svaki par ispisati u novi red!
echo "Zadatak 1 - rješenje:<br />";

for ($i = 1; $i <= 20; $i++) {
	echo $i . " - " . $i*$i . "<br />";
}

// 2. Zadatak - Izracunati sumu prvih 100 prirodnih brojeva koristenjem for petlje.
echo "<br />Zadatak 2 - rješenje:<br />";

$suma = 0;
for ($i = 1; $i <= 100; $i++) {
	$suma += $i;
}
echo $suma . "<br />";

// 3. Zadatak - Izracunati sumu prvih 100 prirodnih brojeva koristenjem while petlje.
echo "<br />Zadatak 3 - rješenje:<br />";

$suma = 0;
$i = 1;
while ($i <= 100) {
	$suma += $i;
	$i++;
}
echo $suma . "<br />";

// 4. Zadatak - Napisati php skriptu/kod koja/i ispisuje sve parne brojeve od 1 do 100, svaki broj u novom retku.
echo "<br />Zadatak 4 - rješenje:<br />";

for ($i = 1; $i <= 100; $i++) {
	if ($i % 2 === 0) {
		echo $i . "<br />";
	}
}

// 5. Zadatak - Ispisati sve troznamenkaste parne brojeve!
echo "<br />Zadatak 5 - rješenje:<br />";

for ($i = 100; $i <= 999; $i++) {
	if ($i % 2 === 0) {
		echo $i . "<br />";
	}
}

// 6. Zadatak - Ispisati sve dvoznamenkaste brojeve djeljive s 3 i 5 ili s oba!
echo "<br />Zadatak 6 - rješenje:<br />";

for ($i = 10; $i <= 99; $i++) {
	if ($i % 3 === 0 || $i % 5 === 0) {
		echo $i . "<br />";
	}
}

// 7. Zadatak - Zadana je varijabla $grad koja sadrzava polje s clanovima godina => broj stanovnika. Izračunajte:
//   a. Prosječan broj stanovnika kroz sve godine?
//   b. Koje godine je bilo najviše stanovnika?
//   c. Koliko godina se provodilo mjerenje?
// Primjer varijable
// $grad = array(1995 => 24000, 1997 => 25510, 1998 => 29154, 2000 =>32124, 2002 => 33114);
echo "<br />Zadatak 7 - rješenje:<br />";

$grad = [1995 => 24000, 1997 => 25510, 1998 => 29154, 2000 => 32124, 2002 => 33114];
$zbroj = 0;
$najbrojnija_godina = 0;
$populacija_najbrojnije_godine = $grad[0];
foreach ($grad as $godina => $populacija) {
	$zbroj += $populacija;

	if ($populacija > $populacija_najbrojnije_godine) {
		$najbrojnija_godina = $godina;
		$populacija_najbrojnije_godine = $populacija;
	}
}
echo "Prosječan broj stanovnika kroz sve godine: " . $zbroj / count($grad) . "<br />";
echo "Godina sa najviše stanovnika je " . $najbrojnija_godina . ". sa " . $populacija_najbrojnije_godine . " stanovnika.<br />";
echo "Mjerenje se provodilo " . count($grad) . " godina.<br />";

// 8. Zadatak - Napisite funkciju koja ce ispitati da li je broj prost. Prosti brojevi su djeljivi iskljucivo sa samim sobom ili s 1. Zatim, ispisite sve proste brojeve manje od 100!
echo "<br />Zadatak 8 - rješenje:<br />";

function je_li_prost($broj) {
	for ($i = 2; $i < $broj; $i++) {
		if ($broj % $i === 0) {
			return false;
		}
	}

	return true;
}

for ($i = 2; $i <= 100; $i++) {
	if (je_li_prost($i)) {
		echo $i . "<br />";
	}
}

// 9. Zadatak - Napišite PHP program koji ce sve članove polja $brojevi zbrojiti pomocu foreach petlje:
// $brojevi = array( 1, 22, 3, 4, 5, 55, 12, 49,94, 23, 7);
echo "<br />Zadatak 9 - rješenje:<br />";

$brojevi = array( 1, 22, 3, 4, 5, 55, 12, 49,94, 23, 7);
$zbroj = 0;
foreach ($brojevi as $broj) {
	$zbroj += $broj;
}

echo "Zbroj je: " . $zbroj . "<br />";

// 10. Zadatak - Dodijelite varijablama $a i $b proizvoljne cjelobrojne vrijednosti – sirinu i duzinu zamisljenog pravokutnika.
// Izračunajte površinu pravokutnika i vrijednost zapišite u varijablu $pov_pravokutnik.
// Zatim spišite u browseru: "Površina pravokutnika širine ____ i dužine ___ iznosi ____" (popunite s vrijednostima iz varijabli)
echo "<br />Zadatak 10 - rješenje:<br />";

$a = 5;
$b = 6;

$pov_pravokutnik = $a * $b;

echo "Površina pravokutnika širine " . $a . " i dužine " . $b . " iznosi " . $pov_pravokutnik . ".<br />";
?>