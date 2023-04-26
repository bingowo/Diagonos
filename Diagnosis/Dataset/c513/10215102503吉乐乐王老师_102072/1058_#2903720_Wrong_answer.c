#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char *ret=(char*)malloc(10000);char*p=ret;
    char ch=getchar();char pre;
    while(ch!=EOF){
        if(ch=='"'){
            *p=ch;p++;
            ch=getchar();
            while(ch!='"'){
                pre=ch;
                *p=ch;p++;ch=getchar();
                if(ch==EOF)break;
            }
            *p=ch;p++;ch=getchar();
            if(ch==EOF)break;
        }
        if(ch=='/'){
            ch=getchar();
            if(ch=='/'){
                *p=' ';p++;
                while(ch!='\n'){
                    *p=' ';p++;
                    ch=getchar();
                    if(ch==EOF)break;}
                while(ch!=EOF&&ch!='/'){
                    *p=ch;p++;ch=getchar();
                }
            }
            if(ch=='*'){
                pre=ch;ch=getchar();
                while(!(pre=='*'&&ch=='/')){
                      pre=ch;ch=getchar();
                    if(ch==EOF)break;}
                ch=getchar();
                while(ch!=EOF&&ch!='/'){
                    *p=ch;p++;ch=getchar();
                }
            }
        }
        if(ch!=EOF&&ch!='/'){
            *p=ch;p++;
            ch=getchar();}
    }
    *p='\0';
    printf("%s",ret);
    getchar();
}
