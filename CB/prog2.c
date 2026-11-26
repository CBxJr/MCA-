#include <stdio.h>
int main()
{
    int a[10], n, temp, i, j;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(i = 0; i < n-1; i++)
        for(j = i+1; j < n; j++)
            if(a[i] < a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
    printf("Third largest element = %d\n", a[2]);
    return 0;
}
