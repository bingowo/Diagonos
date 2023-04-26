#include <stdio.h>
#include <stdlib.h>

int gcd(int a,int b)        //辗转相除法(a>b)
{
    if(b<0)
        b = -b;
    while(b != 0)
    {
        int t = a % b;
        a = b;
        b = t;
    }
    return a; //最大公约数
}
int main()
{
    int ret1 = 0,ret2 = 0;
    char c,sign;
    int a=1;
    int alpha[3]={0,1,-1};
    while (c=getchar(),c != '.' && c != '\n')
    {
        ret1 = ret1*3 + alpha[c-'0'];
    }
    while( c = getchar(), c != '\n')
    {
        ret2 = ret2*3 + alpha[c-'0'];
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

        int t = gcd(a,ret2);
        a /= t,ret2 /= t;
    }
    if(ret1 != 0)
        printf("%d ",ret1);
    if(ret2 != 0)
        printf("%d %d\n",ret2,a);


    return 0;
}
