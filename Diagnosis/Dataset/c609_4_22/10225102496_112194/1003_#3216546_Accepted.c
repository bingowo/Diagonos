#include<stdlib.h>
#include<stdio.h>

int main()
{
    int T,j,i;
    unsigned long long n;
    unsigned long long a[100];
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%llu",&n);
        if(n==0) printf("%llu",n);
        else
        {
            for(j=0;n>0;j++)
        {
            a[j]=n%2333;
            n=n/2333;
        }
        for(j=j-1;j>=0;j--)
        {
            printf("%llu ",a[j]);
        }
        }
        printf("\n");
    }
    return 0;
}
