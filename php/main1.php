
<html>
    <body>
        <h1>Reg form</h1>
        <form method="post" action=""><br><br>

            Username:
            <input type="text" name="uname"><br><br>

            Email:
            <input type="text" name="email"><br><br>

            Password:
            <input type="password" name="pass"><br><br>

            Confirm Password:
            <input type="password" name="cpass"><br><br>

            Mobile No:
            <input type="text" name="mob"><br><br>

            <input type="submit" name="sub">
        </form>
    </body>
</html>

<?php

if (isset($_POST["sub"]))
{
    $uname = trim($_POST["uname"]);
    $email = trim($_POST["email"]);
    $mob = trim($_POST["mob"]);
    $pass = trim($_POST["pass"]);
    $cpass = trim($_POST["cpass"]);

    $unameexp = "/^[a-zA-Z0-9_]{3,}$/";
    $emailexp = "/^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{3,}$/";
    $mobexp = "/^\d{10}$/";
    $cpass = "/^(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.*[@#$%^&+=!]).{8,}$/";
    $pass = "/^(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.*[@#$%^&+=!]).{8,}$/";

    $errors = array();

    if ($uname == "" || $email == "" || $mob == "" || $pass=="")
    {
        $errors[] = "all fields are mandatory";
    }

    if (!preg_match($unameexp, $uname))
        $errors["uname"] = "username is incorrect";

    if (!preg_match($emailexp, $email))
        $errors["email"] = "email is incorrect";

    if (!preg_match($mobexp, $mob))
        $errors["mob"] = "mobile number is incorrect";

    if (!preg_match("/^.{8,}$/", $pass))
    $errors["pass"] = "Password must be at least 8 characters";

    if (!empty($errors))
    {
        foreach ($errors as $e)
            echo "<li>$e</li>";
    }
    else
    {
        echo "registered successfully !!!";
    }
}

?>
