#include<stdio.h>
#define M 100
int main()
{
    int n,i;
    long num[M]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%ld",&num[i]);
    }
    return 0;
}