#include<stdio.h>
#include<string.h>
#include<ctype.h>
int issign(char a){
    if(a=='+') return 1;
    else if(a=='-')return -1;
    else return 0;
}
long long readnum(char *s,int *p){
    int i=*p;
    int sign=1;long long ret=0;
    if(issign(s[i]))sign=issign(s[i++]);
    if(isalpha(s[i])) ret=1;
    else{
        for(;i<strlen(s) && !issign(s[i]) && !isalpha(s[i]) && s[i]!='=';i++){
            ret=ret*10+s[i]-'0';
        }
    }
    *p=i;
    return ret*sign;
}
int main(){
    long long num=0,right=0,p=0;
    int state=-1,alpha=-1;
    char s[100];scanf("%s",s);
    while(p<strlen(s)){
        if(s[p]=='='){state=1;p++;}
        else {
            long long tmp=readnum(s,&p);

            if(p<strlen(s) && isalpha(s[p])){
                num+=(-1)*state*tmp;
                alpha=s[p++];
            }
            else right+=state*tmp;
        }
    }
    double ans=1.0*right/num;
    printf("%c=%.3f",alpha,ans);
    return 0;
}
