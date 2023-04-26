#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int mi;
    int xishu;
}group;

int cmp(const void *a,const void*b)
{
    group aa=*((group*)a);
    group bb=*((group*)b);
    if(aa.mi>bb.mi) return -1;
    else if (aa.mi<bb.mi) return 1;
    else return -1;


}

int a2i(int st,int ed,char s[])
{
    int i,re=0;
    int flag;

    if(s[st]=='-') {if(st==ed) return -1;flag=-1;st++;}
    else if (s[st]=='+') {if(st==ed) return 1;flag=1;st++;}
    else flag=1;
    for(i=st;i<=ed;i++)
    {
        re*=10;
        re+=(s[i]-'0');

    }
    re*=flag;
    return re;
}

group tran(char s[])
{
    int len=strlen(s),i,en=len-1,st=0,sig=0;
    group re;
    for(i=0;i<len;i++)
    {

        if(s[i]=='x') {en=i-1;sig=1;}
        if(s[i]=='^') st=i+1;

    }
    if(en>=0) re.xishu=a2i(0,en,s);
    else re.xishu=1;
    if (st!=0) re.mi=a2i(st,len-1,s);
    else re.mi=sig;
    return re;

}

int clip(char s[],group a[])
{
    int len=strlen(s);
    int i,st=0,en,j,num[100],m=0,k;
    char part[100];
    for(i=1;i<len;i++)
    {

        if((s[i]=='+')||(s[i]=='-'))
        {
            en=i;
            memset(part,0,100*sizeof(char));
            for(j=st,k=0;j<en;j++)
            {
                part[k++]=s[j];
            }
            a[m++]=tran(part);
            st=en;
        }
    }
    memset(part,0,100*sizeof(char));
    for(i=st,k=0;i<len;i++)
    {
        part[k++]=s[i];
    }
    a[m++]=tran(part);
    return m;

}

int cheng(group a[],int nofa,group b[],int nofb,group re[])
{
    int i,j,k;
    for(i=0;i<nofa;i++)
    {
        for(j=0;j<nofb;j++)
        {
            re[k].mi=a[i].mi+b[j].mi;
            re[k].xishu=a[i].xishu*b[j].xishu;
            k++;
        }
    }
    return k;

}

int chongpai(group a[],int k,group b[])
{
    qsort(a,k,sizeof(group),cmp);
    int i,j;
    for(i=0,j=0;i<k-1;i++)
    {
        if(a[i].mi!=a[i+1].mi)
        {
            b[j].mi=a[i].mi;
            b[j].xishu=a[i].xishu;
            j++;
        }
        else
        {
            a[i+1].xishu+=a[i].xishu;
        }
    }
    b[j].mi=a[i].mi;
    b[j].xishu=a[i].xishu;
    j++;
    return j;

}

int main()
{
    int i,j;
    char fir[120],sec[120];
    group one[60],two[60],res[200],ans[60];
    memset(fir,0,sizeof(char)*120);
    memset(sec,0,sizeof(char)*120);

    while(1)
    {
        if(scanf("%s%s",fir,sec)==EOF) break;

        int nof1,nof2,nofr,nofans,n0=0;
        nof1=clip(fir,one);
        /*for(i=0;i<nof1;i++)
        {
            printf("test test: one的第%d项=%d x (%d)\n",i,one[i].xishu,one[i].mi);
        }*/
        nof2=clip(sec,two);
        /*for(i=0;i<nof2;i++)
        {
            printf("test test: two的第%d项=%d x (%d)\n",i,two[i].xishu,two[i].mi);
        }*/
        nofr=cheng(one,nof1,two,nof2,res);
        nofans=chongpai(res,nofr,ans);

        for(i=0;i<nofans-1;i++)
        {
            if(ans[i].xishu!=0) {printf("%d ",ans[i].xishu);n0++;}
        }
        if(ans[i].xishu!=0) {printf("%d\n",ans[i].xishu);n0++;}
        if(n0==0) printf("%d\n",n0);
        memset(fir,0,sizeof(char)*120);
        memset(sec,0,sizeof(char)*120);
    }
    return 0;
}