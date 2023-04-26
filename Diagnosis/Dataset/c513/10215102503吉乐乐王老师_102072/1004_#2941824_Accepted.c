#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char s[100];
    while(scanf("%s",s)==1){
        int flag=0;
        for(int i=0;i<strlen(s);i++){
            if(s[i]=='.'){flag=1;break;}
        }
        if(flag){
            double n=atof(s);
            unsigned char*p=(unsigned char*)&n;
            for(int i=0;i<sizeof(double);i++){
                printf("%02x ",*p++);
            }
        }
        else{
            int n=atoi(s);
            unsigned char*p=(unsigned char*)&n;
            for(int i=0;i<sizeof(int);i++){
                printf("%02x ",*p++);
            }
        }
        putchar('\n');
    }
}