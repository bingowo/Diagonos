#include<stdio.h>

void func();
int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        func();
    }
    return 0;
}

void func()
{
    int x,y,count=0;
    scanf("%d%d",&x,&y);
    for(int i=0;i<32;i++)
        if (((x>>i)&1)^((y>>i)&1)) count++;
    printf("%d\n",count);
}