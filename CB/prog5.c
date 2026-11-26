#include <stdio.h>
int main()
{
int n,top= -1;
int choice,value,i;
printf("enter the size of stack:");
scanf("%d",&n);
int stack[n];
while(1)
{
printf("stack operations:");
printf("1.Push\n");
printf("2.Pop\n");
printf("3.Peek\n");
printf("4.Display\n");
printf("5.Exit\n");
printf("enter your choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:
if (top==n-1)
{
printf("stack overflow\n");
}
else
{
printf("enter value:\n");
scanf("%d",&value);
top++;
stack[top]=value;
printf("%d pushed into stack\n",value);
}
break;
case 2:
if (top==-1)
{
printf("stack underflow\n");
}
else
{
printf("%d Poped from stack\n",stack[top]);
top--;
break;
case 3:
if(top==-1)
{
printf("stack is empty\n");
}
else
{
printf("top element is %d \n" ,stack[top]);
}
break;
case 4:
if(top==-1)
{
printf("stack is empty\n");
}
else
{
printf("stack elements are:\n");
for(i=top;i>=0;i--)
{
printf("%d\n",stack[i]);
}
}
break;
case 5:
return 0;
default:
printf("invalid choice\n");
}
}
}
}


