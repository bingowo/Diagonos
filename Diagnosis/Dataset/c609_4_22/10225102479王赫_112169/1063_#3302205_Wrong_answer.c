#include <stdio.h>
#include <stdlib.h>

long long int f(int n)
{
    if(n==1) return 1;
    if(n==2) return 2;
    if(n==3) return 4;
    if(n==4) return 8;
    long long int sum;
    long long int one=1,two=2,three=4,four=8;
    for(int i=5; i<=n; i++)
    {
        sum=one+two+three+four;
        one=two,two=three,three=four,four=sum;
    }
    return sum;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0; i<T; i++)
    {
        int n,func;
        scanf("%d",&n);
        func=f(n);
        printf("case #%d:\n",i);
        printf("%lld\n",func);
    }
    return 0;
}
