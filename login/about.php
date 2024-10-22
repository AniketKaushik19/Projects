<?php 
session_start();
if(!isset($_SESSION['loggedin'])||$_SESSION['loggedin']!=true){
 header('location:login.php');
 exit;
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
    <title>iprotect</title>
</head>
<body>
<?php require "components/navbar.php";?>
<figure class="text-center my-2">
  <blockquote class="blockquote">
    <p>Lets protect the world</p>
  </blockquote>
  <figcaption class="blockquote-footer">
    by <cite title="Source Title">iprotect </cite>
  </figcaption>
</figure> 
<div class="jumbotron jumbotron-fluid">
  <div class="container bg-secondary">
    <h1 class="display-4">About us</h1>
    <p class="lead">This is a initiative program to give information about security and provide a better security than other.</p>
  </div>
</div>
<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
</body>
</html>