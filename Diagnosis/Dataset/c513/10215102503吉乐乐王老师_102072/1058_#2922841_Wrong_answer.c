#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char ch=getchar();char pre;
    while(ch!=EOF){
        if(ch=='"'){
            putchar(ch);ch=getchar();
            while(ch!='"'){
                putchar(ch);
                ch=getchar();}
            putchar(ch);
            ch=getchar();
            continue;
        }
        if(ch=='/'){
            pre=ch;
            ch=getchar();
            if(ch!='/'&&ch!='*'){
                putchar(pre);continue;
            }
            if(ch=='/'){
                putchar(' ');
                while(ch!='\n'){
                    putchar(' ');
                    ch=getchar();
                    if(ch==EOF)break;}
                putchar(ch);
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
        putchar(ch);
        ch=getchar();
    }
}
