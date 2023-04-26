#include<stdio.h>
int main()
{
    char table[36]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int a[32]={0};
    int n,t,r,y=0,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int j=0;
        scanf("%d%d",&t,&r);
        if(t<0) 
        {
            printf("-");
            t=-t;}
        while(t!=0)
        {
           y=t%r;
           a[j++]=y;
           t=t/r;
        }
       for(j=j-1;j>=0;j--)
       {
           int s=a[j];
           printf("%c\n",table[s]);
       }
    }
    return 0;
}