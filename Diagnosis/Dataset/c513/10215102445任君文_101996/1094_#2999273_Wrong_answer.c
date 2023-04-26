#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i;
    int n;
    long long a=0,b=0;
    long long MAX=0,MIN=0;
    scanf("%d",&n);
    scanf("%lld",&MIN);
    MAX=MIN;
    for(i=0;i<n-1;i++)
    {
        scanf("lld",&a);
        if(a>MAX)
        {
            MAX=a;
        }
        else if(MIN>a)
        {
            MIN=a;
        }
    }
    printf("%lld\n",MAX-MIN);
    return 0;
}