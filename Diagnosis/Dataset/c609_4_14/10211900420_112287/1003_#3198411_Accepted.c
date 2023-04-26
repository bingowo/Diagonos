#include<stdio.h>
int main()
{
    long long a[100],i,j,n,m,T;
    scanf("%lld",&T);
    for(i=0;i<T;i++)
    {
        j=0;
        scanf("%lld",&n);
        if(n==0)
        {
            printf("0\n");
            continue;
        }
        while(n!=0)
        {
            a[j]=n%2333;
            n=n/2333;
            j++;
        }
        for(m=j-1;m>=0;m--)
        {
            printf("%lld ",a[m]);
        }
        printf("\n");
    }
    return 0;

}
