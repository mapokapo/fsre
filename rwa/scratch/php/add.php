<?php

require_once 'data.php';

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
	$title = $_POST['title'];
	$description = $_POST['description'];

	// Add new todo to the list
	addTodo(
		$title,
		$description
	);

	// Redirect to the list of todos
	header('Location: index.php');
	exit;
}
