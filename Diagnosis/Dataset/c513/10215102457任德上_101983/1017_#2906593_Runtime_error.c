#include<stdio.h>
#include<ctype.h>
int find_mult(char *s){
    char *m;
    m=s;
    int num=0;
    while(*m){
        if(*m=='(')num++;
        m++;
    }
    return num;
}
int main(){
    char s[51],*c,*c1,yet;
    int n[127]={0};
    n['I']=1;n['V']=5;n['X']=10;n['L']=50;n['C']=100;n['D']=500;n['M']=1000;
    long long int num=0;
    int xmul,mul=1;
    scanf("%s",s);
    xmul=find_mult(s);
    c=s;
    while(*c=='(')c++;
    while(*c1)c1++;
    c1--;
    while(*c1==')')c1--;
    c1++;
    yet=*c;
    c++;
    while(c<c1){
        if(!isalpha(*c));
        else{
            if(*c==yet)mul++;
            else if(n[*c]<n[yet]){
                num+=mul*n[yet];
                mul=1;
            }
            else{
                num-=n[yet];
                mul=1;
            }
        }
        yet=*c;
        c++;
    }
    num+=mul*n[*(c-1)];
    if(xmul==1)num*=1000;
    else if(xmul==2)num*=1000000;
    printf("%lld",num);
    return 0;
}
