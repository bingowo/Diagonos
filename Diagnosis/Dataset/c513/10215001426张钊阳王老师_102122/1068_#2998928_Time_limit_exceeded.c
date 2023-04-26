#include <stdio.h>
#include<stdlib.h>
#include<string.h>





long long  IT(int n , int m)
{
    long long a[100000];
    memset(a,0,100000);
    for(int i = 1; i < n + 1; i++)
    {
        if(i < m)
        {a[i] = 0;}
        else if(i == m)
        {a[i] = 1;}
        else if(i > m)
        {
            a[i] = a[i - 1] * 2 + 1<<n-m-1 - a[i - m - 1];
        }
    }
    long long  temp = a[n];
    return temp;
}


int main()
{
    long long  n, m;
    while(scanf("%d %d",&n,&m))
    {
        if(n == -1 && m == -1)
            break;


        printf("%lld",IT(n,m));
    }
}
