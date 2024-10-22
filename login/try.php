<?php 
    $name=$_REQUEST['de'];
    $con=mysqli_connect('localhost','root','','try');
    $q=mysqli_query($con,"INSERT INTO d(`name`, `date`) VALUES ('$name',current_timestamp());");
    if($q){
        echo("successfully inserted");
    }
    else{
        echo("not inserted");
    }
?>