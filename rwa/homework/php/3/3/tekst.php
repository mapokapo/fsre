<?php

if ($_SERVER['REQUEST_METHOD'] === 'GET') {
	$tekst = isset($_GET['tekst']) ? $_GET['tekst'] : null;
	$broj = isset($_GET['broj']) ? $_GET['broj'] : null;

	echo "<div style=\"display: inline-block; padding: 0.5rem 2rem 0.5rem 1rem; border: 1px solid black;\">";
	echo "<h1>ISPIS</h1>";
	echo "<ol style=\"padding-left: inherit;\">";
	for ($i = 0; $i < intval($broj); $i++) {
		echo "<li>" . $tekst . "</li>";
	}
	echo "</ol>";
	echo "</div>";
}
