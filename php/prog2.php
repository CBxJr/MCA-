<html>
<body>
<form method="post">
Enter Electricity Units: <input type="number" name="units">
<input type="submit" name="submit" value="Calculate">
</form>
<?php
if(isset($_POST['submit'])) {
$u=$_POST['units']; $b=($u<=50)?$u*1.5:(($u<=100)?$u*2.5:(($u<=150)?$u*3.5:$u*5));
echo "Electricity Units: $u<br>Total Bill: Rs. $b";
}
?>
</body>
</html>