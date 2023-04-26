#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int zhuanint(char *x,int r[])
{
    int i,j;
    int len=strlen(x);
    for(i=0;i<len;i++)
    {
        r[i]=x[i]-'0';
    }
    return len;
}

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

int jian(int *a,int la,int* b,int lb,int* re)
{
    reverse(a,la);
    reverse(b,lb);
    int i,j,k,en,wei;
    /*for(i=0;(i<la)||(i<lb);i++)
    {
        printf("reverse test:a[%d]=%d\n",i,a[i]);

    }
    for(i=0;(i<la)||(i<lb);i++)
    {
        printf("reverse test:b[%d]=%d\n",i,b[i]);
    }*/

    for(i=0;i<la;i++)
    {
        if(a[i]>=b[i]) re[i]=a[i]-b[i];
        else
        {
            for(j=i;j<la;j++)
            {
                if(a[j+1]>0) {en=j+1;a[j+1]--;break;}
            }
            for(k=en-1;k>i;k--)
            {
                a[k]+=9;
            }
            a[i]+=10;
            re[i]=a[i]-b[i];
        }
        //printf("test:re[%d]=%d\n",i,re[i]);
    }
    wei=la;
    reverse(re,wei);
    return wei;

}

int cmp(int *a,int*b,int la,int lb)
{
    int i;
    if(la>lb) return 1;
    else if(la<lb) return -1;
    else
    {
        for(i=0;i<la;i++)
        {
            if(a[i]>b[i]) return 1;
            else if(a[i]<b[i]) return -1;
        }
        return 0;
    }
}
int main()
{
    while(1)
    {
        char a[510],b[510];
        int aa[510],bb[510],la,lb,re[510],flag=0,i,st=0,wei;
        memset(aa,0,sizeof(int)*510);
        memset(bb,0,sizeof(int)*510);
        memset(re,0,sizeof(int)*510);
        if(scanf("%s%s",a,b)==EOF) break;
        la=zhuanint(a,aa);
        lb=zhuanint(b,bb);

        int jud=cmp(aa,bb,la,lb);
        if(jud==1)
            {
                wei=jian(aa,la,bb,lb,re);
                for(i=0;i<wei;i++)
                {
                    if(re[i]!=0) {st=i;break;}
                }
                for(i=st;i<wei;i++)
                {
                    printf("%d",re[i]);
                }
                printf("\n");
            }
        else if(jud==-1)
            {
                wei=jian(bb,lb,aa,la,re);
                for(i=0;i<wei;i++)
                {
                    if(re[i]!=0) {st=i;break;}
                }
                printf("-");
                for(i=st;i<wei;i++)
                {
                    printf("%d",re[i]);
                }
                printf("\n");
            }
            else printf("0\n");
    }
    return 0;
}