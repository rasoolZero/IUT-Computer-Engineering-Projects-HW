<?php
define("DB_HOST", "localhost");
define("DB_NAME", "sqli");
define("DB_CHARSET", "utf8mb4");
define("DB_USER", "root");
define("DB_PASSWORD", "");
 
$pdo = new PDO(
  "mysql:host=".DB_HOST.";dbname=".DB_NAME.";charset=".DB_CHARSET, 
  DB_USER, DB_PASSWORD, [
  PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION,
  PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_ASSOC
]);
 
$stmt = $pdo->prepare($sql);
$stmt->execute($data);
// $stmt->debugDumpParams();
$results = $stmt->fetchAll();

echo "<code class='sql'>$sql</code>";
if (count($results)==0) { echo "<div class='row'>No results</div>"; }
else { 
  printf("<div class='row'>
            <div class='data show'>%s</div> 
            <div class='data'>%s</div> 
            <div class='data price'>%s</div> 
          </div>", 'show','name','price');
  foreach($results as $r) {
  printf("<div class='row'>
            <div class='data show'>%u</div> 
            <div class='data'>%s</div> 
            <div class='data price'>%.2f</div> 
          </div>", $r["show"], $r["name"], $r["price"]);
}}
?>