#include<stdio.h>
char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
int ming(int x,int y)
{
    if(x>0)
    {
        trans(x\y,y);
        putchar(table[x%y]);
    }
}
int main()
{
    int n;
    
    scanf("%d",&n);
    int x,y;      // a数字 b进制
    for(int i=0;i<n;i++)
    {
       scanf("%d %d",&a[i],&b[i]);
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
           printf("/n")
           
       }
    }
}