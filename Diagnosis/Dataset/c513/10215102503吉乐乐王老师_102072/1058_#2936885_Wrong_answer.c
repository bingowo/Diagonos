#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void incomment(char ch){
    int pre=ch;
    ch=getchar();
    if(ch=='/'){
        putchar(' ');
        while(ch!='\n'){
            putchar(' ');
            ch=getchar();
            if(ch==EOF)return ;
        }
        putchar(ch);
        return ;
    }
    if(ch=='*'){
        pre=ch;ch=getchar();
        while(!(pre=='*'&&ch=='/')){
            if(ch==EOF)return;
            pre=ch;ch=getchar();
        }
        return ;
    }
    putchar(pre);
    if(ch==EOF)return;
    putchar(ch);
    return ;
}
void quote(char ch){
    putchar(ch);
    int pre=ch;
    while((ch=getchar())!=pre){
        if(ch==EOF)return;
        putchar(ch);
        if(ch=='\\')putchar(getchar());
    }
    putchar(ch);
    return ;
}
int main(){
    char ch;
    while((ch=getchar())!=EOF){
        if(ch=='/')incomment(ch);
        else if(ch=='"'||ch=='\'')quote(ch);
        else putchar(ch);
    }
}
