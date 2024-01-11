<main class="w-full h-full p-12 flex">
	<div class="flex flex-col flex-1 items-center p-8">
		<h1 class="text-3xl font-bold mb-4">Todo App!</h1>
		<?php if (count($todos) === 0) : ?>
			<p class="text-xl">You have no todos!</p>
		<?php else : ?>
			<ul class="w-full gap-4 flex flex-col">
				<?php for ($i = 0; $i < count($todos); $i++) : ?>
					<?php $todo = $todos[$i]; ?>
					<li class="flex w-full gap-4 items-center bg-gray-200 p-2 rounded-md">
						<form action="toggle.php" method="POST">
							<input type="hidden" name="index" value="<?php echo $i; ?>" />
							<button type="submit" class="bg-green-500 text-white rounded-md p-2">Toggle</button>
						</form>
						<div class="flex flex-col">
							<h2 class="text-xl font-bold <?php echo $todo["completed"] ? "line-through text-gray-700" : "" ?>">
								<?php echo $todo["title"]; ?>
							</h2>
							<p>
								<?php echo $todo["description"]; ?>
							</p>
						</div>
						<form action="remove.php" method="POST" class="ml-auto">
							<input type="hidden" name="index" value="<?php echo $i; ?>" />
							<button type="submit" class="bg-red-500 text-white rounded-md p-2">Remove</button>
						</form>
					</li>
				<?php endfor; ?>
			</ul>
		<?php endif; ?>
	</div>

	<form action="add.php" method="POST" class="flex flex-col justify-center flex-1 items-center bg-gray-200 p-4 rounded-md">
		<h1 class="text-3xl font-bold mb-4">
			Add Todo
		</h1>
		<label for="title" class="text-xl">Title</label>
		<input type="text" name="title" id="title" class="w-full border border-gray-800 rounded-md p-2 mb-4" />
		<label for="description" class="text-xl">Description</label>
		<textarea name="description" id="description" rows="5" class="w-full border border-gray-800 rounded-md p-2 mb-4"></textarea>
		<button type="submit" class="w-full p-4 mb-4 bg-blue-500 text-white rounded-md">Add Todo</button>
	</form>
</main>