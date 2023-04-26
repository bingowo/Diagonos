#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 500

typedef struct
{
    int shu[500];
    int wei;
}bigint;

int jinzhi[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,91,97};


bigint reverse(bigint a)
{
    int i,c;
    for(i=0;i<(a.wei/2);i++)
    {
        c=a.shu[i];
        a.shu[i]=a.shu[a.wei-i-1];
        a.shu[a.wei-1-i]=c;
    }
    return a;
}

int splitstring(char s[],char sign,bigint a[],int nmax)
{
    int len=strlen(s),i,j,st=0,en,co=0,k;
    for(i=0;i<len;i++)
    {
        if(s[i]==sign)
        {
            en=i;
            for(j=st,k=0;j<en;j++,k++)
            {
                a[co].shu[k]=s[j]-'0';
            }
            a[co].wei=k;
            co++;
            st=en+1;

        }
        if(co>=nmax-1) break;
    }
    for(j=st,k=0;j<len;j++,k++)
    {
        a[co].shu[k]=s[j]-'0';

    }
    a[co].wei=k;
    co++;
    return co;
}

bigint singlecheng(bigint a,int x)
{
    //printf("singlecheng\n");
    bigint re;
    memset(re.shu,0,sizeof(int)*M);
    int i,jin=0,mid;
    for(i=0;(i<a.wei)||jin!=0;i++)
    {
        mid=a.shu[i]*x+jin;
        re.shu[i]=mid%10;
        jin=mid/10;
    }
    re.wei=i;
    return re;
}

bigint moveadd0(bigint a,int k)
{
    //printf("moveadd0\n");
    int i,j;
    bigint re;
    memset(re.shu,0,sizeof(int)*M);
    for(i=a.wei-1+k,j=a.wei-1;i>=0;i--,j--)
    {
        if(j<0) re.shu[i]=0;
        else re.shu[i]=a.shu[j];
    }
    re.wei=a.wei+k;
    return re;
}

bigint zhengjia(bigint a,bigint b)
{
    //printf("zhengjia\n");
    int i,du,jin=0;
    bigint re;
    memset(re.shu,0,sizeof(int)*M);
    for(i=0;(i<a.wei)||(i<b.wei)||(jin!=0);i++)
    {
        du=a.shu[i]+b.shu[i]+jin;
        re.shu[i]=du%10;
        jin=du/10;
    }
    re.wei=i;
    return re;
}

bigint cheng(bigint a,bigint b)
{
    int i,j,co=0;
    bigint re,mid;
    memset(re.shu,0,sizeof(int)*M);
    memset(mid.shu,0,sizeof(int)*M);
    int x[M];
    memset(x,0,sizeof(int)*M);
    re.wei=1;
    mid.wei=1;
    for(i=0;i<b.wei;i++)
    {
        x[i]=b.shu[i];
    }
    for(i=0;i<b.wei;i++)
    {
        mid=singlecheng(a,x[i]);
        mid=moveadd0(mid,i);
        re=zhengjia(re,mid);
    }

    return re;
}

int main()
{
    char s[200];
    gets(s);
    int co,i,j,cs;
    bigint a[26],re;
    char su[]="2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,91,97";
    //jinzhi
    bigint sushu[26];
    cs=splitstring(su,',',sushu,26);

    for(i=0;i<cs;i++)
    {
        sushu[i]=reverse(sushu[i]);
    }
    //for(i=0;i<cs;i++) {printf("sushu[%d]=",i);for(j=0;j<sushu[i].wei;j++) printf("%d",sushu[i].shu[j]);printf("\n");}
    re.wei=1;
    memset(re.shu,0,sizeof(int)*200);
    co=splitstring(s,',',a,26);
    for(i=0;i<co;i++)
    {
        a[i]=reverse(a[i]);
    }
    //for(i=0;i<co;i++) {printf("a[%d]=",i);for(j=0;j<a[i].wei;j++) printf("%d",a[i].shu[j]);printf("\n");}

    for(i=0;i<co;i++)
    {
        re=cheng(re,sushu[co-i-1]);
         /*printf("test：");
        for(j=0;j<re.wei;j++) printf("%d",re.shu[j]);
        printf(" & ");*/
        re=zhengjia(re,a[i]);
        /*printf("test：");
        for(j=0;j<re.wei;j++) printf("%d",re.shu[j]);
        printf("\n");*/

    }
    //printf("in main re.wei=%d\n",re.wei);
    re=reverse(re);
    for(i=0;i<re.wei;i++) printf("%d",re.shu[i]);
    printf("\n");

}
