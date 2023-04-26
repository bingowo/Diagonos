#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int r;

void reverse(int re[],int wei)
{
    int i;
    for(i=0;i<wei/2;i++)
    {
        int m;
        m=re[i];
        re[i]=re[wei-1-i];
        re[wei-1-i]=m;
    }
}

int jia1(int shu,int pos,int wei,int *re)
{
    int i;
    reverse(re,wei);
    for(i=wei-pos-1;(shu!=0)||(i<wei);i++)
    {
            int mid=re[i]+shu;
            shu=mid/10;
            re[i]=mid%10;
            //printf("%d",z[i]);
    }
    int w=i;
    reverse(re,w);
    return w;
}

void jud(int* a,int wei)
{
    int i;
    for(i=0;i<wei-1;i++)
    {
        if(a[i]==a[i+1])
        {
            wei=jia1(1,i+1,wei,a);
            jud(a,wei);
        }
    }
    r=wei;
    return;

}

int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        char s[110];
        scanf("%s",s);
        int a[110],j,ls=strlen(s);
        memset(a,0,sizeof(int)*110);
        for(j=0;j<ls;j++)
        {
            a[j]=s[j]-'0';
        }
        int wei=ls;
        wei=jia1(1,ls-1,ls,a);
        jud(a,wei);
        printf("case #%d:\n",i);
        for(j=0;j<r;j++)
        {
            printf("%d",a[j]);
        }
        printf("\n");

    }
    return 0;
}
