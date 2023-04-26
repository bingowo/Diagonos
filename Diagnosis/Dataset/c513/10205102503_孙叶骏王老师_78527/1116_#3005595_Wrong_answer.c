#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    long long x,y;
    scanf("%lld%lld",&x,&y);
    long long a=abs(x),b=abs(y);
    if(a+b==0)printf("%d",0);
    else if((a+b)%2==0)printf("%d",-1);
    else
    {
        int s=ceil(log(a+b+1)/log(2));
        printf("%d",s);
    }
}