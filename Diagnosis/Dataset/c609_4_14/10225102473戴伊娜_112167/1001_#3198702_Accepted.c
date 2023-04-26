#include <stdio.h>
#include <stdlib.h>
char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
void transnumber(int n,int r)
{
    if(n>0)
        {
            transnumber(n/r,r);
            putchar(table[n%r]);
       }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n,r;
        scanf("%d%d",&n,&r);
         if(n<0)
       {
           printf("-");
           n=-n;
       }
       if(n==0)
           putchar(table[0]);
        else transnumber(n,r);
        printf("\n");
    }
       return 0;
}
