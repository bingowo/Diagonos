#include<stdio.h>
#include<string.h>

int f(unsigned int x,unsigned int y)
{
    int i=0,count=0;
    for(i=0;i<32;i++)
    {
        if((x<<i>>31)!=(y<<i>>31)) count++;
    }
    return count;
}

int main()
{
    int T,t=0;
    scanf("%d",&T);
    while (T--)
    {
        unsigned int x,y;
        scanf("%u %u",&x,&y);
        printf("case #%d:\n%d\n",t,f(x,y));
        t++;
    }
    return 0;
}
