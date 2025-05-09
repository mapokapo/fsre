<?php

require_once 'data.php';

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
	$index = $_POST['index'];

	// Toggle todo by index
	toggleTodoByIndex(
		$index
	);

	// Redirect to the list of todos
	header('Location: index.php');
	exit;
}
