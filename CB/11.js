function calculate() {
    let form1 = document.getElementById("f1");
    let score = 0; 

    if (form1.q1.value == "Paris")
        score++;

    if (form1.q2.value == "Mars")
        score++;

    if (form1.q3.value == "H2O")
        score++;

    if (form1.q4.value == "William Shakespeare")
        score++;

    if (form1.q5.value == "Blue Whale")
        score++;

    if (form1.q6.value == "CSS")
        score++;

    if (form1.q7.value == "7")
        score++;

    if (form1.q8.value == "100")
        score++;

    if (form1.q9.value == "Carbon Dioxide")
        score++;

    if (form1.q10.value == "Mitochondria")
        score++;

    alert("congrats you have scored " + score);
    form1.reset();
}