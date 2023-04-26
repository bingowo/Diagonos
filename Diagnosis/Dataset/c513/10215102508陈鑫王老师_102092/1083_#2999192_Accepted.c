#include<stdio.h>
#include<stdlib.h>
int num0(int n)
{
    int ret=0;
    for(int i=1;i<=n;i++)
    {
        if(i%5==0)ret++;
        if(i%25==0)ret++;
        if(i%125==0)ret++;
        if(i%625==0)ret++;
    }
    return ret;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        int num=num0(n);
        printf("case #%d:\n%d\n",i,num);
    }
    return 0;
}
