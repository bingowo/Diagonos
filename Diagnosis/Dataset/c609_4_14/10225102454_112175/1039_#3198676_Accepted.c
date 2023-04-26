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

#define N 100
char s[N], minv1, minv2, maxv1, maxv2;

void find1(char str[])
{
    int n = strlen(str + 1), nn = strlen(s + 1);
    minv1 = 10006, maxv1 = -1; 
    for (int i = 1; i + n - 1 <= nn; i++)
    {
        int flag = 0;
        for (int j = 1; j <= n; j++)
        {
            if (str[j] != s[i + j - 1])
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            maxv1 = max(maxv1, i);
            minv1 = min(minv1, i);
        }
    }
}

void find2(char str[])
{
    int n = strlen(str + 1), nn = strlen(s + 1);
    minv2 = 10006, maxv2 = -1; 
    for (int i = 1; i + n - 1 <= nn; i++)
    {
        int flag = 0;
        for (int j = 1; j <= n; j++)
        {
            if (str[j] != s[i + j - 1])
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            maxv2 = max(maxv2, i);
            minv2 = min(minv2, i);
        }
    }
}

void solve(int t)
{
    printf("case #%d:\n", t);
    char s1[N], s2[N];
    scanf("%s%s%s", s1 + 1, s2 + 1, s + 1);
    int n1 = strlen(s1 + 1), n2 = strlen(s2 + 1);
    find1(s1);
    find2(s2);
    // printf("%d %d\n", minv1, maxv1);
    // printf("%d %d\n", minv2, maxv2);
    if (maxv1 == -1 || maxv2 == -1)
        printf("0\n");
    else
    {
        int x1 = minv1 + n1, x2 = minv2 + n2;
        int y1 = maxv1 + n1, y2 = maxv2 + n2;
        printf("%d\n", max(max(0, maxv2 - x1), max(0, maxv1 - x2)));
    }
}

int main(void)
{ 
    int t;
    scanf("%d", &t);
    getchar();
    for (int i = 0; i < t; i++)
        solve(i);

    return 0;
}