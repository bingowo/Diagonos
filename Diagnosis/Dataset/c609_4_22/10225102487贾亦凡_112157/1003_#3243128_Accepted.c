#include<stdio.h>
int main()
{
    int t,i;
    long long n;
    scanf("%d",&t);
    for(int j=0;j<t;j++)
    {
        scanf("%lld",&n);
        if(n==0)
        {
            printf("0\n");
            continue;
        }
        long long s[10];
        i=0;
        while (n>0)
        {
            s[i]=n%2333;
            i++;
            n/=2333;
        }
        for(int j=i-1;j>=0;j--)
        {
            printf("%lld ",s[j]);
        }
        printf("\n");
    }
    return 0;
}