<?php

require_once 'data.php';

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
	$index = $_POST['index'];

	// Remove todo by index
	removeTodoByIndex(
		$index
	);

	// Redirect to the list of todos
	header('Location: index.php');
	exit;
}
