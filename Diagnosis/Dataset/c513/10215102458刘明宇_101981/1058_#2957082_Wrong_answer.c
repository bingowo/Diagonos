#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[10000];
    while(scanf("%s",s)!=EOF);
    char *p = s;
    while(*p){
        if(*p == '/' && *(p+1) == '/'){
            char *p2 = p+2;
            while(*p2 != '\n'){
                printf("\n");
            }
        }
        else if(*p == '/' && *(p+1) == '*'){
            char *p2 = p+2;
            while(*p2){
                if(*p2 == '\n') printf("\n");
                else if(*p2 == '*' && *(p2+1) == '/')break;
                p2++;
            }
        }
        else{printf("%c",*p);}
        p++;
    }
}