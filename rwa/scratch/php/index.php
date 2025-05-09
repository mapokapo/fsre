<?php

// Top-level data (primitive database)
require_once "data.php";

$title = "Home";
include_once "templates/header.php";

// Template and template-specific variables
include_once "templates/pages/home.php";

include_once "templates/footer.php";
