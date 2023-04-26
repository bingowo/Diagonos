#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int r;
int flag;

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
    int i,w;
    reverse(re,wei);
    pos=wei-pos-1;
    if(shu>0)
    {
        for(i=pos;(shu!=0)||(i<wei);i++)
        {
                int mid=re[i]+shu;
                shu=mid/10;
                re[i]=mid%10;
                //printf("%d",z[i]);
        }
        w=i;
    }
    else if(shu<0)
    {
        int j,k,en;
        shu=abs(shu);

        if(re[pos]>=shu) re[pos]=re[pos]-shu;
        else
        {
            for(j=pos;j<wei;j++)
            {
                if(re[j+1]>0) {en=j+1;re[j+1]--;break;}
            }
            for(k=en-1;k>pos;k--)
            {
                re[k]+=9;
            }
            re[pos]+=10;
            re[pos]=re[pos]-shu;
            //printf("test:re[%d]=%d\n",i,re[i]);
        }
        w=wei;
    }
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
            if((i<=flag)||(a[i]==0))
            {
            if(flag==200) flag=i+1;
            wei=jia1(1,i+1,wei,a);
            jud(a,wei);

            //printf("flag=%d\n",flag);
            }
            else
            {
                wei=jia1(-a[i+1],i+1,wei,a);
                jud(a,wei);
            }
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
        flag=200;
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
