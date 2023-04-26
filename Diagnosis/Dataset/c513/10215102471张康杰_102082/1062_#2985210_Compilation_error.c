#include <stdio.h>
#include <stdlib.h>

void f(int n,int a[])
{
    if(n == 0 || n == 1)
        a[n] = 1;
    else if(n < 0)
        a[n] = 0;
    else
        a[n] =  f(n - 1) + f(n - 2) + f(n - 3) + f(n - 4);
}

int main()
{
    int T,i,n;
    scanf("%d",&T);
    unsigned long long int record[50] = {0};
    for(i = 0;i < T;i++)
    {
        scanf("%d",&n);
        f(n,record);
        printf("case #%d:\n%lld\n",i,record[n]);
    }    
}