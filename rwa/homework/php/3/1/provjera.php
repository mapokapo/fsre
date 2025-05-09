<!DOCTYPE html>
<html lang="en">

<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Provjera</title>
</head>

<body>
	<?php
	$ime = $_POST['ime'];
	$lozinka = $_POST['lozinka'];

	function CheckPwd($lozinka)
	{
		if (strlen($lozinka) < 6) {
			return false;
		}

		if (!preg_match("#[0-9]+#", $lozinka)) {
			return false;
		}

		if (!preg_match("#[a-zA-Z]+#", $lozinka)) {
			return false;
		}

		return true;
	}

	if ($_SERVER['REQUEST_METHOD'] === 'POST' && !empty($ime) && !empty($lozinka)) {
		echo "Korisničko ime je " . $ime . " a lozinka je <strong>" . $lozinka . "</strong> i <strong>" . (CheckPwd($lozinka) ? "valjana je" : "nije valjana") . "</strong>. <br /><hr />";
	}
	?>
	<form action="provjera.php" method="post" style="display: flex; flex-direction: column; align-items: start;">
		<label for="ime">
			Korisničko ime
			<input type="text" name="ime" id="ime">
		</label>
		<label for="lozinka">
			Lozinka
			<input type="password" name="lozinka" id="lozinka">
		</label>
		<button type="submit">Pošalji</button>
	</form>
</body>

</html>