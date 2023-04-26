#include<stdio.h>
int main()
{
    long long int a,b,tmp=1,sum=1;
    scanf("%lld %lld",&a,&b);
    if(a<0) a=-a;
    if(b<0) b=-b;
    sum=a+b;
    if(sum==0)
    {
        printf("0");
        return 0;
    }
    if(sum%2==0)
    {
        printf("-1");
        return 0;
    }
    int count=0;
    while(tmp<sum)
    {
        tmp*=2;
        count++;
    }
    printf("%d",count);
}
