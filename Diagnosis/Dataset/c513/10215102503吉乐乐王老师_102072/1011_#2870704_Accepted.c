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
    char hex[1000];
    scanf("%s",hex);
    int binary[1000];
    int idx=3;
    for(int i=2;i<strlen(hex);i++){
        int num=hex[i]>='A'?hex[i]-'A'+10:hex[i]-'0';
        int i=idx;
        for(int j=0;j<4;j++){
            binary[i--]=num%2;
            num/=2;
        }
        idx+=4;
    }
    idx-=4;
    int rmd;
    prural ret,base;
    ret.real=0;ret.imaginary=0;
    base.real=-1;base.imaginary=1;
    for(int j=0;j<=idx;j++){
        rmd=binary[j];
        ret=cal(ret,base,rmd);
    }
    if(ret.real==0&&ret.imaginary!=0){
        if(ret.imaginary==1||ret.imaginary==-1)printf(ret.imaginary==1?"i":"-i");
        else printf("%lldi",ret.imaginary);}
    else if(ret.imaginary==0&&ret.real!=0)printf("%lld",ret.real);
    else if(ret.imaginary==0&&ret.real==0)printf("0");
    else{
        printf("%lld",ret.real);
        if(ret.imaginary>0)putchar('+');
        if(ret.imaginary==1||ret.imaginary==-1)printf(ret.imaginary==1?"i":"-i");
        else printf("%lldi",ret.imaginary);}
}