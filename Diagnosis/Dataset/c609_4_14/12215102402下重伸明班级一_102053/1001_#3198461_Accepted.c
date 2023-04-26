#include<stdio.h>
char s[]={"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
void ming(int x,int y)
{
    if(x>0)
    {
        ming(x/y,y);
        putchar(s[x%y]);
    }
}
int main()
{

    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x<0)
        {
            printf("-");
            x=x*-1;
        }
        if(x==0)
        {
            putchar(s[0]);
        }
        else
        {
            ming(x,y);
        }
        printf("\n");
    }
}
