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
                while(ch!='\n'){
                    putchar(' ');
                    ch=getchar();}
                putchar(ch);
                ch=getchar();
                continue;
            }
            if(ch=='*'){
                pre=ch;ch=getchar();
                while(!(pre=='*'&&ch=='/')){
                      pre=ch;ch=getchar();}
                ch=getchar();
                continue;
            }
        }
        if(ch=='\''||ch=='"'){
            putchar(ch);
            pre=ch;
            while((ch=getchar())!=pre){
                if(ch==EOF)break;
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
