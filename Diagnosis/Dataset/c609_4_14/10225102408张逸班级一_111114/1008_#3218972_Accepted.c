#include<stdio.h>
#include<stdlib.h>
int main(){
    char s[1000];int length;
    while(scanf("%s",s)!=EOF){
        if(strchr(s,'.')){
           double a=atof(s);
           unsigned char* p=(unsigned char*)&a;
           length=sizeof(double);
           for(int i=0;i<length;i++){
           printf("%02x ",*(p+i));
        }
        printf("\n");
        }
        else {
            int a=atoi(s);
            unsigned char*p=(unsigned char*)&a;
            length=sizeof(int);
            for(int i=0;i<length;i++){
            printf("%02x ",*(p+i));
        }
        printf("\n");
        }
    }
    return 0;
}
