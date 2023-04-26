#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LEN 50


int main()
{
    int a=0,b=0,c=0;
    int aIsFu=0,bIsFu=0,cIsFu=0;
    char s[50]={0};scanf("%s",s);
    int cnt=0;
    if(s[cnt]=='-'){
        aIsFu=1;
        cnt++;
    }
    if(isdigit(s[cnt])){
        while(isdigit(s[cnt])){
            a=a*10+s[cnt++]-'0';
        }
    }
    if(s[cnt]=='x' && s[cnt+1]=='^' && s[cnt+2]=='2'){
        if(a==0){
            a=1;
        }
        cnt+=3;
    }

    if(s[cnt]=='-' ){
        cnt++;
        if(s[cnt]=='x'){
            bIsFu=1;
            b=1;
        }
        if(isdigit(s[cnt])){
           int tmp=0;
           while(isdigit(s[cnt])){
                tmp=tmp*10+s[cnt++]-'0';
           }
           if(s[cnt]=='x'){
                bIsFu=1;
                b=tmp;
           }
           else{
            cIsFu=1;
            c=tmp;
           }
           cnt++;
        }
    }
    if(s[cnt]=='+'){
        cnt++;
        if(s[cnt]=='x'){
            b=1;
        }
        if(isdigit(s[cnt])){
           int tmp=0;
           while(isdigit(s[cnt])){
                tmp=tmp*10+s[cnt++]-'0';
           }
           if(s[cnt]=='x'){
                b=tmp;
           }
           else{
            c=tmp;
           }
           cnt++;
        }
    }

    if(s[cnt]=='-'){
        cnt++;
        while(isdigit(s[cnt])){
            c=c*10+s[cnt++]-'0';
        }
    }
    if(s[cnt]=='+'){
        cnt++;
        while(isdigit(s[cnt])){
            c=c*10+s[cnt++]-'0';
        }
    }

    if(aIsFu) a*=-1;
    if(bIsFu) b*=-1;
    if(cIsFu) c*=-1;

    if(b*b-4*a*c<0) printf("No Answer!\n");
    else {
        int a1=1,a2=1,c1=1,c2=1;


    }








    return 0;
}

