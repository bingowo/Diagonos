//digsys\1013.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>

//#define LOCAL
#define TRUE 1
#define FALSE 0

long long GCD(long long x,long long y)//x>y
{
    if(y==0)return x;
    else return GCD(y,x%y);
}
char inte[40];
char doub[40];
int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    char c;
    int in=0;
    int id=0;
    while((c=getchar())!='\n'&&c!='.'){
        inte[in++]=c;
    }
    long long num=0;
    if(inte[0]!='0'){
        //pr inte A
        long long tem=1;
        for(int i=in-1;i>=0;--i){
            switch(inte[i]){
            case'2':
                num-=tem;
                break;
            case'1':
                num+=tem;
                break;
            }
            tem*=3;
        }
    }
    if(c=='.'){
        while((c=getchar())!='\n'){
            doub[id++]=c;
        }
        long long deno=1,nume=0;
        for(int i=id-1;i>=0;--i){
            switch(doub[i]){
            case'2':
                nume-=deno;
                break;
            case'1':
                nume+=deno;
                break;
            }
            deno*=3;
        }
        if(nume<0&&num>0){
            --num;
            nume+=deno;
        }else if(nume>0&&num<0){
            ++num;
            nume=deno-nume;
        }
        long long tem;
        if(nume<0)
            tem=GCD(deno,-nume);
        else
            tem=GCD(deno,nume);
        if(num!=0)printf("%lld ",num);
        printf("%lld %lld",nume/tem,deno/tem);
    }
    else{//no point
        printf("%lld ",num);
    }
}
