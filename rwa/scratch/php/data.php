<?php

session_start();

$todos = $_SESSION["todos"] ?? [];

function addTodo(string $title, string $description): void
{
	global $todos;
	$todos[] = [
		"title" => $title,
		"description" => $description,
		"completed" => false
	];

	$_SESSION["todos"] = $todos;
}

function removeTodoByIndex(int $index): void
{
	global $todos;
	array_splice($todos, $index, 1);

	$_SESSION["todos"] = $todos;
}

function toggleTodoByIndex(int $index): void
{
	global $todos;
	$todos[$index]["completed"] = !$todos[$index]["completed"];

	$_SESSION["todos"] = $todos;
}
