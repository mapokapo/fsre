<?php
/*
	Leo Petrović - 2174/RR
*/

// Zadatak 2. - Napisati php skriptu s pripadajucim PHP funkcijom koja ima dva ulazna argumenta (brojcane vrijednosti), Funkcija zatim ispisuje aritmeticku sredinu izmedju ta dva broja. Izvrsiti nekoliko poziva funkcije s proizvoljnim vrijednostima!
echo "Zadatak 2 - rješenje:<br />";

function sredina($a, $b) {
	return ($a + $b) / 2;
}

echo "Aritmetička sredina brojeva 1 i 5 je: " . sredina(1, 5) . ".<br />";
echo "Aritmetička sredina brojeva 3 i 10 je: " . sredina(3, 10) . ".<br />";
echo "Aritmetička sredina brojeva -5 i 5 je: " . sredina(-5, 5) . ".<br />";
echo "Aritmetička sredina brojeva 3 i 3 je: " . sredina(3, 3) . ".<br />";
echo "Aritmetička sredina brojeva 7 i 8 je: " . sredina(7, 8) . ".<br />";
?>