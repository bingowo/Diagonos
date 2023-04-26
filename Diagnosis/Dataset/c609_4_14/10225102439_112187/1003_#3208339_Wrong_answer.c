#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    long long int a[n];
    for (int i=0;i<n;i++)
        scanf("%lld",a+i);
    for (int j=0;j<n;j++)
    {
        long long int x=a[j],b[300],t=0;
        while (x!=0)
        {
            b[t++]=x%2333;
            x/=2333;
        }
        t--;
        while (t>=0)
        {
            printf("%lld ",b[t]);
            t--;
        }
        printf("\n");
    }
    return 0;
}
