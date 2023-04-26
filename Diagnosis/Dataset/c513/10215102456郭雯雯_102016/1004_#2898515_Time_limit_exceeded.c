#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char s[10];
    while(scanf("%s",s)){
        char* c;
        if((c=strchr(s,'.'))!=NULL){
            int t=atoi(s);
            int n=sizeof(int);
            unsigned char* p=(unsigned char*)&t;
            for(int i=0;i<n;i+=2){
                unsigned char* c=p;
                printf("%02x ",*c);
                p+=2;
            }
        }
        else{
            double t=atof(s);
            int n=sizeof(double);
            unsigned char* p=(unsigned char*)&t;
            for(int i=0;i<n;i+=2){
                unsigned char* c=p;
                printf("%02x ",*c);
                p+=2;
            }
        }
    }
}