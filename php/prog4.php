
<!DOCTYPE html>
<html>
<head>
    <title>Electricity Bill Calculator</title>
</head>
<body>

<h2>Electricity Bill Calculator</h2>

<form method="post">
    Enter Units Consumed:
    <input type="number" name="units" required min="0">
    <input type="submit" name="submit" value="Calculate Bill">
</form>

<?php
if(isset($_POST['submit']))
{
    $units = (int)$_POST['units'];
    $bill = 0;

    if($units <= 50)
    {
        $bill = $units * 1.5;
    }
    else if($units <= 100)
    {
        $bill = (50 * 1.5) +
                (($units - 50) * 2.5);
    }
    else if($units <= 150)
    {
        $bill = (50 * 1.5) +
                (50 * 2.5) +
                (($units - 100) * 3.5);
    }
    else
    {
        $bill = (50 * 1.5) +
                (50 * 2.5) +
                (50 * 3.5) +
                (($units - 150) * 5);
    }

    echo "<h3>Electricity Bill Details</h3>";
    echo "Units Consumed: " . $units . "<br>";
    echo "Total Electricity Bill: Rs. " .
         number_format($bill, 2);
}
?>

</body>
</html>
