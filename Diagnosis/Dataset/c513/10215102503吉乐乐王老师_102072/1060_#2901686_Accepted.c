#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int mymax(int a,int b){
    return a>b?a:b;
}
int main(){
    char s[101];
    gets(s);
    char *p=s;
    int now=0,ret=0;
    while(*p){
        if('0'<=*p&&*p<='9'){
            while(*p=='0')p++;
            while('0'<=*p&&*p<='9'){now++;p++;}
            ret=mymax(ret,now);
            now=0;
        }
        p++;
    }
    printf("%d",ret);
}