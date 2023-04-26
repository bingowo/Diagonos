#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct num
{
    int i[1000];
    int d[1000];
    int cnti;
    int cntd;
}FLOAT;//a int d dec
FLOAT CTF(char *a);
void MINUS(FLOAT a,FLOAT b,int n);
FLOAT trans(FLOAT a);
int main()
{
   int n,z;
   char a[1000],b[1000];
   scanf("%s",a);
   scanf("%s",b);
   scanf("%d",&n);
   FLOAT A=CTF(a);
   FLOAT B=CTF(b);
   A=trans(A);
   B=trans(B);
     /*  for(z=0;z<A.cnti;z++)
       {printf("%d",A.i[z]);}
       printf(".");
       for(z=0;z<A.cntd;z++)
       {printf("%d",A.d[z]);}
       printf("\n");
       for(z=0;z<B.cnti;z++)
       {printf("%d",B.i[z]);}
       printf(".");
       for(z=0;z<B.cntd;z++)
       {printf("%d",B.d[z]);}
       printf("\n");*/
    MINUS(A,B,n);
   return 0;
}
FLOAT CTF(char *a)
{
    int k=0;
    FLOAT res;
    res.i[0]=0;
    res.d[0]=0;
    res.cnti=0;res.cntd=0;
    if(a[0]=='.'){res.cnti=1;res.i[0]=0;}
    while(k<strlen(a)&&a[k]!='.')
    {
        res.i[res.cnti++]=a[k]-'0';k++;
    }
    if(k==strlen(a)-1){res.cntd=1;res.d[0]=0;return res;}//无小数
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
    //排除a<b
    if(a.cnti<b.cnti){FLOAT T=a;a=b;b=T;sign=-1;}
    else if(a.cnti==b.cnti)
    {
        for(k=a.cnti-1;k>=0;k++)
        {
            if(a.i[k]<b.i[k]){FLOAT T=a;a=b;b=T;sign=-1;break;}
            else if(a.i[k]>b.i[k])break;
        }
        if(k==0)
        {
            for(k=0;k<a.cntd&&k<b.cntd;k++)
            {
                if(a.i[k]<b.i[k]){FLOAT T=a;a=b;b=T;sign=-1;break;}
                else if(a.i[k]>b.i[k])break;
            }
            if(k==a.cntd-1&&k<b.cntd-1&&(a.i[k]==b.i[k])){FLOAT T=a;a=b;b=T;}
        }
    }//排除所有a<b的情况
    int record=0,t=0;
    if(a.cntd>b.cntd)
    {
        k=b.cntd;
        for(;k<a.cntd;k++){b.d[b.cntd++]=0;}
    }
    if(a.cntd<b.cntd)
    {
        k=a.cntd;
        for(;k<b.cntd;k++){a.d[a.cntd++]=0;}
    }
    res.cntd=a.cntd;
    for(k=a.cntd-1;k>=0;k--)
    {
        t=a.d[k]-b.d[k]-record;
        if(t<0){t=10+t;record=1;res.d[k]=t;}
        else {record=0;res.d[k]=t;}
    }//小数部分的比较
    //a=trans(a);b=trans(b);
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
    /* if(sign==-1)printf("-");
    k=res.cnti-1;
    while(res.i[k]==0)k--;
    if(k==-1)printf("0");
    else
    {
        for(;k>=0;k--){printf("%d",res.i[k]);}

    }
    printf(".");
    for(k=0;k<res.cntd;k++)
    {
        printf("%d",res.d[k]);
    }
    printf("\n");*/
    //四舍五入
    int m=0;
    if(res.cntd<=n)
    {
        for(m=res.cntd;m<=n;m++){res.d[res.cntd++]=0;}
    }//补0
    record=0;
    if(res.d[n]>4)record=1;
    for(m=n-1;m>=0;m--)
    {
        t=res.d[m]+record;
        if(t>9){t=t-10;record=1;}
        else record=0;
        res.d[m]=t;
        //printf("(%d)",res.d[m]);
    }
    for(m=0;m<res.cnti;m++)
    {
        t=res.i[m]+record;
        if(t>9){t=t-10;record=1;}
        else record=0;
        res.i[m]=t;
    }
    if(record!=0)res.i[res.cnti++]=1;
    if(sign==-1)printf("-");
    k=res.cnti-1;
    while(res.i[k]==0&&k>0)k--;
    if(k==0)printf("0");
    else
    {
        for(;k>=0;k--){printf("%d",res.i[k]);}

    }
    printf(".");
    for(k=0;k<n;k++)
    {
        printf("%d",res.d[k]);
    }
    printf("\n");
}
