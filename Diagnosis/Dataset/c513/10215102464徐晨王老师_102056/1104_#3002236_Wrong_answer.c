#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(){
    long long int p[26]={0};
    char s1[50],s2[50];
    char itd[12][5]={"IN","OUT","MOV","XCHG","ADD","SUB","MUL","DIV","MOD","AND","OR","XOR"};
    while(scanf("%s %s",s1,s2)!=EOF){
        if(strcmp(s1,itd[0])==0){
            int index=-1;
            for(int i=0;i<strlen(s2);i++){
                if(s2[i]==',')index=i;
            }
            index++;
            int sum=0;
            char s[50]={'\0'};
            for(int i=index;i<strlen(s2);i++){
                s[i-index]=s2[i];
            }
            sum=atoi(s);
            p[s2[0]-65]=sum;
        }
        if(strcmp(s1,itd[1])==0){
            printf("%lld\n",p[s2[0]-65]);
        }
        if(strcmp(s1,itd[2])==0){
            int index=-1;
            for(int i=0;i<strlen(s2);i++){
                if(s2[i]==',')index=i;
            }
            index++;
            p[s2[0]-65]=p[s2[index]-65];
        }
        if(strcmp(s1,itd[3])==0){
            int index=-1;
            for(int i=0;i<strlen(s2);i++){
                if(s2[i]==',')index=i;
            }
            index++;
            int transfer=p[s2[0]-65];
            p[s2[0]-65]=p[s2[index]-65];
            p[s2[index]-65]=transfer;
        }
        if(strcmp(s1,itd[4])==0){
            int index1=-1,index2=-1;
            for(int i=0;i<strlen(s2);i++){
                if(s2[i]==',')index1=i;
            }
            for(int i=strlen(s2)-1;i>=0;i--){
                if(s2[i]==',')index2=i;
            }
            index1++;index2++;
            if(index1==index2){
                p[s2[0]-65]=p[s2[0]-65]+p[s2[index1]-65];
            }
            else{
                p[s2[0]-65]=p[s2[index1]-65]+p[s2[index2]-65];
            }
        }
        if(strcmp(s1,itd[4])==0){
            int index1=-1,index2=-1;
            for(int i=0;i<strlen(s2);i++){
                if(s2[i]==',')index1=i;
            }
            for(int i=strlen(s2)-1;i>=0;i--){
                if(s2[i]==',')index2=i;
            }
            index1++;index2++;
            if(index1==index2){
                p[s2[0]-65]=p[s2[0]-65]+p[s2[index1]-65];
            }
            else{
                p[s2[0]-65]=p[s2[index1]-65]+p[s2[index2]-65];
            }
        }
        if(strcmp(s1,itd[5])==0){
            int index1=-1,index2=-1;
            for(int i=0;i<strlen(s2);i++){
                if(s2[i]==',')index1=i;
            }
            for(int i=strlen(s2)-1;i>=0;i--){
                if(s2[i]==',')index2=i;
            }
            index1++;index2++;
            if(index1==index2){
                p[s2[0]-65]=p[s2[0]-65]-p[s2[index1]-65];
            }
            else{
                p[s2[0]-65]=p[s2[index1]-65]-p[s2[index2]-65];
            }
        }
        if(strcmp(s1,itd[6])==0){
            int index1=-1,index2=-1;
            for(int i=0;i<strlen(s2);i++){
                if(s2[i]==',')index1=i;
            }
            for(int i=strlen(s2)-1;i>=0;i--){
                if(s2[i]==',')index2=i;
            }
            index1++;index2++;
            if(index1==index2){
                p[s2[0]-65]=p[s2[0]-65]*p[s2[index1]-65];
            }
            else{
                p[s2[0]-65]=p[s2[index1]-65]*p[s2[index2]-65];
            }
        }
        if(strcmp(s1,itd[7])==0){
            int index1=-1,index2=-1;
            for(int i=0;i<strlen(s2);i++){
                if(s2[i]==',')index1=i;
            }
            for(int i=strlen(s2)-1;i>=0;i--){
                if(s2[i]==',')index2=i;
            }
            index1++;index2++;
            if(index1==index2){
                p[s2[0]-65]=p[s2[0]-65]/p[s2[index1]-65];
            }
            else{
                p[s2[0]-65]=p[s2[index1]-65]/p[s2[index2]-65];
            }
        }
        if(strcmp(s1,itd[8])==0){
            int index1=-1,index2=-1;
            for(int i=0;i<strlen(s2);i++){
                if(s2[i]==',')index1=i;
            }
            for(int i=strlen(s2)-1;i>=0;i--){
                if(s2[i]==',')index2=i;
            }
            index1++;index2++;
            if(index1==index2){
                p[s2[0]-65]=p[s2[0]-65]%p[s2[index1]-65];
            }
            else{
                p[s2[0]-65]=p[s2[index1]-65]%p[s2[index2]-65];
            }
        }
        if(strcmp(s1,itd[9])==0){
            int index1=-1,index2=-1;
            for(int i=0;i<strlen(s2);i++){
                if(s2[i]==',')index1=i;
            }
            for(int i=strlen(s2)-1;i>=0;i--){
                if(s2[i]==',')index2=i;
            }
            index1++;index2++;
            if(index1==index2){
                p[s2[0]-65]=p[s2[0]-65]&p[s2[index1]-65];
            }
            else{
                p[s2[0]-65]=p[s2[index1]-65]&p[s2[index2]-65];
            }
        }
        if(strcmp(s1,itd[10])==0){
            int index1=-1,index2=-1;
            for(int i=0;i<strlen(s2);i++){
                if(s2[i]==',')index1=i;
            }
            for(int i=strlen(s2)-1;i>=0;i--){
                if(s2[i]==',')index2=i;
            }
            index1++;index2++;
            if(index1==index2){
                p[s2[0]-65]=p[s2[0]-65]|p[s2[index1]-65];
            }
            else{
                p[s2[0]-65]=p[s2[index1]-65]|p[s2[index2]-65];
            }
        }
        if(strcmp(s1,itd[11])==0){
            int index1=-1,index2=-1;
            for(int i=0;i<strlen(s2);i++){
                if(s2[i]==',')index1=i;
            }
            for(int i=strlen(s2)-1;i>=0;i--){
                if(s2[i]==',')index2=i;
            }
            index1++;index2++;
            if(index1==index2){
                p[s2[0]-65]=p[s2[0]-65]^p[s2[index1]-65];
            }
            else{
                p[s2[0]-65]=p[s2[index1]-65]^p[s2[index2]-65];
            }
        }
        for(int i=0;i<50;i++){
            s1[i]='\0';
            s2[i]='\0';
        }
    }
    return 0;
}
