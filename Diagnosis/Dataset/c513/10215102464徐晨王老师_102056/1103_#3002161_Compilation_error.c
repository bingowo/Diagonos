#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(){
    long long int p[4]={0};
    char s1[50],s2[50];
    char itd1[3]="IN";
    char itd2[4]="MOV";
    char itd3[4]="ADD";
    char itd4[4]="SUB";
    char itd5[4]="MUL";
    char itd6[4]="DIV";
    char itd7[4]="OUT";
    while(scanf("%s %s",s1,s2)!=EOF){
        if(strcmp(s1,itd1)==0){
            int index=-1;
            for(int i=0;i<strlen(s2);i++){
                if(s2[i]==',')index=i;
            }
            index++;
            int sum=0;
            char s[50];
            for(i=index;i<strlen(s2);i++){
                s[i-index]=s2[i];
            }
            sum=atoi(s);
            if(index==strlen(s2)&&sum==0)sum=1;
            p[s2[0]-65]=sum;
        }
        if(strcmp(s1,itd2)==0){
            int index=-1;
            for(int i=0;i<strlen(s2);i++){
                if(s2[i]==',')index=i;
            }
            index++;
            p[s2[0]-65]=p[s2[index]-65];
        }
        if(strcmp(s1,itd3)==0){
            int index=-1;
            for(int i=0;i<strlen(s2);i++){
                if(s2[i]==',')index=i;
            }
            index++;
            p[s2[0]-65]=p[s2[0]-65]+p[s2[index]-65];
        }
        if(strcmp(s1,itd4)==0){
            int index=-1;
            for(int i=0;i<strlen(s2);i++){
                if(s2[i]==',')index=i;
            }
            index++;
            p[s2[0]-65]=p[s2[0]-65]-p[s2[index]-65];
        }
        if(strcmp(s1,itd5)==0){
            int index=-1;
            for(int i=0;i<strlen(s2);i++){
                if(s2[i]==',')index=i;
            }
            index++;
            p[s2[0]-65]=p[s2[0]-65]*p[s2[index]-65];
        }
        if(strcmp(s1,itd6)==0){
            int index=-1;
            for(int i=0;i<strlen(s2);i++){
                if(s2[i]==',')index=i;
            }
            index++;
            p[s2[0]-65]=p[s2[0]-65]/p[s2[index]-65];
        }
        if(strcmp(s1,itd7)==0){
            printf("%lld\n",p[s2[0]-65]);
        }
        for(int i=0;i<50;i++){
            s1[i]='\0';
            s2[i]='\0';
        }
    }
    return 0;
}
