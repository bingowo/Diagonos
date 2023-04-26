#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,n;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        long long int x;
        scanf("%lld",&x);
        long long int a[10000];
         if(x==0)
            {
                printf("%lld",x);
            }
        for(n=0;x!=0;n++)
            {
                a[n]=x%2333;
                x=x/2333;
            }
        for(n--;n>0||n==0;n--)
            printf("%lld ",a[n]);
        printf("\n");

    }
    return 0;
}
