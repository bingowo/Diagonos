#include<stdio.h>
int main()
{
    char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int n,t,r,y,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&t&r);
        while(t>r){
            y=t/r;
            printf("%s",table[y]);
            t=t%r;
        }
        printf("%s\n",table[t])
    }
}