#include<stdio.h>
int f(int x,int y)
{
    int c=x^y;
    int p=0
    while(z>0)
    {
        if(c%2!=0) p++;
        c/=2;
    }
    return p;
}
int main(void)
{
    int T=0;
    scanf("%d\n",&T);
    for(int i=0;i<T;i++)
    {
        int x,y;
        scanf("%d %d\n",&x,&y);
        f(x,y);
        printf("%d\n",f(x,y));
    }
    return 0;
}