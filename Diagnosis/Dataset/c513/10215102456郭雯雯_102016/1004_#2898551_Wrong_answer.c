#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char s[10];
    while(scanf("%s",s)!=EOF){
        char* c;
        if((c=strchr(s,'.'))!=NULL){
            int t=atoi(s);
            int n=sizeof(t);
            unsigned char* p=(unsigned char*)&t;
            for(int i=0;i<n;i++){
                printf("%02x%c",*p++,i!=n-1?' ':'\n');
            }
        }
        else{
            double t=atof(s);
            int n=sizeof(t);
            unsigned char* p=(unsigned char*)&t;
            for(int i=0;i<n;i++){
                printf("%02x%c",*p++,i!=n-1?' ':'\n');
            }
        }
    }
}