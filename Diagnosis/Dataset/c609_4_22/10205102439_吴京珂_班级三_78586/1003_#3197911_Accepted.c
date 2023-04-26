#include <stdio.h>
#include <stdlib.h>

void _2333(long long int n)
{
    long long int a[100]= {0};
    int i=0,j=0;
    while(n!=0)
    {
        a[i]=n%2333;
        n/=2333;
        i++;
    }

    for(j=i-1; j>0; j--)
    {
        printf("%lld ",a[j]);
    }
    printf("%lld\n",a[0]);
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0; i<t; i++)
    {
        long long int n;
        scanf("%lld",&n);

        _2333(n);
    }

    return 0;
}
