#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char s[100];

int find(int m,int n)
{
    int max = m > n ? m : n;
    int min = m+n-max;
    while(max%min)
    {
        int res = max%min;
        max = min;
        min = res;
    }
    return min;
}

int trans(char c)
{
    if(c == '2')
        return -1;
    if(c == '0')
        return 0;
    return 1;
}

int main()
{
    char *zs;
    char *xs;
    int sig = 0;
    int p;
    scanf("%s",s);
    for(int i = 0;i < strlen(s);i++)
    {
        if(s[i] == '.')
        {
            sig = 1;
            p = i;
            s[i] = '\0';
        }
    }
    if(sig)
    {
        zs = s;
        xs = s+p+1;
    }
    else
    {
        zs = s;
    }
    long long int sumz = 0;
    for(int i = strlen(zs)-1;i >= 0;i--)
    {
        int t = strlen(zs)-i-1;
        sumz += (long long int)pow(3,t)* trans(zs[i]);
    }
//    printf("%d ",sumz);
    if(sig)
    {
        int zi = 0;
        unsigned len = strlen(xs);
        int max = (int)pow(3,len);
        for(int i = 1;i <= len;i++)
        {
            int time = max/(int)pow(3,i);
            zi += time * trans(xs[i-1]);
        }
        int numb = find(zi,max);
        zi /= numb;
        max /= numb;
        if(((zi < 0) && (max > 0)) || ((zi > 0) && (max < 0)))
        {
            zi = -abs(zi);
            max = abs(max);
        }
        if((zi < 0) && (sumz > 0))
        {
            zi += max;
            sumz--;
        }
        if((zi > 0) && (sumz < 0))
        {
            zi = max-zi;
            sumz++;
        }
        if(sumz != 0)
            printf("%lld ",sumz);

        printf("%d %d",zi,max);
    }
    if(sig == 0)
        printf("%lld ",sumz);
    printf("\n");

    return 0;
}