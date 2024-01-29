<!DOCTYPE html>
<html lang="en">

<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Kalkulator</title>
</head>

<body>
	<h1>Kalkulator</h1>

	<form action="kalkulator.php" method="get" style="display: flex; gap: 2rem; flex-wrap: wrap;">
		<label for="a">
			A broj
			<input type="number" name="a" id="a">
		</label>
		<label for="operacija">
			Operacija
			<select name="operacija" id="operacija">
				<option value="+" selected>+</option>
				<option value="-">-</option>
				<option value="*">*</option>
				<option value="/">/</option>
			</select>
		</label>
		<label for="b">
			B broj
			<input type="number" name="b" id="b">
		</label>
		<button type="submit">Rezultat</button>
	</form>

	<?php
	function Operacija($a, $b, $op)
	{
		if (!empty($a) && !empty($b) && !empty($op)) {
			echo "<br /><hr />Rezultat je: ";
			switch ($op) {
				case '+':
					echo $a + $b;
					break;
				case '-':
					echo $a - $b;
					break;
				case '*':
					echo $a * $b;
					break;
				case '/':
					if ($b == 0) {
						echo "Nije moguće dijeliti s nulom";
						break;
					}
					echo $a / $b;
					break;
				default:
					return false;
			}
			echo "<br /><hr />";
		} else {
			return false;
		}
	}

	if ($_SERVER['REQUEST_METHOD'] === 'GET') {

		$a = isset($_GET['a']) ? $_GET['a'] : null;
		$b = isset($_GET['b']) ? $_GET['b'] : null;
		$operacija = isset($_GET['operacija']) ? $_GET['operacija'] : null;

		if (!empty($a) && !empty($b) && !empty($operacija)) {
			Operacija($a, $b, $operacija);
		}
	}
	?>
</body>

</html>