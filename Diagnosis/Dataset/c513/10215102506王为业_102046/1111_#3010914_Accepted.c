//simu\1110.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
/*
    
*/


#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;

#define OP 20
char output[42][42];
char sfunc[60];
int arr[5]={0};
int firstline=TRUE;

long long npow(int coe,int pow)
{
    LL ret=1;
    while(pow!=0){
        ret*=coe;
        --pow;
    }
    return ret;
}

void get_func(char *sc)
{
    while(*sc){
        int nega=FALSE;;
        if(*sc=='-'){
            nega=TRUE;
            ++sc;
        }else if(*sc=='+'){
            nega=FALSE;
            ++sc;
        }
        int coef=1,pow=0;
        if(isdigit(*sc)){
            coef=0;
            do{
                coef=coef*10+*sc-'0';
                ++sc;
            }while(isdigit(*sc));
        }
        if('x'==*sc){
            pow=1;
            ++sc;
            if(*sc=='^'){
                ++sc;
                pow=0;
                do{
                    pow=pow*10+*sc-'0';
                    ++sc;
                }while(isdigit(*sc));
            }
        }
        arr[pow]=nega?-coef:coef;
    }
    
}

void initialize()
{
    memset(output,'.',42*sizeof(output[0]));
    for(int i=-20;i<=20;++i){
        output[OP][OP+i]='|';
        output[OP+i][OP]='-';
    }
    output[OP][OP]='+';
    output[OP][OP+20]='^';
    output[OP+20][OP]='>';
}

int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    firstline=TRUE;
    while(scanf("%s",sfunc)!=EOF){
        initialize();
        memset(arr,0,5*sizeof(arr[0]));
        get_func(sfunc+5);
        long long temy=0;
        for(int ix=-20;ix<=20;++ix){
            temy=0;
            for(int i=0;i<4;++i){
                if(arr[i]!=0)
                    temy+=arr[i]*npow(ix,i);
            }
            if(-20<=temy&&temy<=20){
                output[ix+OP][temy+OP]='*';
            }
        }
        //output area------------
        if(firstline){
            firstline=FALSE;
        }else{
            putchar('\n');
        }
        for(int iy=40;iy>=0;--iy){
            for(int ix=0;ix<=40;++ix){
                putchar(output[ix][iy]);
            }
            putchar('\n');
        }

    }
}