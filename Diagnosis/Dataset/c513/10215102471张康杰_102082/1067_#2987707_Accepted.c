#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef unsigned long long int ULL;

ULL f(int n,ULL ar[])
{
    ULL s;
    if(ar[n] != 0)
        return ar[n];
    if(n == 0)
    {
        s == 0;
    }
    else if(n == 1 || n == 2)
    {
        s = 1;
    }
    else
    {
        s = f(n - 1,ar) + f(n - 2,ar) + f(n - 3,ar); 
    }
    ar[n] = s;
    return s;
}

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        int n;
        ULL*ar;
        scanf("%d",&n);
        ar = (ULL*)malloc(sizeof(ULL) * (n + 1));
        memset(ar,0,sizeof(ULL)*(n + 1));
        printf("case #%d:\n",i);
        printf("%llu",f(n,ar));
        free(ar);
        putchar('\n');
    }
    return 0;
}