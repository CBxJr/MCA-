#include<stdio.h>
int main()
{
int a[20],n,i,j,temp;
printf("Enter the number of elements:\n");
scanf("%d",&n);
printf("Enter the Elements:\n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<n;i++){
for(j=i+1;j<n;j++){
if (a[i]<a[j]){
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
}
printf("The largest element is %d\n",a[0]);
printf("The smallest element is %d\n",a[n-1]);
return 0;
}

