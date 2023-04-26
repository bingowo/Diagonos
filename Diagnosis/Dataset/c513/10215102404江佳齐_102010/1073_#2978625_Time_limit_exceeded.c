#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int f1(long long int i)
{
    if(i%9==0) return -1;
    else return 0;
}
int f2(long long int i)
{
    int flag=0;
    while(i)
    {
        int temp=i%10;
        i=i/10;
        if(temp==9)
        {
            flag=1;
            break;
        }
    }
    if(flag==1) return -1;
    else return 0;
}
int main()
{
    long long int a,b,count=0;
    scanf("%lld %lld",&a,&b);
    for(long long int i=a;i<=b;i++)
    {
        if(f1(i)!=-1&&f2(i)!=-1) count++;
    }
    printf("%lld\n",count);
    return 0;
}
