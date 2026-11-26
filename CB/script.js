
function validate()
{
    let u = document.getElementById("uname").value;
    let e = document.getElementById("email").value;
    let p = document.getElementById("pass").value;
    let r = document.getElementById("cpass").value;
    let n = document.getElementById("phn").value;

    const emailexp = /^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{3,}$/;
    const mobexp = /^\d{10}$/;

    if (u == "" || e == "" || p == "" || r == "" || n == "")
    {
        alert("All fields are mandatory.");
        return false;
    }
    else if (!emailexp.test(e))
    {
        alert("Email format is invalid.");
        return false;
    }
    else if (p != r)
    {
        alert("Password and Confirm Password do not match.");
        return false;
    }
    else if (!mobexp.test(n))
    {
        alert("Phone number must contain 10 digits.");
        return false;
    }
    else
    {
        alert("Form submitted successfully!");
        return true;
    }
}
