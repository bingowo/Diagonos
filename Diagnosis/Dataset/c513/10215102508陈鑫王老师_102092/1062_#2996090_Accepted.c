#include<stdio.h>
#include<stdlib.h>
long long int map[51];
long long int solve(int n)
{
    long long int ret;
    if(n==1)
    {
        ret=1;
        map[n]=ret;
    }
    else if(n==2)
    {
        ret=2;
        map[n]=ret;
    }
    else if(n==3)
    {
        ret=4;
        map[n]=ret;
    }
    else if(n==4)
    {
        ret=8;
        map[n]=ret;
    }
    else
    {
        if(map[n]!=0)
        {
            ret=map[n];
        }
        else
        {

        ret=solve(n-1)+solve(n-2)+solve(n-3)+solve(n-4);
        map[n]=ret;
        }
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
        long long int ret;
        ret=solve(n);
        printf("case #%d:\n",i);
        printf("%llu\n",ret);

    }
    return 0;
}
