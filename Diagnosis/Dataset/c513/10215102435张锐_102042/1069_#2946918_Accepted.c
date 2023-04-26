#include <stdio.h>
#include <stdlib.h>
long long int yes(long long int x)//是返回-1，不是返回和
{
    int s[200],i=0;int x1=x;
    while(x)
    {
        long long int temp=x%10;
        s[i++]=temp;x=x/10;
    }
    long long int num=0;
    for(int j=0;j<i;j++) num=num*10+s[j];
    if(num==x1) return 1;
    else return 0;
}
void f(long long int x,long long int ans[])
{
    ans[0]++;
    int s[200],i=0;int x1=x;
    while(x)
    {
        long long int temp=x%10;
        s[i++]=temp;x=x/10;
    }
    long long int num=0;
    for(int j=0;j<i;j++) num=num*10+s[j];
    long long int y=num+x1;
    if(yes(y)) {ans[1]=y;return;}
    else f(y,ans);
}
int main()
{
    long long int x;
    scanf("%lld",&x);
    long long int ans[2]={0};
    f(x,ans);
    printf("%lld %lld\n",ans[0],ans[1]);
    return 0;
}
