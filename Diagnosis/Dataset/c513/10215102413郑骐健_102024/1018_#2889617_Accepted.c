#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#define N 40
int prime[40] = { 1,2, 3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97 };
int multiply(int* p,int i, int n)
{
    p[0] += i;
    for (int z = 0;z < N; z++)
    {
        p[z] *= prime[n];
    }
    for (int h = 0;h < N-1;h++)
    {
        if (!(p[h] < 10))
        {
            p[h + 1] += p[h] / 10;
            p[h] = p[h] % 10;
        }
    }
}
int main()
{
    char c;
    int length = 0;
    int p[N] = { 0 };
    do
    {
        scanf(" %d%c", &p[length++],&c);
    } while (c == ',');
    int res[40];
    memset(res, 0, sizeof(int) * 40);
    for (int i = 0;i < length;i++)
    {
        multiply(res, p[i], length - i-1);
    }
    int g;
    for ( g= N-1;g >0;g--)
    {
        if (res[g] != 0)break;
    }
    for (int i = g;i > -1;i--)
    {
        printf("%d", res[i]);
    }
    return 0;
}

