
<!DOCTYPE html>
<html>
<body>

<h2>Indian Cricket Players</h2>

<form method="POST">
    <label>Enter Player Names:</label><br><br>

    <textarea name="players" rows="6" cols="30"
    placeholder="Enter player names&#10;One name per line" required></textarea>

    <br><br>
    <input type="submit" name="submit" value="Display Players">
</form>

<?php

if (isset($_POST['submit'])) {

    $players = explode("\n", $_POST['players']);

    echo "<h3>Player List</h3>";

    echo "<table border='1' cellpadding='8'>";
    echo "<tr><th>Sl.No</th><th>Player Name</th></tr>";

    $i = 1;

    foreach ($players as $name) {

        $name = trim($name);

        if ($name != "") {
            echo "<tr>";
            echo "<td>$i</td>";
            echo "<td>" . htmlspecialchars($name) . "</td>";
            echo "</tr>";

            $i++;
        }
    }

    echo "</table>";
}

?>

</body>
</html>
