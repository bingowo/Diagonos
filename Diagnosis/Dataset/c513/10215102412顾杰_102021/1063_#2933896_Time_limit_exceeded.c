#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
long long f(long long a,long long b)
{
    if(a>b)return 4*b+f(a-b,b);
    else if(a<b)return 4*a+f(a,b-a);
    else return 4*a;
}
int main()
{
   long long x,y;
   scanf("%lld%lld",&x,&y);
   printf("%lld",f(x,y));
}
