#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char ch=getchar();char pre;
    while(ch!=EOF){
        if(ch=='\''){
            putchar(ch);ch=getchar();
            while((ch!='\''||(ch=='\''&&pre=='\\'))&&ch!=EOF){
                putchar(ch);
                pre=ch;
                ch=getchar();}
            if(ch==EOF)break;
            putchar(ch);
            ch=getchar();
            continue;
        }
        if(ch=='\"'){
            putchar(ch);ch=getchar();
            while((ch!='\"'||(ch=='\"'&&pre=='\\'))&&ch!=EOF){
                putchar(ch);
                pre=ch;
                ch=getchar();}
            if(ch==EOF)break;
            putchar(ch);
            ch=getchar();
            continue;
        }
        if(ch=='/'){
            if(pre=='\\'){
                putchar(ch);
                pre=ch;
                ch=getchar();continue;
            }
            pre=ch;
            ch=getchar();
            if(ch=='/'&&pre=='/'){
                putchar(' ');
                while(ch!='\n'){
                    putchar(' ');
                    ch=getchar();
                    if(ch==EOF)break;}
                putchar(ch);
                ch=getchar();
                continue;
            }
            if(ch=='*'&&pre=='/'){
                ch=getchar();
                pre=ch;ch=getchar();
                while(!(pre=='*'&&ch=='/')){
                      pre=ch;ch=getchar();
                    if(ch==EOF)break;}
                ch=getchar();
                continue;
            }
            else putchar(pre);
            continue;
        }
        putchar(ch);
        pre=ch;
        ch=getchar();
    }
}
