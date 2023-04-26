#include <stdlib.h>
#include <stdio.h>
#include <string.h>

unsigned long long int f(int n,int ar[])
{
    unsigned long long int s;
    if(ar[n] != -1)
        return ar[n];
    if(n == 0)
    {
        s == 0;
    }
    else if(n == 1 || n == 2)
    {
        s == 1;
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
        scanf("%d",&n);
        unsigned long long int ar[n + 1];
        memset(ar,-1,sizeof(unsigned long long int) * (n + 1));
        ar[0] = 0;
        printf("case #%d:\n",i);
        printf("%llu",f(n,ar));
        putchar('\n');
    }
    return 0;
}