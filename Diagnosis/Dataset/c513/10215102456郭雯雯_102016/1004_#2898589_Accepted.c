#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char s[100];
    while(scanf("%s",s)!=EOF){
        if(strchr(s,'.')==0){
            int t=atoi(s);
            int n=sizeof(t);
            unsigned char* p=(unsigned char*)&t;
            while(n--){
                printf("%02x ",*p++);
            }
            printf("\n");
        }
        else{
            double t=atof(s);
            int n=sizeof(t);
            unsigned char* p=(unsigned char*)&t;
            while(n--){
                printf("%02x ",*p++);
            }
            printf("\n");
        }
    }
}