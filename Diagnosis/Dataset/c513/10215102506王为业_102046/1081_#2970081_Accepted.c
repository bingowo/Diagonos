//math\1081.c


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <ctype.h>
/*
    one word pressure test
*/

//#define LOCAL
#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;
#define MAXLEN 500
int retlen;
int* highac_mult(const int*x,const int xlen,const int*y,const int ylen)
{

    static int ret[MAXLEN]={0};//memset?
    memset(ret,0,MAXLEN*sizeof(ret[0]));
    for(int ix=0;ix<xlen;++ix){
        for(int iy=0;iy<ylen;++iy){
            ret[ix+iy]+=x[ix]*y[iy];
        }
    }
    for(int i=0;i<MAXLEN-1;++i){
        if(ret[i]>=10){
            ret[i+1]+=ret[i]/10;
            ret[i]%=10;
        }
    }
    retlen=MAXLEN-1;
    while(ret[retlen]==0)
        --retlen;
    ++retlen;//key
    return ret;
}

void copy_from(int* to,int *len_add,const int*from)
{
    *len_add=retlen;
    for(int i=0;i<retlen;++i){
        to[i]=from[i];
    }
}

char str [MAXLEN];
int tem_a[MAXLEN];
int alen;
int ans[MAXLEN];
int anslen;
int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int T;
    scanf("%d",&T);
    getchar();
    for(int iT=0;iT<T;++iT){
        printf("case #%d:\n",iT);
        scanf("%s",str);
        alen=strlen(str);
        anslen=1;
        memset(ans,0,MAXLEN*sizeof(ans[0]));
        ans[0]=1;
        for(int i=0,j=alen-1;i<j;++i,--j){
            char t=str[i];
            str[i]=str[j];
            str[j]=t;
        }
        for(int i=0;i<alen;++i){
            tem_a[i]=str[i]-'0';
        }
        //swap and change value
        int n;
        scanf("%d",&n);
        while(n!=0){
            if(n&1){
                copy_from(ans,&anslen,highac_mult(tem_a,alen,ans,anslen));
                //ans*=tem_a
            }
            copy_from(tem_a,&alen,highac_mult(tem_a,alen,tem_a,alen));
            n>>=1;
        }
        for(int i=anslen-1;i>=0;--i){
            putchar(ans[i]+'0');
        }
        putchar('\n');
    }
}

