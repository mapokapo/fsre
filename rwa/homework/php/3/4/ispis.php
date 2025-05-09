<!DOCTYPE html>
<html lang="en">

<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Ispis</title>
</head>

<body>
	<h1>Odaberite opciju:</h1>

	<form action="ispis.php" method="get">
		<button type="submit" value="A" name="opcija">A</button>
		<button type="submit" value="B" name="opcija">B</button>
		<button type="submit" value="C" name="opcija">C</button>
	</form>

	<?php
	$opcija = $_GET['opcija'];

	if ($_SERVER['REQUEST_METHOD'] === 'GET') {
		if (empty($opcija)) {
			echo "<span>Niste odabrali nijedno dugme</span>";
		} else {
			echo "<span>Odabrali ste dugme " . $opcija . "</span>";
		}
	}
	?>
</body>

</html>