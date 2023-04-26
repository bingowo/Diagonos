

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define LL long long 

int min(int a, int b)
{
    return a > b ? b: a;
}

int max(int a, int b)
{
    return a < b ? b: a;
}

int main(void)
{ 
    char s[100];
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int res = 1;
        for (int j = i; j <= n - 1; j++)
            if (s[j] != s[j + 1])
                res++;
            else
                break;
        ans = max(res, ans);
    }
    printf("%d\n", ans);
    return 0;
}