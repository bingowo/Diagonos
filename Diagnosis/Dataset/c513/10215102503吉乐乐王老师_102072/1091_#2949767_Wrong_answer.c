#include<stdio.h>
#include<stdlib.h>
#define N 1000
typedef struct{
    long long int real;
    long long int ima;
}com;
void mult(com *a,com *b){
    com ret=*a,base=*b;
    com temp;
    temp.real=ret.real*base.real-ret.ima*base.ima;
    temp.ima=ret.real*base.ima+ret.ima*base.real;
    *a=temp;
}
int main(){
    char s[100];
    int n;
    scanf("%s %d",s,&n);
    com base;base.real=0;base.ima=0;
    char *p=s;
    while(*p){
        if(*p=='-'){
            int sign=-1;
            int num=0;
            p++;
            if(*p&&*p=='i'){base.ima=-1;break;}
            while(*p&&*p!='i'&&*p!='-'&&*p!='+'){
                num=num*10+*p-'0';p++;
            }
            if(*p&&*p=='i'){base.ima=-num;break;}
            else{base.real=-num;continue;}
        }
        else if(*p=='+'){
            int num=0;
            p++;
            if(*p&&*p=='i'){base.ima=1;break;}
            while(*p&&*p!='i'&&*p!='-'&&*p!='+'){
                num=num*10+*p-'0';p++;
            }
            base.ima=num;break;
        }
        else if(*p=='i'){base.ima=1;break;}
        else{
            int num=0;
            while(*p>='0'&&*p<='9'){
                num=num*10+*p-'0';p++;
            }
            base.real=num;continue;
        }
    }
    com ret=base;
    for(int i=1;i<n;i++){
        mult(&ret,&base);
    }
    if(ret.ima){
        if(ret.real){
            printf("%lld",ret.real);
            if(ret.ima>0)putchar('+');
            printf("%lldi",ret.ima);}
        else printf("%lldi",ret.ima);
    }
    else printf("%llu",ret.real);
}