#include<stdio.h>
int f(int x,int y)
{
    int c=x^y;
    int p=0;
    while(c!=0)
    {
        if(c%2!=0) p++;
        c/=2;
    }
    return p;
}
int main()
{
    int t,x,y;
    scanf("%d\n",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d %d\n",&x,&y);
        printf("%d\n",f(x,y));
    }
    return 0;
}
