<?php 
session_start();
if(!isset($_SESSION['loggedin'])||$_SESSION['loggedin']!=true){
 header('location:login.php');
 exit;
}
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    require "components/db_con.php";
    $email = $_POST["email"];
    $password = $_POST["password"];
    $comment=$_POST['comment'];
    $hash = password_hash($password, PASSWORD_DEFAULT);
    $insert = mysqli_query($con, "INSERT INTO `library`.`contact` ( `email`, `password`,`comment`, `dt`) VALUES ( '$email', '$hash','$comment', current_timestamp());");
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>iprotect</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
</head>
<body>
    <?php  require "components/navbar.php"?>
    <center>
    <div class="m-5">
      <h1>Contact us</h1>
      <form   method="POST" action="contact.php" >
     <div class="mb-3">
    <label for="email" class="form-label">Email address</label>
    <input type="email"  name="email" class="form-control" id="email" aria-describedby="emailHelp">
    <div id="emailHelp" class="form-text">We'll never share your email with anyone else.</div>
  </div>
  <div class="mb-3">
    <label for="" class="form-label">Password</label>
    <input type="password" name="password" class="form-control" id="password">
    <div id="emailHelp" class="form-text">Your password is secure with us</div>
  </div>
  </div>
  <div class="form-floating">
      <textarea class="form-control" id="comment" name="comment" placeholder="Leave a comment here" id="floatingTextarea2" style="height: 100px"></textarea>
      <label for="floatingTextarea2">Comments</label>
    </div>
    <button type="submit" class="btn btn-primary my-3">Submit</button>
</form>
    </div>
   </center>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
</body>
</html>