#include<stdio.h>
#include<ctype.h>
int main(){
    char s[51],*c,yet;
    int n[127]={0};
    n['I']=1;n['V']=5;n['X']=10;n['L']=50;n['C']=100;n['D']=500;n['M']=1000;
    long long int num=0,p[2]={0};
    int mul=1,xmul=1;
    scanf("%s",s);
    c=s;
    yet=*c;
    c++;
    while(*c){
        if(*c=='(')xmul=0;
        if(*c==yet)mul++;
        else if(n[*c]<n[yet]){
            p[xmul]+=mul*n[yet];
            mul=1;
        }
        else{
            p[xmul]-=n[yet];
            mul=1;
        }
        yet=*c;
        c++;
        if(*c==')')p[xmul]*=1000;
    }
    p[xmul]+=mul*n[*(c-1)];
    num=p[0]+p[1];
    printf("%lld",num);
    return 0;
}