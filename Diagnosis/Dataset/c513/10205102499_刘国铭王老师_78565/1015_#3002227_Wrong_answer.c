#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define N 25

int p[N+1];

int isprime(int n)
{
    int i;
    for (i=2; i<=sqrt(n); i++)
    {
        if (n%i == 0)
            return 0;
    }
    return 1;
}

void calcPrime()
{
    int i;
    int j;
    p[0] = 2;
    j = 1;
    i = 3;
    while (j<=N+1)
    {
        while (!isprime(i))
            i++;
        p[j++] = i;
        i++;
    }
}

void print(int a[])
{
    int i;
    for (i=N; i>=0; i--)
    {
        if (a[i] != 0)
            break;
    }
    if (i < 0)
    {
        printf("0\n");
        return;
    }
    printf("%d", a[i]);
    for (i--; i>=0; i--)
        printf(",%d", a[i]);
    printf("\n");
}

void prase(char s[], int a[])
{
    int i = 0;
    int j = 0;
    while (s[i])
    {
        a[j++] = atoi(s+i);
        while(isdigit(s[i]))
            i++;
        if (s[i] == ',')
            i++;
    }
    int tmp;
    for (i=0; i<j/2; i++)
    {
        tmp = a[i];
        a[i] = a[j-1-i];
        a[j-1-i] = tmp;
    }
    for (i=j; i<=N; i++)
        a[i] = 0;
}

void plus(int a[], int b[])
{
    int i;
    for (i=0; i<=N; i++)
    {
        a[i] += b[i];
        //printf("p[%d]=%d\n", i, p[i]);
        if (a[i] >= p[i])
        {
            a[i+1] ++;
            a[i] -= p[i];
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
    char s1[1000], s2[1000];
    int a[N+1], b[N+1];

    calcPrime();
    while (scanf("%s%s", s1, s2) != EOF)
    {
        if (strcmp(s1, "0") == 0 || strcmp(s2, "0") == 0)
            break;

        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        prase(s1, a);
        prase(s2, b);

        plus(a, b);
        print(a);
    }
    }
    return 0;
}
