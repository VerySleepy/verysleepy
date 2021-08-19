<?php

define(EMAIL, 'sleepy-crashback@thecybershadow.net');

// NB: make sure the current directory does not have indexes enabled.

// Error handling / strict mode bootstrap
error_reporting(-1);
function error_handler($errno, $errstr, $errfile, $errline) { throw new ErrorException($errstr, $errno, 1, $errfile, $errline); }
set_error_handler('error_handler');
function error($message = 'An error occurred') { throw new Exception($message); }
function enforce($condition, $message = 'Enforcement failed') { if (!$condition) error($message); return $condition; }
enforce(!get_magic_quotes_gpc(), "Magic quotes are on!");

$count = $_REQUEST['count'];
$dir = uniqid('', true) . '-' . urlencode($_REQUEST['program']);
mkdir($dir, 0700, true);

$filelist = "";

foreach ($_FILES as $name => $file)
	if ($file["error"] == UPLOAD_ERR_OK)
	{
		$tmp_name = $file["tmp_name"];
		$filename = $file["name"];
		$filename = basename($filename);
		move_uploaded_file($tmp_name, "$dir/$filename");
		$filelist .= $url = "http://" . $_SERVER['HTTP_HOST'] . dirname($_SERVER['REQUEST_URI']) . "/$dir/$filename\n";
	}


mail(EMAIL, 'Sleepy Crashback', $filelist);
