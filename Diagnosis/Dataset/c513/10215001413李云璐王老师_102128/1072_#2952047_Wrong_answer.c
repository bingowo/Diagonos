#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

long long int q(long long int x,long long int y)
{
    long long int a;
    a=fabs(x)+fabs(y);
    return a;
}
int main()
{
    long long int x,y,bu;
    scanf("%lld%lld",&x,&y);
    if(q(x,y)%2==0) printf("-1");
    else 
    {
        for(int i=0;i<64;i++)
        if(q(x,y)>=pow(2,i)&&q(x,y)<=pow(2,i+1)) {bu=i+1;break;}
        
    }
}