#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

long long int pow(int n,int w)
{
    long long int x=1;
    for(int i=0;i<w;i++){
        x=x*n;
    }
    return x;
}

long long int change(char c)
{
    long long int x=0;
    if(isdigit(c)) x=c-'0';
    else x=c-'A'+10;
    return x;
}

int main()
{
    char s0[100];
    scanf("%s",s0);
    int length=strlen(s0)-2;
    long long int a=0,b=0,y=0;
    long long int r=0;
    if(length==1&&s0[2]=='0') printf("0");
    for (int k=0;k<length;k++){
    long long int x=change(s0[k+2]);
    int digit=4;
    for(int i=0;i<digit;i++){
        y=pow(2,digit-1-i);
        r=x&y;
        if(r>0) r=1;
        long long int a1=a,b1=b;
        a=r-a1-b1;
        b=a1-b1;
    }}
    if(a!=0) printf("%lld",a);
    if(b>0&&a!=0) printf("+");
    if(b>1) printf("%lldi",b);
    if(b==1) printf("i");
    if(b<-1) printf("%lldi",b);
    if(b==-1) printf("-i");
    return 0;
}
