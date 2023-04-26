#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int binary(long long int a,char *s){
    long long int i=1;
    int m = 0;
    for(;a!=0;m++,s++,a=a>>1){*s='0'+(int)(a&i);}
    *s=0;
    return m;
}
int main(){
    long long int i,a,b,a1=0,b1=0;
    int m;
    char s[65],*s1;
    scanf("%x",&i);
    m=binary(i,s);
    s1=s;
    for(;*s1;s1++){
        a=-a1-b1+*s1-'0';
        b=a1-b1;
        a1=a;
        b1=b;
    }
    if(b<0)printf("%lld%lldi",a,b);
    if(b==0)printf("%lld",a);
    else printf("%lld+%lldi",a,b);
    return 0;
}







