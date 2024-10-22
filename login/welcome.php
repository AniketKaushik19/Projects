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
    <div class="jumbotron container">
  <h1 class="display-3 text-bolder text-center m-3 my-3">Welcome to iprotect</h1>
  <!-- slider start  -->
  <div id="carouselExampleIndicators" class="carousel slide carousel-dark" data-bs-ride="carousel">
  <div class="carousel-indicators carousel-dark">
    <button type="button" data-bs-target="#carouselExampleIndicators" data-bs-slide-to="0" class="active" aria-current="true" aria-label="Slide 1"></button>
    <button type="button" data-bs-target="#carouselExampleIndicators" data-bs-slide-to="1" aria-label="Slide 2"></button>
    <button type="button" data-bs-target="#carouselExampleIndicators" data-bs-slide-to="2" aria-label="Slide 3"></button>
  </div>
  <div class="carousel-inner container my-5">
    <center><div class="carousel-item active">
      <img src="components/img/1.jpg"  width="720vw"  alt="...">
    </div>
    <div class="carousel-item">
      <img src="components/img/2.jpg" width="650vw"  alt="...">
    </div>
    <div class="carousel-item">
      <img src="components/img/3.jpg" width="720vw"  alt="...">
    </div>
  </div>
  <button class="carousel-control-prev" type="button" data-bs-target="#carouselExampleIndicators" data-bs-slide="prev">
    <span class="carousel-control-prev-icon" aria-hidden="true"></span>
    <span class="visually-hidden">Previous</span>
  </button>
  <button class="carousel-control-next" type="button" data-bs-target="#carouselExampleIndicators" data-bs-slide="next">
    <span class="carousel-control-next-icon" aria-hidden="true"></span>
    <span class="visually-hidden">Next</span>
  </button>
</div></center>
  <!-- slider end  -->
  <div class="container bg-warning">
  <h1 class="display-5 my-2">Top tips for staying safe in the digital world:</h1>
  <p class="lead">
    1. Know a Spam Email When You See One<br>
    2. Create Stronger Passwords<br>
    3. Use Two-Factor Authentication For Most Valuable Accounts<br>
    4. Update Your Devices and Computer Programs Frequently
  </p>
 
</div>

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
</body>
</html>

