#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char c;
    int row=0, block=0, str=0, chr=0;
    char pre = '\0';
    while((c=getchar()) != EOF) {
        if(block){
            if(c=='/' && pre=='*'){ block = 0;}
        }else if(row) {
            if(c == '\n'){
                row = 0;
                printf("\n");
            }
        }else if(str) {
            if(c=='"' && pre!='\\') {str = 0;}
            printf("%c",c);
        }else if(chr){
            if(c == '\'' && pre!='\\') chr = 0;
            printf("%c",c);
        }else {
            if(pre == '/'){
                if(c == '/') row = 1;
                else if(c == '*') block = 1;
                else printf("%c",c);
            }else if(c == '"'){
                if(pre != '\\')str = 1;
                printf("%c",c);
            }else if(c == '\''){
                if(pre != '\\') chr = 1;
                printf("%c",c);
            }else if(c != '/') printf("%c",c);
        }
        pre = c;
    }
    return 0;
}
