<?php
$showalt = false;
$showerr = false;
$showalready=false;

if ($_SERVER["REQUEST_METHOD"] == "POST") {
  require "components/db_con.php";
  $username = $_POST["username"];
  $password = $_POST["password"];
  $mpassword = $_POST["mpassword"];
  $new = mysqli_query($con, "SELECT * FROM `library`.`logineds` WHERE username='$username';");
  if(mysqli_num_rows($new)==1){
    $showalready=true;
  }else{
  if ($password == $mpassword) {
    $hash = password_hash($password, PASSWORD_DEFAULT);
    $insert = mysqli_query($con, "INSERT INTO `library`.`logineds` ( `username`, `password`, `datetime`) VALUES ( '$username', '$hash', current_timestamp());");
    if ($insert) {
      $showalt = true;
    }
    //  for testing else {
    //   $showerr = true;
    // }

  } else {
    $showerr = true;
  }
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
  <?php //error strnatcasecmp
  if ($showalt) {
    echo '<div class="alert alert-success alert-dismissible fade show" role="alert">
        <strong>congratulation!</strong> Account created successful!!
        <button type="button" class="btn-close" data-bs-dismiss="alert" aria-label="Close"></button>
      </div>';
      // header("location:logined.php");
  }
  if ($showerr) {
    echo '<div class="alert alert-danger alert-dismissible fade show" role="alert">
        <strong>Warning!</strong> Please enter valid Username and password
        <button type="button" class="btn-close" data-bs-dismiss="alert" aria-label="Close"></button>
      </div>';
  }
  if ($showalready){
    echo '<div class="alert alert-danger alert-dismissible fade show" role="alert">
        <strong>Warning!</strong> Username already exist.
        <button type="button" class="btn-close" data-bs-dismiss="alert" aria-label="Close"></button>
      </div>';
  }
  ?>
  <!-- nav bar start -->
  <?php require "components/navbar.php" ?>
  <!-- nav bar end  -->
  <!-- main content start  -->
  <center>
  <div class="container m-5">
    <h1>Welcome to Sign in page</h1>
    <form method="POST" action="sign.php">
      <div class="mb-3 mx-5 col-md-4">
        <label for="exampleInputEmail1" class="form-label ">Username</label>
        <input type="text" class="form-control border-success" id="username" name="username" aria-describedby="emailHelp">
        <div id="emailHelp" class="form-text">Unique username with symbols</div>
      </div>
      <div class="mb-3 mx-5 col-md-4">
        <label for="exampleInputPassword1" class="form-label">Password</label>
        <input type="password" class="form-control border-success" id="password" name="password" aria-describedby="passwordHelp">
        <div id="passwordHelp" class="form-text">Strong password with special character</div>
      </div>
      <div class="mb-3 mx-5 col-md-4">
        <label for="exampleInputPassword1" class="form-label">Confirm Password</label>
        <input type="password" class="form-control border-success" id="mpassword" name="mpassword" aria-describedby="passwordHelp">
        <div id="passwordHelp" class="form-text">Re-enter the password</div>
      </div>
      <button type="submit" class="btn btn-primary">Create/sign</button>
    </form>
  </div>
  </center>
  <!-- main content end  -->

  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
</body>

</html>