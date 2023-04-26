#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char *ret=(char*)malloc(10000);char*p=ret;
    char ch=getchar();char pre=ch;
    while(ch!=EOF){
        if(pre=='"'){
            while(ch!='"'){
                *p=ch;p++;ch=getchar();
            }
            *p=ch;p++;ch=getchar();
        }
        if(ch=='/'){
            ch=getchar();
            if(ch=='/'){
                *p=' ';p++;
                while(ch!='\n'){
                    *p=' ';p++;
                    ch=getchar();}
                *p='\n';p++;
                ch=getchar();
                while(ch!=EOF){
                    *p=ch;p++;ch=getchar();
                }
            }
            if(ch=='*'){
                while(ch!='/')ch=getchar();
                ch=getchar();
                while(ch!=EOF){
                    *p=ch;p++;ch=getchar();
                }
            }
        }
        *p=ch;p++;pre=ch;
        ch=getchar();
    }
    *p='\0';
    printf("%s",ret);
}