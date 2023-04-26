#include<stdio.h>
#include<ctype.h>
int main(){
    char s[51],*c,yet;
    int n[127]={0};
    n['I']=1;n['V']=5;n['X']=10;n['L']=50;n['C']=100;n['D']=500;n['M']=1000;
    long long int num=0;
    int mul=1;
    scanf("%s",s);
    c=s;
    while(*c=='(')c++;
    yet=*c;
    c++;
    while(*c){
        if(*c==')')num*=1000;
        else if(*c==yet)mul++;
        else if(n[*c]<n[yet]){
            num+=mul*n[yet];
            mul=1;
        }
        else{
            num-=n[yet];
            mul=1;
        }

        yet=*c;
        c++;
    }
    num+=mul*n[*(c-1)];
    printf("%lld",num);
    return 0;
}