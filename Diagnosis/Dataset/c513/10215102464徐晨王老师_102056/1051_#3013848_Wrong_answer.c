#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        printf("case #%d:\n",t);
        char s[500];
        scanf("%s",s);
        char p[1000]={'\0'};
        for(int i=0;i<strlen(s);i++){
            int x=s[i];
            char ss[9]={'\0'};
            for(int j=7;j>=0;j--){
                ss[j]=x%2+48;
                x=x/2;
            }
            strcat(p,ss);
        }
        int len=strlen(p);
        if(len%6!=0){
            char pp[6-len%6+1];
            for(int i=0;i<(6-len%6);i++){
                pp[i]='0';
            }
            strcat(p,pp);
        }
        for(int i=0;i<strlen(p)/6;i++){
            int x=0;
            for(int j=0;j<6;j++){
                x=x*2+p[6*i+j]-48;
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
            else if(x==63)printf("/");
        }
        if(strlen(p)%4!=0){
        for(int i=0;i<(4-strlen(p)%4);i++){
            printf("=");
        }
        }
        printf("\n");
    }
}
