#include<stdio.h>
#include<math.h>
void reverse(long long n)
{
    if(n>0)
    {
        reverse(n/2333);
        printf("%d ",n%2333);
    }
}
int main()
{
    int T;
    long long n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld",&n);
        if(n==0)
            printf("0");
        else
        {
            reverse(n);
            printf("\n");
        }
    }
    return 0;
}
