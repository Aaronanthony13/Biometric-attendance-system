nes (24 sloc) 774 Bytes 

<?php



foreach ($_REQUEST as $key => $value)

{

	if ($key == "SID") {

		$SID = $value;

	}

}



// EDIT: Your mysql database account information

$username = "root";

$password = "Anthony10c1997";

$database = "attendance";

$tablename = "elex_attendance";

$localhost = "127.0.0.1";



// Check Connection to Database

if (mysql_connect($localhost, $username, $password))

  {

  	@mysql_select_db($database) or die ("Unable to select database");



    // Next two lines will write into your table 'test_table_name_here' with 'yourdata' value from the arduino and will timestamp that data using 'now()'

    $query = "INSERT INTO $tablename VALUES ($SID,now())";

  	$result = mysql_query($query);

  } else {

  	echo('Unable to connect to database.');

  }



?>