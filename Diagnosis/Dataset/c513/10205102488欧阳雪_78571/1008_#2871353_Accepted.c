#include<stdio.h>

int f(int x,int y)
{
    int c=0;
    long long a=x^y;
    while(a)
    {
        a=a&(a-1);
        c++;
    }
    return c;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        int m=f(x,y);
        printf("%d\n",m);
    }
}