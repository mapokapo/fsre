<?php

function izvrsiOperaciju($broj, $operacija)
{
	switch ($operacija) {
		case 'KVADRAT':
			return $broj * $broj;
		case 'KUB':
			return $broj * $broj * $broj;
		default:
			return "Nepoznata operacija";
	}
}

if ($_SERVER['REQUEST_METHOD'] === 'GET') {
	$broj = isset($_GET['broj']) ? $_GET['broj'] : null;
	$operacija = isset($_GET['operacija']) ? $_GET['operacija'] : null;

	echo "<div style=\"display: flex; flex-direction: column; gap: 1rem;\">";
	if (empty($broj) || empty($operacija)) {
		echo "<span>Molim unesite broj ili operaciju</span>";
	} else {
		echo "<span>Poslali ste broj: <strong>" . $broj . "</strong></span>";
		echo "<span>Operacija je: <strong>" . $operacija . "</strong></span>";
		echo "<span>Rezultat je: <strong>" . izvrsiOperaciju($broj, $operacija) . "</strong></span>";
	}
	echo "</div>";
}
