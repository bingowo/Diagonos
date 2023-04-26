#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solve1Number(char c)
{
    int n = c,res = 0;
    for(int i = 0;i<8;i++)
    {
        if (n&1 == 1)
        {
            res+=1;n = n>>1;
        }
    }
    return res;
}

int GCD(int a, int b)
{
    int r = 0;
    while(b!=0)
    {
            r = a%b;
            a = b;
            b = r;
    }
    return a;
}

int main()
{
    int T = 0;
    scanf("%d",&T);
    getchar();
    int numeratorList[T];
    int denominatorList[T];
    memset(numeratorList,0,T);
    memset(denominatorList,0,T);
    for(int i = 0;i<T;i++)
    {
        char s[300];
        memset(s,0,300);
        gets(s);
        int slen = strlen(s);
        int res = 0;
        for(int i = 0;i<slen;i++)
        {
            res += solve1Number(s[i]);
        }
        numeratorList[i] = res;
        denominatorList[i] = slen*8;
    }

    for(int i = 0;i<T;i++)
    {
        int gcd = GCD(numeratorList[i],denominatorList[i]);
        printf("%d/%d\n",numeratorList[i]/gcd,denominatorList[i]/gcd);
    }


    return 0;
}
