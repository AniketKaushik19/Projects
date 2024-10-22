<?php

if(isset($_SESSION['loggedin']) && $_SESSION['loggedin']==true){
  $loggedin=true;
}
else{
  $loggedin=false;
}
echo '<nav class="navbar navbar-expand-lg navbar-dark bg-dark">
<div class="container-fluid">
  <a class="navbar-brand" href="welcome.php">iprotect</a>
  <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
    <span class="navbar-toggler-icon"></span>
  </button>
  <div class="collapse navbar-collapse" id="navbarSupportedContent">
  ';
  if($loggedin){
    echo'
  <ul class="navbar-nav me-auto mb-2 mb-lg-0">
    <li class="nav-item">
        <a class="nav-link active " aria-current="page" href="welcome.php">Home</a>
      </li>
      <li class="nav-item">
        <a class="nav-link active" aria-current="page" href="contact.php">Contact</a>
      </li>
      <li class="nav-item">
        <a class="nav-link active" aria-current="page" href="about.php">About us</a>
      </li>
    </ul>
    <form class="d-flex">';
      echo'<input class="form-control me-2" type="search" placeholder="Search" aria-label="Search">
      <button class="btn btn-success mx-2" type="submit">Search</button>
      <div class="text-light mx-2 my-2">'.$_SESSION['username'].'</div>';
      echo '<button class="btn btn-outline-success mx-2" type="submit"><a class="link-light text-decoration-none" href="logout.php">logout</a></button>';}
       
      if(!$loggedin){
      echo '<button class="btn end-0 btn-outline-success mx-2" type="submit"><a class="link-light text-decoration-none" href="sign.php">Sign</a></button>
      <button class="btn btn-outline-success mx-2" type="submit"><a  class="link-light text-decoration-none" href="login.php">login</a></button>';}
    echo'</form>
  </div>
</div>
  </nav>';
?>