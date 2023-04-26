#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
unsigned long long int a[32];
int main()
{
    int t,n;
    scanf("%d",&t);
    a[0]=1;
    for(int i=1;i<31;i++)
        a[i]=a[i-1]*2;
    for(int i=0; i<t; i++)
    {
        scanf("%d",&n);
        printf("case #%d:\n",i);
        printf("%llu\n",a[n]);
    }
}
