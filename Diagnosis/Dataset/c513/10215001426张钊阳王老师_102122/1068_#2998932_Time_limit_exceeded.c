#include <stdio.h>
#include<stdlib.h>
#include<string.h>



long long RE(int n, int m)
{
    long long *a=(long long*)malloc(sizeof(long long)*(n+1));
    memset(a,0,8*n+8);
    int i;
    for(int i = 1; i < n+1; i++)
    {
        if(i < m)
        {a[i] = 0;}
        else if(i == m)
        {a[i] = 1;}
        else if(i > m)
        {
            a[i] = a[i - 1] * 2 + pow(2,i-m-1) - a[i - m - 1];
        }
    }
    long long temp = a[n];
    free(a);
    return temp;
}


int main()
{
    long long  n, m;
    while(scanf("%d %d",&n,&m))
    {
        if(n == -1 && m == -1)
            break;


        printf("%lld",RE(n,m));
    }
}
