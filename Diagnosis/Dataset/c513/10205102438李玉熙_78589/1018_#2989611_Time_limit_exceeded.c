#include<stdio.h>
int main()
{
    int a[20]={2,3,5,7,11,13,17,19,23,29,31,37,39,41,43,47,51,53,59,61};
    int num[25];
    long long sum=0,j=0;long long base=1;
    int i=0;
    while(scanf("%d",&a[i])!=EOF)i++;
    int len=i;
    for(i=len-1;i>=0;i--)
    {
        sum=base*num[i]+sum;
        base=base*a[j];
        j++;
    }
    printf("%lld",sum);
}