#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    long long int n[26]={0};
    char ope[100];
    char data[100];
    while(scanf("%s %s",ope,data)==2){
        char *p=data;
        char ch1=0,ch2=0,ch3=0;
        if(strcmp(ope,"IN")==0){
            ch1=*p;p+=3;
            n[ch1-'A']=atoll(p);
        }
        else if(strcmp(ope,"MOV")==0){
            ch1=*p;p+=3;
            ch2=*p;
            n[ch1-'A']=n[ch2-'A'];
        }
        else if(strcmp(ope,"XCHG")==0){
            ch1=*p;p+=3;
            ch2=*p;
            long long int t=n[ch1-'A'];
            n[ch1-'A']=n[ch2-'A'];
            n[ch2-'A']=t;
        }
        else if(strcmp(ope,"ADD")==0){
            ch1=*p;p+=3;
            ch2=*p;
            if(*(p+2)){p+=3;ch3=*p;}
            n[ch1-'A']=ch3?n[ch2-'A']+n[ch3-'A']:n[ch1-'A']+n[ch2-'A'];
        }
        else if(strcmp(ope,"SUB")==0){
            ch1=*p;p+=3;
            ch2=*p;
            if(*(p+2)){p+=3;ch3=*p;}
            n[ch1-'A']=ch3?n[ch2-'A']-n[ch3-'A']:n[ch1-'A']-n[ch2-'A'];
        }
        else if(strcmp(ope,"MUL")==0){
            ch1=*p;p+=3;
            ch2=*p;
            if(*(p+2)){p+=3;ch3=*p;}
            n[ch1-'A']=ch3?n[ch2-'A']*n[ch3-'A']:n[ch1-'A']*n[ch2-'A'];
        }
        else if(strcmp(ope,"DIV")==0){
            ch1=*p;p+=3;
            ch2=*p;
            if(*(p+2)){p+=3;ch3=*p;}
            n[ch1-'A']=ch3?n[ch2-'A']/n[ch3-'A']:n[ch1-'A']/n[ch2-'A'];
        }
        else if(strcmp(ope,"MOD")==0){
            ch1=*p;p+=3;
            ch2=*p;
            if(*(p+2)){p+=3;ch3=*p;}
            n[ch1-'A']=ch3?n[ch2-'A']%n[ch3-'A']:n[ch1-'A']%n[ch2-'A'];
        }
        else if(strcmp(ope,"AND")==0){
            ch1=*p;p+=3;
            ch2=*p;
            if(*(p+2)){p+=3;ch3=*p;}
            n[ch1-'A']=ch3?n[ch2-'A']&n[ch3-'A']:n[ch1-'A']&n[ch2-'A'];
        }
        else if(strcmp(ope,"OR")==0){
            ch1=*p;p+=3;
            ch2=*p;
            if(*(p+2)){p+=3;ch3=*p;}
            n[ch1-'A']=ch3?n[ch2-'A']|n[ch3-'A']:n[ch1-'A']|n[ch2-'A'];
        }
        else if(strcmp(ope,"XOR")==0){
            ch1=*p;p+=3;
            ch2=*p;
            if(*(p+2)){p+=3;ch3=*p;}
            n[ch1-'A']=ch3?n[ch2-'A']^n[ch3-'A']:n[ch1-'A']^n[ch2-'A'];
        }
        else if(strcmp(ope,"OUT")==0){
            ch1=*p;
            printf("%d\n",n[ch1-'A']);
        }
        getchar();
    }
}