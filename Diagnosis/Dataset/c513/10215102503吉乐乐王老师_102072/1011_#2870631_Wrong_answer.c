#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef long long int lli;
typedef struct 
{
    lli real;
    lli imaginary;
}prural;
prural cal(prural ret,prural base ,int rmd){
    prural res;
    res.real=ret.real*base.real-ret.imaginary*base.imaginary;
    res.imaginary=ret.real*base.imaginary+ret.imaginary*base.real;
    res.real+=rmd;
    return res;
}
int main(){
    lli num;
    scanf("%llX",&num);
    int binary[1000];
    int i=0;
    do{
        binary[i++]=num%2;
        num/=2;
    }while(num);
    int rmd;
    prural ret,base;
    ret.real=0;ret.imaginary=0;
    base.real=-1;base.imaginary=1;
    for(int j=i-1;j>=0;j--){
        rmd=binary[j];
        ret=cal(ret,base,rmd);
    }
    if(ret.real==0&&ret.imaginary!=0){
        if(ret.imaginary==1||ret.imaginary==-1)printf(ret.imaginary==1?"i":"-i");
        else printf("%lldi",ret.imaginary);}
    else if(ret.imaginary==0&&ret.real!=0)printf("%lld",ret.real);
    else{
        printf("%lld",ret.real);
        if(ret.imaginary>0)putchar('+');
        if(ret.imaginary==1||ret.imaginary==-1)printf(ret.imaginary==1?"i":"-i");
        else printf("%lldi",ret.imaginary);}
}