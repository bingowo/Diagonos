#include<stdio.h>
#include<ctype.h>
int main(){
    char s[81];
    scanf("%s",s);
    char *p=s;
    int left=0,right=0;
    char alp;
    while(*p){
        if(isalpha(*p)){alp=*p;break;}
        p++;
    }
    p=s;
    while(*p!='='){
        if(*p=='+'){
            p++;
            if(isalpha(*p)){
                left+=1;p++;continue;
            }
            int num=0;
            while(*p>='0'&&*p<='9'){
                num=num*10+*p-'0';p++;
            }
            if(isalpha(*p)){
                left+=num;p++;continue;
            }
            else{
                right+=num;continue;
            }
        }
        if(*p=='-'){
            p++;
            if(isalpha(*p)){
                left-=1;p++;continue;
            }
            int num=0;
            while(*p>='0'&&*p<='9'){
                num=num*10+*p-'0';p++;
            }
            if(isalpha(*p)){
                left-=num;p++;continue;
            }
            else {
                right-=num;
                continue;
            }
        }
        if(isalpha(*p)){
            left+=1;p++;continue;
        }
        if(*p>='0'&&*p<='9'){
            int num=0;
            while(*p>='0'&&*p<='9'){
                num=num*10+*p-'0';p++;
            }
            if(isalpha(*p)){
                left+=num;p++;continue;
            }
            else {
                right+=num;continue;
            }
        }
    }
    p++;
    while(*p){
        if(*p=='+'){
                p++;
                if(isalpha(*p)){
                    left-=1;p++;continue;
                }
                int num=0;
                while(*p>='0'&&*p<='9'){
                    num=num*10+*p-'0';p++;
                }
                if(isalpha(*p)){
                    left-=num;p++;continue;
                }
                else{
                    right-=num;continue;
                }
            }
            if(*p=='-'){
                p++;
                if(isalpha(*p)){
                    left+=1;p++;continue;
                }
                int num=0;
                while(*p>='0'&&*p<='9'){
                    num=num*10+*p-'0';p++;
                }
                if(isalpha(*p)){
                    left+=num;p++;continue;
                }
                else {
                    right+=num;
                    continue;
                }
            }
            if(isalpha(*p)){
                left-=1;p++;continue;
            }
            if(*p>='0'&&*p<='9'){
                int num=0;
                while(*p>='0'&&*p<='9'){
                    num=num*10+*p-'0';p++;
                }
                if(isalpha(*p)){
                    left-=num;p++;continue;
                }
                else {
                    right-=num;continue;
                }
            }
        }
    double ret=-right*1.0/left;
    printf("%c=%.3lf",alp,ret);
}