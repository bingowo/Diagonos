#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char *ret=(char*)malloc(100000);char*p=ret;
    char ch=getchar();char pre;
    while(ch!=EOF){
        if(ch=='"'){
            *p=ch;p++;ch=getchar();
            while(ch!='"'){
                *p=ch;p++;ch=getchar();}
            *p=ch;p++;ch=getchar();
            continue;
        }
        if(ch=='/'){
            ch=getchar();
            if(ch!='/'&&ch!='*'){
                *p='/';p++;continue;
            }
            if(ch=='/'){
                *p=' ';p++;
                while(ch!='\n'){
                    *p=' ';p++;
                    ch=getchar();
                    if(ch==EOF)break;}
                *p=ch;p++;
                ch=getchar();
                continue;
            }
            if(ch=='*'){
                ch=getchar();
                pre=ch;ch=getchar();
                while(!(pre=='*'&&ch=='/')){
                      pre=ch;ch=getchar();
                    if(ch==EOF)break;}
                ch=getchar();
                continue;
            }
        }
        else {
            *p=ch;p++;
            ch=getchar();}
    }
    *p='\0';
    printf("%s",ret);
    getchar();
}
