//digsys\1018.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>

//#define LOCAL
#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;

#define ARRLEN 200
int prime[27];
int dignum[ARRLEN];
int weight[ARRLEN]={1,0,0};
int temwei[ARRLEN]={1,0,0};
int result[ARRLEN];
int isprime(int x)
{
    for(int k=2;k<=sqrt(x);++k){
        if(x%k==0)
            return FALSE;
    }
    return TRUE;
}
void createPRIME()
{
    int i=2;
    int len=0;
    prime[len++]=1;//1 is not a prime,but simplify the problem
    while(len<25){
        if(isprime(i)){
            prime[len++]=i;
        }
        ++i;
    }
}

int rlen_highACtime(int highac[],int highlen,int lowac,int res[])
{
    for(int i=0;i<highlen;++i){
        res[i]=highac[i]*lowac;
    }
    for(int i=0;i<ARRLEN-1;++i){
        if(res[i]>=10){
            res[i+1]+=res[i]/10;
            res[i]%=10;
        }
    }
    int reslen=ARRLEN-1;
    while(res[reslen]==0)--reslen;
    return reslen+1;
}
int hlen_highACtime(int highac[],int highlen,int lowac)
{
    for(int i=0;i<highlen;++i){
        highac[i]=highac[i]*lowac;
    }
    for(int i=0;i<ARRLEN-1;++i){
        if(highac[i]>=10){
            highac[i+1]+=highac[i]/10;
            highac[i]%=10;
        }
    }
    highlen=ARRLEN-1;
    while(highac[highlen]==0)--highlen;
    return highlen+1;
}
int alen_highACadd(int a[],int b[],int alen,int blen)
{
    int larlen=alen<blen?blen:alen;
    for(int i=0;i<larlen;++i){
        a[i]+=b[i];
        if(a[i]>=10){
            a[i+1]=a[i]/10;
            a[i]%=10;
        }
    }
    return a[larlen]?larlen+1:larlen;
}

int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    createPRIME();
    int inlen=0;
    while(scanf("%d",&dignum[inlen])==1){
        ++inlen;
        if(getchar()==EOF)break;
    }
    for(int i=0,j=inlen-1;i<j;++i,--j){
        int tem=dignum[i];
        dignum[i]=dignum[j];
        dignum[j]=tem;
    }
    //from low to high
    int wei_len=1;
    int temweiLEN=1;
    int reslen=1;
    for(int ipos=0;ipos<inlen;++ipos){
        wei_len=hlen_highACtime(weight,wei_len,prime[ipos]);
        if(dignum[ipos]!=0){
            memset(temwei,ARRLEN,sizeof(temwei[0]));
            temweiLEN=rlen_highACtime(weight,wei_len,dignum[ipos],temwei);
            reslen=alen_highACadd(result,temwei,reslen,temweiLEN);
        }
    }
    for(int i=reslen-1;i>=0;--i){
        printf("%d",result[i]);
    }
}
