#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int number(int n,int m)
{
    if(n == m)return 1;
    else if(n < m)return 0;
    else return 2*number(n-1,m) - number(n-m-1,m) + pow(2,n-m-1);
}
//f(n,m) = f(n-1,m) + f(n-2,m) +……+f(n-m,m) + 2^(n-m);f是函数
//f(n+1,m) = f(n,m) + f(n-1,m) +……+f(n-m+1,m) + 2^(n-m+1);
//两式相减得f(n+1,m) - f(n,m) = f(n,m) - f(n-m,m) + 2^(n-m);
//即f(n+1,m) = 2*f(n,m) - f(n-m,m) + 2^(n-m);
//即f(n,m) = 2*f(n-1,m) - f(n-m-1,m) + 2^(n-m-1);

int main()
{
    int m,n;
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(n == -1 && m == -1)break;
        else printf("%d\n",number(n,m));
        //printf("%d\n%d",m,pow(2,n)-1);
    }
    return 0;
}
