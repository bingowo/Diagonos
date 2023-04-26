#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int binary(long long int a,char *s){
    long long int i=1;
    int m = 0;
    do{*s='0'+(long long int)(a&i);m++,s++,a=a>>1;}
    while(a!=0);
    *s=0;
    return m;
}
int main(){
    long long int i,a,b,a1=0,b1=0;
    int m;
    char s[65],*s1,*s2,s3,sign;
    scanf("%x",&i);
    m=binary(i,s);
    s2=s;
    s1=s+m-1;
    while(s1>s2){s3=*s1;*s1=*s2;*s2=s3;s1--,s2++;}
    s1=s;
    for(;*s1;s1++){
        a=-a1-b1+*s1-'0';
        b=a1-b1;
        a1=a;
        b1=b;
    }
    if(a!=0){
    if(b<0){
        b=-b;
        sign='-';

    }
    else if(b>0)sign='+';
    else sign=0;
    if(b!=1&&b!=-1){printf("%lld",a);printf("%c",sign);if(sign)printf("%lldi",b);}
    else {printf("%lld",a);printf("%c",sign);if(sign)printf("i");}}
    else printf("%lldi",b);
    return 0;
}









