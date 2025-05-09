<?php
/*
	Leo Petrović - 2174/RR
*/

// Zadatak 1. - Napisite funkciju koja će ispitati da li je broj prost. Prosti brojevi su djeljivi iskljucivo sa samim sobom ili s 1. Zatim, ispisite sve proste brojeve manje od 100!
echo "Zadatak 1 - rješenje:<br />";

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
?>