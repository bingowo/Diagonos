#include<stdio.h>
int main()
{
    int a[100000];
    int i=0;
    while((scanf("%d",a[i]))!=EOF);
    {
        printf("%d",a[i]);
        i++;
    }
}
