<?php 
$server="localhost";
$username="root";
$password="";
$database="library";
$con=mysqli_connect($server,$username,$password);
if (!$con){
    die("not connect to database");
}
// echo "connected to the database";
?>