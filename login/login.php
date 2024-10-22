<?php
$login=false;
$showerr = false;
if ($_SERVER["REQUEST_METHOD"] == "POST") {
  require "components/db_con.php";
  $username = $_POST["username"];
  $password = $_POST["password"];
  $insert = mysqli_query($con, "SELECT * FROM `library`.`logineds` WHERE username='$username';");
  $num = mysqli_num_rows($insert);

  if ($num == 1) {
    while ($row = mysqli_fetch_assoc($insert)) {
      if (password_verify($password, $row['password'])) {
        $login=true;
        session_start();
        $_SESSION['username']=$row['username'];
        $_SESSION["loggedin"]=true;
        header('location:welcome.php');
        } 
      else {
          $showerr = true;
        }
      }
   }
  else{
    $showerr=true;
  }  
}
?>
<!doctype html>
<html lang="en">

<head>
  <!-- Required meta tags -->
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">

  <!-- Bootstrap CSS -->
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">

  <title>iprotect</title>
</head>

<body>
  <?php require "components/db_con.php";
  if ($showerr) {
    echo '<div class="alert alert-danger alert-dismissible fade show" role="alert">
        <strong>Warning!</strong> Login failed enter correct details!!
        <button type="button" class="btn-close" data-bs-dismiss="alert" aria-label="Close"></button>
      </div>';
  }
  // if ($sign) {
  //   echo '<div class="alert alert-danger alert-dismissible fade show" role="alert">
  //       <strong>Warning!</strong> Login failed enter correct details!!
  //       <button type="button" class="btn-close" data-bs-dismiss="alert" aria-label="Close"></button>
  //     </div>';
  // }
  
  ?>
  <!-- nav bar start -->
  <?php require "components/navbar.php" ?>
  <!-- nav bar end  -->
  <!-- main content start  -->
  <center>
  <div class="container m-5">
    <h1 >Welcome to Login page</h1>
    <form method="POST" action="login.php">
      <div class="mb-3 mx-5 col-md-4">
        <label for="exampleInputEmail1" class="form-label ">Username</label>
        <input type="text" class="form-control  border-success" id="username" name="username" aria-describedby="emailHelp">
        <div id="emailHelp" class="form-text">Unique username with symbols</div>
      </div>
      <div class="mb-3 mx-5 col-md-4">
        <label for="exampleInputPassword1" class="form-label">Password</label>
        <input type="password" class="form-control border-success" id="password" name="password" aria-describedby="passwordHelp" required>
        <div id="passwordHelp" class="form-text">Strong password with special character</div>
      </div>
      <button type="submit" class="btn mx-5 btn-primary">login</button>
    </form>
  </div>
  </center>
  <!-- main content end  -->
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
</body>

</html>