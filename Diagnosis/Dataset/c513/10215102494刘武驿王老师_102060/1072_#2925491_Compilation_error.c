#include<stdio.h>
#include<string.h>
int main()
{
    long long int a,b;
    scanf("%lld %lld",&a,&b);
    long long int dis=(a>0)?a:-a+(b>0)b:-b;
    if(dis%2==0)
    {
        printf("-1");
        return 0;
    }
    
}