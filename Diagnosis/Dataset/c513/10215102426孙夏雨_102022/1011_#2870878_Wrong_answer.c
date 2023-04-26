#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

long long int pow(int b,int n)
{
    long long int a=1;
    for(int i=0;i<n;i++) a*=b;
    return a;
}

long long int change(char* s,int length)
{
    long long int x=0;
    for(int i=0;i<length;i++){
        long long int y=0;
        if(isdigit(s[i+2])) y=(s[i+2]-'0')*pow(16,length-1-i);
        else y=(s[i+2]-'A'+10)*pow(16,length-1-i);
        x+=y;
    }
    return x;
}

int count(long long int x)
{
    int digit=0;
    while(x>0){
        digit++;
        x=x>>1;
    }
    return digit;
}

int main()
{
    char *s0[100];
    scanf("%s",s0);
    int length=strlen(s0)-2;
    long long int x=change(s0,length);
    long long int a=0,b=0,y=0;
    long long int r=0;
    int digit=count(x);
    if(digit==0) printf("0");
    for(int i=0;i<digit;i++){
        y=pow(2,digit-1-i);
        r=x&y;
        if(r>0) r=1;
        long long int a1=a,b1=b;
        a=r-a1-b1;
        b=a1-b1;
    }
    if(a!=0) printf("%lld",a);
    if(b>0&&a!=0) printf("+");
    if(b>1) printf("%lldi",b);
    if(b==1) printf("i");
    if(b<-1) printf("%lldi",b);
    if(b==-1) printf("-i");
    return 0;
}
