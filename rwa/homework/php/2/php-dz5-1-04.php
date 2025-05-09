<?php
/*
	Leo Petrović - 2174/RR
*/

// Zadatak 4. - Napisati PHP/HTML program koji generira sljedeci ispis unutar preglednika putem PHP koda. PHP kod racuna faktorijel za svaki broj do broja koji unesemo kao argument funkcije. Program mora imati sljedecu strukturu – prvo definirati funkciju za faktorijel koja radi ispis kao u prozoru ispod (izvrsiti nekoliko poziva funkcije s proizvoljnim vrijednostima! – ovo je npr. poziv funkcije za 9 koji je predan kao argument funkcije).
echo "Zadatak 4 - rješenje:<br />";

function faktorijel($broj) {
	if ($broj <= 1) {
		echo "<br />1! = 1<br />";
		return 1;
	} else {
		$rezultat =  $broj * faktorijel($broj - 1);
		echo $broj . "! = " . $rezultat . "<br />";
		return $rezultat;
	}
}

faktorijel(9);
faktorijel(5);
faktorijel(10);
?>