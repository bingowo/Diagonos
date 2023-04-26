#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<ctype.h>
#define M 52
void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int isb(char a)
{
    if (('A' <= a) && (a <= 'Z'))
        return 1;
    else
        return 0;
}
int iss(char a)
{
    if (('a' <= a) && (a <= 'z'))
        return 1;
    else
        return 0;
}
int main()
{
    int T;
    int i, j, k,temp;
    int a[M] = { 0 };
    int n = 0;
    char c;
    scanf("%d", &T);
    for (i = 0; i < T; i++)
    {
        for (j = 0; j < M; j++)
        {
            a[j] = 0;
        }
        while ((c = getchar()) != '\n')
        {
            if (isb(c))
            {
                temp = c - 'A';
                if (a[temp * 2 + 1] == 0)
                    n++;
                a[temp*2+1] = 1;
            }
            else if (iss(c))
            {
                temp = c - 'a';
                if (a[temp * 2] == 0)
                    n++;
                a[temp*2] = 1;
            }
        }
        printf("case #%d:\n", i);
        for (j = 0; j < 52; j++)
        {
            for (k = j + 1; k < 52; k++)
            {
                ;
            }
        }
    }
    return 0;
}