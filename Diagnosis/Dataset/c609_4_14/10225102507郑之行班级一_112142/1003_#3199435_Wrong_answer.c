#include <stdio.h>
#include <stdlib.h>

void mod(long long a)
{
    if(a)
    {
        mod(a/2333);
        printf("%lld ",a%2333);
    }
}

int main()
{
    int T;scanf("%d",&T);
    long long a;
    for (int i=0;i<T;i++)
    {
        while(scanf("%lld",&a)!=-1)
        {

        if(a==0){printf("0");return 0;}

        mod(a);
        printf("\n");
        }
        break;
    }
    return 0;
}
