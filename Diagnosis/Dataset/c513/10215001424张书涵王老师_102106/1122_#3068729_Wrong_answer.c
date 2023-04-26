#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    int i;
    for(i=0;i<T;i++)
    {
        unsigned long long int n,n1,p;
        int j;
        scanf("%llu",&n);
        unsigned long long int a[100000]={0};
        n1=n;
        for(j=0;n1>0;j++)
        {
            a[j]=n1%2333;
            n1=n1/2333;
        }
        int p1;
        for(p1=j-1;p1>=0;p1--)
            printf("%llu ",a[p1]);
        printf("\n");
    }
}