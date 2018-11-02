<?php

$data = $_GET['SID'];
$data1 = $_GET['TID'];

//Validate Your Data => if it is invalid => die();


// TODO
$servername = "127.0.0.1";
$username = "root";
$password = "Anthony10c1997";
$dbname = "attendance";


// Create connection to mysql server
$conn = new mysqli($servername, $username, $password, $dbname);


// Check connection
if ($conn->connect_error) 
    die("Connection failed: " . $conn->connect_error);


$sql = "INSERT INTO elex_attendance (SID,TID) values ($data,$data1)";

if ($conn->query($sql) === TRUE) {
    echo "New record created successfully";
} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}

$conn->close();

?>