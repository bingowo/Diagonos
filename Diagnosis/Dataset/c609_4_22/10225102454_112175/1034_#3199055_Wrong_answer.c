#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define ll long long 

int min(int a, int b)
{
    return a > b ? b: a;
}

int max(int a, int b)
{
    return a < b ? b: a;
}

#define N 100006
int n;
char s[N];

int main(void)
{ 
    scanf("%s", s + 1);
    n = strlen(s + 1);
    int flag = 1;
    for (int i = 1; i <= n; i++)
    {
        // printf("%d\n", i);
        if (i <= n - 1 && s[i] == '0' && s[i + 1] == 'x')
        {
            ll sum = 0;
            int j = i + 2;
            while (j <= n)
            {
                int x;
                if (isdigit(s[j]))
                    x = s[j] - '0';
                else
                    x = s[j] - 'a' + 10;
                if (x <= 15)
                {
                    sum = sum * 16 + x;
                }
                else
                    break;
                j++;
            }
            if (sum)
            {
                flag = 0;
                printf("%lld ", sum);
            }
            i = j - 1;
        }
    }
    if (flag)
        puts("-1");

    return 0;
}