#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        printf("case #%d:\n",t);
        char s[100];
        scanf("%s",s);
        char p[100]={'\0'};
        for(int i=0;i<strlen(s);i++){
            int x=s[i];
            char ss[9]={'\0'};
            for(int j=7;j>=0;i++){
                ss[j]=x%2+48;
                x=x/2;
            }
            strcat(p,ss);
        }
        int len=strlen(p);
        if(len%6!=0){
            char ss[6-len%6+1]={'0'};
            ss[6-len%6]='\0';
            strcat(p,ss);
        }
        for(int i=0;i<strlen(p)/6;i++){
            int x=0;
            for(int j=0;j<6;j++){
                x=x*2+p[6*i+j];
            }
            if(x>=0&&x<=25){
                printf("%c",x+65);
            }
            else if(x>=26&&x<=51){
                printf("%c",x+71);
            }
            else if(x>=52&&x<=61){
                printf("%c",x-4);
            }
            else if(x==62){
                printf("+");
            }
            else printf("/");
        }
        for(int i=0;i<(4-strlen(p));i++){
            printf("=");
        }
    }
}