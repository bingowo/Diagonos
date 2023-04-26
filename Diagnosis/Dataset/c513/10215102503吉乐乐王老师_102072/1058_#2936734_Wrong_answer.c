#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char ch=getchar();char pre;
    while(ch!=EOF){
        if(ch=='/'){
            pre=ch;
            ch=getchar();
            if(ch=='/'){
                putchar(' ');
                while(ch!='\n'&&ch!=EOF){
                    putchar(' ');
                    ch=getchar();}
                if(ch==EOF)break;
                putchar(ch);
                ch=getchar();
                continue;
            }
            if(ch=='*'){
                pre=ch;ch=getchar();
                while(!(pre=='*'&&ch=='/')&&ch!=EOF){
                      pre=ch;ch=getchar();}
                if(ch==EOF)break;
                ch=getchar();
                continue;
            }
        }
        else if(ch=='\''||ch=='\"'){
            pre=ch;
            while((ch=getchar())!=pre){
                if(ch=EOF)break;
                putchar(ch);
                if(ch=='\\'){
                    putchar(getchar());
                }
            }
            if(ch==EOF)break;
        }
        putchar(ch);
        ch=getchar();
    }
}
