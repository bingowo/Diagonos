#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char s[20];
    while(scanf("%s",s)!=EOF){
        int flag=0;
        if(strchr(s,'.')!=NULL)flag=1;
        if(flag==0){
            int num=atoi(s);
            unsigned char *p=(unsigned char*)&num;
            for(int i=0;i<sizeof(num);i++){
                printf("%02x ",*p++);
            }
        }
        else {
            double num=atof(s);
            unsigned char *p=(unsigned char*)&num;
            for(int i=0;i<sizeof(num);i++){
                printf("%02x ",*p++);
            }
        }
        putchar('\n');
    }
}