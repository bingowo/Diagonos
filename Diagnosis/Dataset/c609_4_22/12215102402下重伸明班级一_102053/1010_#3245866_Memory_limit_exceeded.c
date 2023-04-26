#include<stdio.h>
char m[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
void ming(int x,int y)
{
    int a= x/y;
    int b=x%y;
    if(b<0)
    {
        a=a+1;
        b=b-y;
    }
    ming(a,y);
    putchar(m[b]);
    
}
int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    if(x==0)
    {
        printf("0");
    }
    ming(x,y);
    return 0;
}