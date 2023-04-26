#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int* ctoBinaryArray(char c)
{
    int n = c;
    int* arr = (int*)malloc(8*(sizeof(int)));
    memset(arr,0,8);
    int i = 7,r = 0;
    while(n!=0)
    {
        r = n%2;
        n = n/2;
        arr[i--] = r;
    }
    return arr;
}

int solve1Number(int* arr, int lenth)
{
    int res = 0;
    for(int i = 0;i<lenth;i++)
    {
        if (arr[i] == 1){res++;}
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
            int* p = ctoBinaryArray(s[i]);
            res += solve1Number(p,8);
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
