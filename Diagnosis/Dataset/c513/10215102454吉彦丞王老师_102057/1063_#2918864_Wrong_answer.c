#include<stdio.h>
int max(int a,int b)
{
    if(a>b)
    {
        return 1;
    }
    else if(a==b)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int t=0;
    while(a>0&&b>0)
    {
        if(max(a,b)==1)
        {
            t=t+4*b;
            a=a-b;
        }
        else if(max(a,b)==0)
        {
            t=t+4*b;
            a=0;
            b=0;
        }
        else
        {
            t=t+4*a;
            b=b-a;
        }
    }
    printf("%d",t);
    return 0;
}