#include <stdio.h>

int main()
{
    int flag = 0;
    char c;
    while((c = getchar()) != EOF) {
        if(flag == 0) {
            if(c == '/') flag = 1;
            else{
                if(c == '"') flag = 5;
                else if(c == '\'') flag = 7;
                printf("%c",c);
            }
        }else if(flag == 1) {
            if(c == '/') flag = 2;
            else if(c == '*') flag = 3;
            else {
                flag = 0;
                printf("/%c",c);
            }
        }else if(flag == 2) {
            if(c == '\n'){
                printf("\n");
                flag = 0;
            }
        }else if(flag == 3) {
            if(c == '*') flag = 4;
        }else if(flag == 4) {
            if(c == '/') flag = 0;
            else if(c != '*') flag = 3;
        }else if(flag == 5) {
            printf("%c",c);
            if(c == '\\') flag = 6;
            else if(c == '"') flag = 0;
        }else if(flag == 6) {
            printf("%c",c);
            flag = 5;
        }else if(flag == 7) {
            printf("%c",c);
            if(c == '\\') flag = 8;
            else if(c == '\'') flag = 0;
        }else {
            printf("%c",c);
            flag = 7;
        }
    }
    return 0;
}
