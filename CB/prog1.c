#include <stdio.h>
int main()
{
int a[5],i,key;
printf("enter 5 elments: ");
for (i=0;i<5;i++)
scanf("%d", &a[i]);
printf("enter element to search:");
scanf("%d", &key);
for(i=0;i<5;i++){
	if (a[i]==key){
	printf("found element");
	return 0;
	}
	}
	printf("element not found ");
	return 0;
}
