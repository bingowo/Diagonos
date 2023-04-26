#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define ll long long 

int min(int a, int b) {
    return a > b ? b: a;
}

int max(int a, int b) {
    return a < b ? b: a;
}

#define N 1000006
int n, b[1000];
char s[N];

int main(void)
{ 
    scanf("%s", s + 1);
    int n = strlen(s + 1);

    int ans = 0, st = 0;
    int i = 1, j = 1;
    while (j <= n)
    {
        int x = s[j];
        if (!b[x])
            b[x] = j;
        else
        {
            i = max(i, b[x] + 1);
            b[x] = j;
        }

        int d = j - i + 1;
        if (d > ans)
            ans = d, st = i;
        j++;
    }

    for (int i = st; i < st + ans; i++)
        putchar(s[i]);
    
    return 0;
}