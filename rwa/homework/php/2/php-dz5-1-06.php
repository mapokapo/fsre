<?php
/*
	Leo Petrović - 2174/RR
*/

// Zadatak 6. - Napisite PHP skriptu s funkcijom za izracun i prikaz prosjecne temperature, deset najnižih, te deset najvisih temperatura. Funkcija ima samo jedan ulazni argument, niz temparature (niz/string, vrijednosti odvojene zarezom) – primjer niza temperature:
// $temparature = "78, 60, 62, 68, 71, 68, 73, 85, 66, 64, 76, 63, 81, 76, 73, 68, 72, 73, 75, 65, 74, 63, 67, 65, 64, 68, 73, 75, 79, 73";
echo "Zadatak 6 - rješenje:<br />";

function prosjek($niz) {
	$zbroj = 0;

	foreach ($niz as $broj) {
		$zbroj += $broj;
	}

	return $zbroj / count($niz);
}

function najnize($niz) {
	$najnize = $niz[0];

	foreach ($niz as $broj) {
		if ($broj < $najnize) {
			$najnize = $broj;
		}
	}

	return $najnize;
}

function najvise($niz) {
	$najvise = $niz[0];

	foreach ($niz as $broj) {
		if ($broj > $najvise) {
			$najvise = $broj;
		}
	}

	return $najvise;
}

function ispisi($niz) {
	$niz = array_map("intval", explode(",", $niz));

	echo "Prosječna temperatura je: " . prosjek($niz) . ".<br />";
	echo "Najniža temperatura je: " . najnize($niz) . ".<br />";
	echo "Najviša temperatura je: " . najvise($niz) . ".<br /><br />";
}

ispisi("78, 60, 62, 68, 71, 68, 73, 85, 66, 64, 76, 63, 81, 76, 73, 68, 72, 73, 75, 65, 74, 63, 67, 65, 64, 68, 73, 75, 79, 73");
ispisi("1, 2, 3, 4, 5, 6, 7, 8, 9, 10");
ispisi("10, 9, 8, 7, 6, 5, 4, 3, 2, 1");
ispisi("1, 1, 1, 1, 1, 1, 1, 1, 1, 1");
ispisi("1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 100");
?>