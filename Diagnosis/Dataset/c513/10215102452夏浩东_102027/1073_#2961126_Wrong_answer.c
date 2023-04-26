#include <stdio.h>
int func(long long int num)
{
    int res=0,k=0;
    while(num!=0){
        res+=num%10;
        if(num%10==9) return 1;
        num=num/10;
    }
    if(num%9==0) return 1;
    else return 0;
}
int main()
{
    long long int a=0,b=0;
    long long int res=0;
    scanf("%d %d",&a,&b);
    for(long long int i=a;i<=b;i++)
    {
        if(func(i)==1) res++;
    }
    printf("%lld",b-a+1-res);
}