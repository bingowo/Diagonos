#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    long long int n[4]={0};
    char ope[100];
    char data[100];
    while(scanf("%s %s",ope,data)==2){
        char *p=data;
        if(strcmp(ope,"IN")==0){
            char ch=*p;p+=3;
            n[ch-'A']=atoll(p);
        }
        else if(strcmp(ope,"MOV")==0){
            char ch1=*p;p+=3;
            char ch2=*p;
            n[ch1-'A']=n[ch2-'A'];
        }
        else if(strcmp(ope,"ADD")==0){
            char ch1=*p;p+=3;
            char ch2=*p;
            n[ch1-'A']+=n[ch2-'A'];
        }
        else if(strcmp(ope,"SUB")==0){
            char ch1=*p;p+=3;
            char ch2=*p;
            n[ch1-'A']-=n[ch2-'A'];
        }
        else if(strcmp(ope,"MUL")==0){
            char ch1=*p;p+=3;
            char ch2=*p;
            n[ch1-'A']*=n[ch2-'A'];
        }
        else if(strcmp(ope,"DIV")==0){
            char ch1=*p;p+=3;
            char ch2=*p;
            n[ch1-'A']/=n[ch2-'A'];
        }
        else if(strcmp(ope,"OUT")==0){
            char ch1=*p;
            printf("%d\n",n[ch1-'A']);
        }
        getchar();
    }
}