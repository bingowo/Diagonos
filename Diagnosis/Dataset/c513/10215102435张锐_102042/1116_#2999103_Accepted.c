#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int a,b;
    scanf("%lld%lld",&a,&b);
    if(a<0) a=-a;
    if(b<0) b=-b;
    long long int sum=a+b,temp=1;int i=0;
    if(sum%2==0&&sum!=0) i=-1;
    for(;i>=0;i++)
    {
        if(sum<=temp) break;
        temp*=2;
    }
    printf("%d",i);
    return 0;
}
