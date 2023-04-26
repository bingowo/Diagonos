//digsy\1094.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
/*
    one word pressure test
*/

//#define LOCAL
#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;

#define MAXLEN 150

struct highac_num{
    char num[MAXLEN];
    int len;
    int negtive;
};
typedef struct highac_num bigint;

int big_int_cmp(bigint*x, bigint*y)
{
    if(x->negtive ^ y->negtive ==0){
        if(x->len==y->len){
            for(int i=x->len-1;i>=0;--i){
                if(x->num[i] > y->num[i]){
                    return x->negtive?-1:1;
                }else if(x->num[i] < y->num[i]){
                    return y->negtive?1:-1;
                }
            }
            return 1;//equal
        }else{
            if(x->len > y->len){
                return x->negtive?-1:1;
            }else{
                return y->negtive?1:-1;
            }
        }
    }else{
        if(x->negtive){
            return -1;
        }else{
            return 1;
        }
    }
    return 1;//bug area
}

void abs_add(bigint*res,const bigint*x,const bigint*y)
{
    memset(res,0,sizeof(res[0]));
    int commonlen=x->len > y->len? x->len:y->len;
    for(int i=0;i<commonlen;++i){
        res->num[i]+=x->num[i]+y->num[i];//clarify ++ +=
        res->num[i+1]+=res->num[i]/10;
        res->num[i]%=10;
    }
    if(res->num[commonlen]!=0){
        ++commonlen;
    }
    res->len=commonlen;
}
void abs_minus(bigint* res,const bigint*larger,const bigint*smaller)
{
    int commonlen=larger->len > smaller->len?larger->len:smaller->len;
    int before=0;
    for(int i=0;i<commonlen;++i){
        res->num[i]=larger->num[i]-smaller->num[i]+before;
        if(res->num[i]<0){
            res->num[i]+=10;
            before=-1;
        }else{
            before=0;
        }
    }
    if(res->num[commonlen-1]==0)
        --commonlen;
    res->len=commonlen;
}

bigint tem_buf;
bigint big_int_minus(bigint*x,bigint*y)//return x-y
{
    if(x->negtive ^ y->negtive){
        if(x->negtive){//x<0,y>0//-|x|-|y|
            abs_add(&tem_buf,x,y);
            tem_buf.negtive=TRUE;
        }else{//x>0,y<0//|x|+|y|
            abs_add(&tem_buf,x,y);
            tem_buf.negtive=FALSE;
        }
    }else{
        if(x->negtive){//x<0,y<0,calc:|y|-|x|
            if(big_int_cmp(y,x)>0){//y>x,|y|<|x|
                abs_minus(&tem_buf,x,y);
                tem_buf.negtive=TRUE;
            }else{//y<x,|x|<|y|
                abs_minus(&tem_buf,y,x);
                tem_buf.negtive=FALSE;
            }
        }else{//x>0,y>0,calc:|x|-|y|
            if(big_int_cmp(y,x)>0){//|y|>|x|
                abs_minus(&tem_buf,y,x);
                tem_buf.negtive=TRUE;
            }else{
                abs_minus(&tem_buf,x,y);
                tem_buf.negtive=FALSE;
            }
        }
    }
    return tem_buf;
}
bigint arr[51];

void get_big_int(bigint * x)
{
    x->len=0;
    char c=getchar();
    if(c=='-'){
        x->negtive=TRUE;
    }else{
        x->negtive=FALSE;
        x->num[x->len++]=c-'0';
    }

    while((c=getchar())!='\n'&&c!=EOF){
        x->num[x->len++]=c-'0';
    }

    for(int i=0,j=x->len -1;i<j;++i,--j){
        c=x->num[i];
        x->num[i]=x->num[j];
        x->num[j]=c;
    }
}

int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int n;
    scanf("%d",&n);
    getchar();
    for(int in=0;in<n;++in){
        get_big_int(arr+in);
    }
    qsort(arr,n,sizeof(arr[0]),big_int_cmp);
/*
    for(int in=0;in<n;++in){
        if(arr[in].negtive)
            putchar('-');
        for(int i=arr[in].len-1;i>=0;--i){
            printf("%d",arr[in].num[i]);
        }
        putchar('\n');
    }
    printf("ANS:\n");
*/
    bigint result=big_int_minus(&arr[n-1],&arr[0]);
    if(result.negtive)
        putchar('-');
    for(int i=result.len-1;i>=0;--i){
        printf("%d",result.num[i]);
    }
    putchar('\n');
}

