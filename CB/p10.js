let a=document.getElementById("image");
function increase()
{
    a.width=400;
}
function decrease()
{
    a.width=200;
}
a.addEventListener("mouseover",increase);
a.addEventListener("mouseout",decrease);

