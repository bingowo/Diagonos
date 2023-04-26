#include<stdio.h>
char ToAlpha(int t)
{
    char r ='A'+(t-10);
    return r;
}
int main()
{
    int T,N,R,i,j,k,t;
    char s[10000];
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        int flag=1;
        scanf("%d%d",&N,&R);
        if(N<0)
        {
            N=-N;
            flag=-1;
        }
        k=-1;
        while(N>0)
        {
            t=N%R;
            k++;
            if(t<=9)
            {
                s[k]='0'+t;
            }
            else
            {
                s[k]=ToAlpha(t);
            }
            N=N/R;
        }
        if (flag==-1)
        {
            printf("-");
        }
        for(j=k;j>=0;j--)
        {
            printf("%c",s[j]);
        }
        printf("\n");
    }
    return 0;
}