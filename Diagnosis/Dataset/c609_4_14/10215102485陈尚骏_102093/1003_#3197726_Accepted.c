#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long int n;
        scanf("%lld",&n);
        int a[100];
        int i=0;
        if(n==2333)
            printf("1 0\n");
        else{
        while(n>0)
        {
            a[i]=n%2333;
            i++;
            n=n/2333;
        }
        i--;
        printf("%d",a[i]);
        i--;
        for(;i>=0;i--)
            printf(" %d",a[i]);
        printf("\n");
        }
    }
    return 0;
}