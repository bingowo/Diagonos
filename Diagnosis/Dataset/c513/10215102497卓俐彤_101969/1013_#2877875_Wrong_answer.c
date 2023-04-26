#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxstr 500

long long int gcd(long long int m,long long int n){
    long long int res,t;
    if(m<0)m=-m;
    if(n<0)n=-n;
    res=m;
    while(n){
        t=res%n;
        res=n;
        n=t;
    }
    return res;
}

int main(){
    char s[maxstr];
    scanf("%s",s);
    char *p=s;
    long long int a=0,b=0,c=1;
    int flag1=0,flag2=0;
    while(*p&&*p!='.'){
        a*=3;
        if(*p=='1')a+=1;
        if(*p=='2')a-=1;
        p++;
    }
    if(*p=='.'){
        flag1=1;
        if(a!=0)flag2=1;
        while(*p++){
            c*=3;
            b*=3;
            if(*p=='1')b+=1;
            if(*p=='2')b-=1;
        }
        long long int res=gcd(c,b);
        b=b/res;
        c=c/res;
        if(b<0&&a>0){
            a-=1;
            b+=c;
        }
        if(b>0&&a<0){
            a+=1;
            b=c-b;
        }
    }
    if(a!=0)printf("%lld",a);
    if(flag2)printf(" ");
    if(flag1)printf("%lld %lld",b,c);
    printf("\n");
    return 0;
}
