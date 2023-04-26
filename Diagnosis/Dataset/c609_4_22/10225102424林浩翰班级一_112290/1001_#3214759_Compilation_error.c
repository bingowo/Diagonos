#include<stdio.h>

char table[]="01234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ";
void trans(int n,int r)
{
    if(n>0)
    {
        trans(n/r,r);
        putchar(table[n%r]);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n,r;
        scanf("%d%d",&n,&r);
        if(n<0){printf("-");n=-n;}
        if(n==0){putchar(table[0]);}
        else{trans(n,r);printf("\n")}
    }
    return 0;
}
