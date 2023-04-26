#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef long long int lli;
typedef struct
{
    lli real;
    lli imaginary;
}prural;
prural cal(prural ret,int rmd){
    prural base;base.real=-1;base.imaginary=-1;
    ret.real-=rmd;
    prural a;
    a.real=(ret.real*base.real-ret.imaginary*base.imaginary)/2;
    a.imaginary=(ret.real*base.imaginary+ret.imaginary*base.real)/2;
    return a;
}
lli atoi2(char s[]){
    lli ret=0;int i=0;int flag=0;
    while(s[i]!='\0'){
        if(s[i]=='-'||s[i]=='+'){flag=s[i]=='-'?1:0;}
        else {ret=ret*10+s[i]-'0';}
        i++;
    }
    if(flag)ret=-ret;
    return ret;
}
prural get(){
    prural a;a.imaginary=0,a.real=0;
    char s[100];
    scanf("%s",s);
    if(s[0]=='i'){
        a.imaginary=1;return a;
    }
    if(s[0]=='-'){
        if(s[1]=='i'){a.imaginary=-1;return a;}
        int i=0,j=0,k=0;
        char num1[100];
        while(s[i]){num1[j]=s[i];
            i++;j++;
            if(s[i]=='+'||s[i]=='-'||s[i]=='i')break;}
        num1[j]='\0';
        if(s[i]=='i'){a.imaginary=atoi2(num1);return a;}
        if(s[i]=='\0'){a.real=atoi2(num1);return a;}
        char num2[100];
        while(s[i]){
            if(s[i+1]=='i'){a.real=atoi2(num1);a.imaginary=s[i]=='-'?-1:1;return a;}
            while(s[i]){num2[k]=s[i];i++;k++;if(s[i]=='i')break;}
        }
        num2[k-1]='\0';
        a.real=atoi2(num1);a.imaginary=atoi2(num2);
    }
    if(isdigit(s[0])){
        if(s[1]=='i'){a.imaginary=s[0]-'0';return a;}
        int i=0,j=0,k=0;
        char num1[100];
        while(s[i]){num1[i]=s[i];i++;j++;if(s[i]=='-'||s[i]=='+'||s[i]=='i')break;}
        num1[j]='\0';
        if(s[i]=='i'){a.imaginary=atoi2(num1);return a;}
        if(s[i]=='\0'){a.real=atoi2(num1);return a;}
        char num2[100];
        while(s[i]){
            if(s[i+1]=='i'){a.real=atoi2(num1);a.imaginary=s[i]=='-'?-1:1;return a;}
            while(s[i]){num2[k]=s[i];i++;k++;if(s[i]=='i')break;}
        }
        num2[k-1]='\0';
        a.real=atoi2(num1);a.imaginary=atoi2(num2);
    }
    return a;
}
int isodd(long long int a){
    if(a%2==0)return 1;
    return 0;
}
int main(){
    prural ini=get();
    int ret[10000];int i=0;
    int rmd;
    if(ini.real==0&&ini.imaginary==0)ret[i++]==0;
    while(ini.imaginary!=0||ini.real!=0){
        if((isodd(ini.imaginary)&&isodd(ini.real))||(!isodd(ini.real)&&!isodd(ini.imaginary)))rmd=0;
        else rmd=1;
        ini=cal(ini,rmd);
        ret[i++]=rmd;
    }
    for(int j=i-1;j>=0;j--){
        printf("%d",ret[j]);
    }
}