#include <stdio.h>
#include <string.h>
#include <math.h>
int RE(int n, int m)
{
    if(n < m) return 0;
    if(n == m) return 1;
    return 2 * RE(n - 1,m) + pow(2, n-m-1) - RE(n - m - 1,m);
}
int main()
{
    int n,m;
    while(1)
    {
        scanf("%d %d",&n,&m);
        if(n==-1&&m == -1) break;
        printf("%d\n",RE(n,m));


    }
    return 0;
}
