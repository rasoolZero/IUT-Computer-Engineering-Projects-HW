<!DOCTYPE html>
<html>
  <head>
    <title>NetSec SQLi Homework</title>
    <meta charset="utf-8">
    <link rel="stylesheet" href="style.css">
  </head>
  <body>
    <center>
      <h1>CRYSTAL CRAFTERS</h1>
    <form method="post">
      <p><code>" OR 1=1 OR `name` LIKE "</code> no longer works.</p>
      <input type="text" name="search">
      <input type="submit" value="Search">
    </form>

    <div id="results"><?php
      if (isset($_POST["search"])) {
        $sql = "SELECT * FROM `products` WHERE `show`=1 AND `name` LIKE ?";
        $data = ["%".$_POST["search"]."%"];
        require "database.php";
      }
    ?></div>
    </center>
  </body>
</html>