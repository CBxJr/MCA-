
<html>
<body>
    <form method="post" action="">
        Enter the student names:
        <textarea name="slist" rows="10" cols="20"></textarea>
        <input type="submit" name="sub" value="Submit">
    </form>
</body>
</html>

<?php
if(isset($_POST["sub"]))
{
    $students = explode("\n", $_POST["slist"]);

    echo "<h3>Student Names:</h3>";
    foreach($students as $name)
    {
        echo htmlspecialchars(trim($name)) . "<br>";
    }

    echo "<h3>Ascending Order:</h3>";
    asort($students);
    foreach($students as $name)
    {
        echo htmlspecialchars(trim($name)) . "<br>";
    }

    echo "<h3>Descending Order:</h3>";
    arsort($students);
    foreach($students as $name)
    {
        echo htmlspecialchars(trim($name)) . "<br>";
    }
}
?>
