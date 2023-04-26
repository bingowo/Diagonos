#include<stdio.h>
int main()
{
    int a[100000],n;
    int i=0;
    while((scanf("%d",&n))!=EOF);
    {
        a[i]=n;
        printf("%d",a[i]);
        i++;
    }
}
