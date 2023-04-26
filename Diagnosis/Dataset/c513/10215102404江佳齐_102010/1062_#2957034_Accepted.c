#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long int f(int n)
{
    if(n==1) return 1;
    if(n==2) return 2;
    if(n==3) return 4;
    if(n==4) return 8;
    long long int one=1,two=2,three=4,four=8;
    long long int sum;
    for(int i=5;i<=n;i++)
    {
        sum=one+two+three+four;
        one=two;two=three;three=four;four=sum;
    }
    return sum;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n;
        long long int sum;
        scanf("%d",&n);
        sum=f(n);
        printf("case #%d:\n",i);
        printf("%lld\n",sum);
    }
    return 0;
}
