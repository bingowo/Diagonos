#include <stdio.h>
#include <stdlib.h>

long long int gcd( long long int a,long long int b)        //辗转相除法(a>b)
{
    if(b<0)
        b = -b;
    while(b != 0)
    {
         long long int t = a % b;
        a = b;
        b = t;
    }
    return a; //最大公约数
}
int main()
{
    long long int ret1 = 0,ret2 = 0,a = 1;
    char c[33] = {0};
    int i=0;
    int alpha[3]={0,1,-1};
    scanf("%s",c);;
    while (c[i] != '.' && c[i] != '\0')
    {
        ret1 = ret1*3 + alpha[c[i++]-'0'];
        //i++;
    }
    while( c[++i] != '\0')
    {
        ret2 = ret2*3 + alpha[c[i]-'0'];
        a = a*3;
    }
    if(ret2 != 0)
    {
        if(ret2 < 0 && ret1 > 0)
        {
            ret2 = a + ret2;
            ret1--;
        }else if(ret2 > 0 && ret1 < 0)
        {
            ret2 = a - ret2;
            ret1++;
        }

        long long int t = gcd(a,ret2);
        a /= t,ret2 /= t;
    }
   if (ret2 == 0)
        printf("%lld\n",ret1);
   else
   {
        if (ret1 != 0)
            printf("%lld ",ret1);
        printf("%lld %lld\n",ret2,a);
   }
    return 0;
}