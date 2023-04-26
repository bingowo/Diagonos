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
    int T,i;
    long long n;
    scanf("%d",&T);
    for(i=0;i<T;i++)
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
