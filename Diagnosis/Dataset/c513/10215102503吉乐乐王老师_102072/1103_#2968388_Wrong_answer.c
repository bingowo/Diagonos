#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    int n[4]={0};
    char dec[100];
    while(gets(dec)){
        char ope[100];
        char *po=ope;
        char *p=dec;
        while(*p!=' '){*po=*p;p++;po++;}
        *po='\0';
        if(strcmp(ope,"IN")==0){
            p++;//跳过空格
            char ch=*p;
            while(*p!=',')p++;
            p++;
            int num=0;
            while(*p!='\n'&&*p){num=num*10+*p-'0';p++;}
            n[ch-'A']=num;
        }
        else if(strcmp(ope,"MOV")==0){
            p++;
            char ch1=*p;
            while(*p!=',')p++;
            p++;
            char ch2=*p;
            n[ch1-'A']=n[ch2-'A'];
        }
        else if(strcmp(ope,"ADD")==0){
            p++;
            char ch1=*p;
            while(*p!=',')p++;
            p++;
            char ch2=*p;
            n[ch1-'A']+=n[ch2-'A'];
        }
        else if(strcmp(ope,"SUB")==0){
            p++;
            char ch1=*p;
            while(*p!=',')p++;
            p++;
            char ch2=*p;
            n[ch1-'A']-=n[ch2-'A'];
        }
        else if(strcmp(ope,"MUL")==0){
            p++;
            char ch1=*p;
            while(*p!=',')p++;
            p++;
            char ch2=*p;
            n[ch1-'A']*=n[ch2-'A'];
        }
        else if(strcmp(ope,"DIV")==0){
            p++;
            char ch1=*p;
            while(*p!=',')p++;
            p++;
            char ch2=*p;
            n[ch1-'A']/=n[ch2-'A'];
        }
        else if(strcmp(ope,"OUT")==0){
            p++;
            char ch1=*p;
            printf("%d\n",n[ch1-'A']);
        }
    }
}