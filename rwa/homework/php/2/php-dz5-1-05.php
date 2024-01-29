<?php
/*
	Leo Petrović - 2174/RR
*/

// Zadatak 5. - Napisite PHP funkciju unutar skripte za promjenu svih vrijednosti ulaznog polja na nacin da sve clanove polja promijeni u mala ili velika slova.
// Funkcija ima dva ulazna argumenta, ulazno polje i zeljeni oblik ispisa unesen kao niz (UPPER ILI LOWER). Na kraju skripte uraditi vise poziva funkcije.
// Primjer input polja:
// $boje = array('B' => 'Blue', 'G' => 'Green', 'r' => 'Red');
// Ocekivani izlaz:
// Vrijednosti u lowercase.
// Array ( [B] => blue [G] => green [r] => red ) 
// Vrijednosti u uppercase.
// Array ( [B] => BLUE [G] => GREEN [r] => RED )
echo "Zadatak 5 - rješenje:<br />";

function promijeni($polje, $oblik) {
	if ($oblik == "UPPER") {
		foreach ($polje as $key => $value) {
			$polje[$key] = strtoupper($value);
		}
	} elseif ($oblik == "LOWER") {
		foreach ($polje as $key => $value) {
			$polje[$key] = strtolower($value);
		}
	}
	return $polje;
}

$niz1 = array('B' => 'Blue', 'G' => 'Green', 'r' => 'Red');
$niz2 = array("Foo" => "bar", "Bar" => "foo", "FOO" => "BAR");

echo "<br />";
print_r($niz1);
echo "<br /><br />Vrijednosti u lowercase.<br />";
print_r(promijeni($niz1, "LOWER"));
echo "<br /><br />Vrijednosti u uppercase.<br />";
print_r(promijeni($niz1, "UPPER"));

echo "<br /><br /><br /><br />";

print_r($niz2);
echo "<br /><br />Vrijednosti u lowercase.<br />";
print_r(promijeni($niz2, "LOWER"));
echo "<br /><br />Vrijednosti u uppercase.<br />";
print_r(promijeni($niz2, "UPPER"));
?>