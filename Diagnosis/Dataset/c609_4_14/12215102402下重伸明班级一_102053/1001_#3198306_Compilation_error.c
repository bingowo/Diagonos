#include<stdio.h>
char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
void trans(int x,int y)
{
    if(x>0)
    {
        trans(x/y,y);
        putchar(table[x%y]);
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
           x=-x;
       }
       if(x==0)
       {
           printf("0");
       }
       else
       {
           trans(x,y);
           printf("/n");
           
       }
    }
}