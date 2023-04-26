#include<stdio.h>
int main()
{
    int T,a,b,t;
    int count(int x,int y);
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%d %d",&a,&b);
        t=count(a,b);
        printf("%d\n",t);
    }
    return 0;
}
int count(int x,int y)
{
    int cnt=0;
    for(int i=0;i<32;i++)
    {
        cnt+=(x&1)^(y&1);
        x=x>>1;
        y=y>>1;
    }
    return cnt;
}