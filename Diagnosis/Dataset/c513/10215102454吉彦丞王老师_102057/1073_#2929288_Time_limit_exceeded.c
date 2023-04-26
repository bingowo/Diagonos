#include<stdio.h>
int include(int a)
{
    int t=0;
    while(a>0)
    {
        if(a%10==9)
        {
            t++;
        }
        a=a/10;
    }
    if(t>0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int t=0;
    for(int i=a;i<b+1;i++)
    {
        if(include(i)==0&&i%9!=0)
        {
            t=t+1;
        }
    }
    printf("%d",t);
    return 0;
}