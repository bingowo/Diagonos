#include<stdio.h>
int main()
{
    long long int a,b,tmp=1,sum=1;
    scanf("%lld %lld",&a,&b);
    if(a<0) a=-a;
    if(b<0) b=-b;
    sum=a+b;
    int count=0;
    while(tmp<sum)
    {
        tmp*=2;
        count++;
    }
    printf("%d",count);
}
