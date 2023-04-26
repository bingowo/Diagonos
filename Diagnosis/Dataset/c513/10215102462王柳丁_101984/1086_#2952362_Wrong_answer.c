#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct num
{
    int i[1000];
    int d[1000];
    int cnti;
    int cntd;
}FLOAT;//a int b dec
FLOAT CTF(char *a);
void MINUS(FLOAT a,FLOAT b,int n);
FLOAT trans(FLOAT a);
int main()
{
   int k,n;
   char a[1000],b[1000];
   while(scanf("%s",a)!=EOF&&scanf("%s",b)!=EOF&&scanf("%d",&n)!=EOF)
   {
       FLOAT A=CTF(a);
       FLOAT B=CTF(b);
       /*for(k=0;k<A.cnti;k++)
       {printf("%d",A.i[k]);}
       for(k=0;k<A.cntd;k++)
       {printf("%d",A.d[k]);}
       printf("\n");
       for(k=0;k<B.cnti;k++)
       {printf("%d",B.i[k]);}
       for(k=0;k<B.cntd;k++)
       {printf("%d",B.d[k]);}
       printf("\n");*/
       MINUS(A,B,n);
   }
   return 0;
}
FLOAT CTF(char *a)
{
    int k=0;
    FLOAT res;
    res.i[0]=0;
    res.d[0]=0;
    res.cnti=0;res.cntd=0;
    while(a[k]!='.'&&k<strlen(a))
    {
        res.i[res.cnti++]=a[k]-'0';k++;
    }
    if(k==strlen(a)-1)return res;
    else if(a[k]=='.')
    {
        k++;
        while(k<strlen(a))
        {
            res.d[res.cntd++]=a[k]-'0';k++;
        }
    }
    return res;
}
FLOAT trans(FLOAT a)
{
    int m,mid;
    for(m=0;m<a.cnti/2;m++)
    {
        mid=a.i[m];
        a.i[m]=a.i[a.cnti-m-1];
        a.i[a.cnti-m-1]=mid;
    }
    return a;
}
void MINUS(FLOAT a,FLOAT b,int n)
{
    int k=0,sign=1;
    FLOAT res;
    res.cntd=0;res.cnti=0;
    if(a.cnti<b.cnti){FLOAT T=a;a=b;b=T;sign=-1;}
    else if(a.cnti==b.cnti)
    {
        for(;k<a.cnti;k++)
        {
            if(a.i[k]<b.i[k]){FLOAT T=a;a=b;b=T;sign=-1;break;}
            else if(a.i[k]>b.i[k])break;
        }
        if(k==a.cnti-1)
        {
            for(k=0;k<a.cntd&&k<b.cntd;k++)
            {
                if(a.i[k]<b.i[k]){FLOAT T=a;a=b;b=T;sign=-1;break;}
                else if(a.i[k]>b.i[k])break;
            }
            if(k==a.cntd-1&&k<b.cntd-1){FLOAT T=a;a=b;b=T;}
        }
    }//排除所有a<b的情况
    int record=0,t=0;
    if(a.cntd>b.cntd)
    {
        for(k=b.cntd;k<a.cntd;k++){b.d[b.cntd++]=0;}
    }
    res.cntd=a.cntd;
    for(k=a.cntd-1;k>=0;k--)
    {
        t=a.d[k]-b.d[k]-record;
        if(t<0){t=10+t;record=1;res.d[k]=t;}
        else {record=0;res.d[k]=t;}
    }//小数部分的比较
    a=trans(a);b=trans(b);
    for(k=0;k<b.cnti;k++)
    {
        t=a.i[k]-b.i[k]-record;
        if(t<0){t=10+t;record=1;res.i[res.cnti++]=t;}
        else {record=0;res.i[res.cnti++]=t;}
    }
    for(;k<a.cnti;k++)
    {
        t=a.i[k]-record;
        if(t<0){t=10+t;record=1;res.i[res.cnti++]=t;}
        else {record=0;res.i[res.cnti++]=t;}
    }//整数部分的比较
    //四舍五入
    int m=0;
    if(res.cntd<=n)
    {
        for(m=res.cntd;m<=n+1;m++){res.d[m]==0;}
    }
    record=0;
    if(res.d[n]>4)record++;
    for(m=n-1;m>=0;m--)
    {
        t=res.d[m]+record;
        if(t>9){t=t-10;record=1;}
        else record=0;
        res.d[m]=t;
    }
    for(m=0;m<res.cnti;m++)
    {
        t=res.i[m]+record;
        if(t>9){t=t-10;record=1;}
        else record=0;
        res.d[m]=t;
    }
    if(record!=0)res.i[res.cnti++]=1;
    if(sign==-1)printf("-");
    k=res.cnti-1;
    while(res.i[k]==0)k--;
    if(k==0)printf("0");
    for(;k>=0;k--){printf("%d",res.i[k]);}
    printf(".");
    for(k=0;k<n;k++)
    {
        printf("%d",res.d[k]);
    }
    printf("\n");
}



