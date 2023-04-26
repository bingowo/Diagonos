#include <stdio.h>
#include <stdlib.h>
int main()
{
    char c,tmp;
    int s1 = -1,s2 = -1,s3 = -1,s4 = -1;
    while(scanf("%c",&c) != EOF){
        if(s1 == -1 && s4 == -1 && c == '/' && s2 == -1 && s3 == -1){
            scanf("%c",&tmp);
            if(tmp == '/'){
                s2 = -1*s2;
                continue;
            }
            else if(tmp == '*'){
                s3 = -1*s3;
                continue;
            }
            else printf("%c",c);
            c = tmp;
        }
        if(s1 == -1 && s4 == -1 && c == '*' && s3 == 1){
            scanf("%c",&tmp);
            while(tmp == '*' || tmp == '/'){
                if(tmp == '/'){
                    s3 = -1*s3;
                    break;
                }
                scanf("%c",&tmp);
            }
            continue;
        }
        if(c == '\'' && s4 == -1) s1 = -1*s1;
        if(c == '\"' && s1 == -1) s4 = -1*s4;
        if(s2 == 1 && c == '\n'){
            s2 = -1*s2;
        }
        if(c == '\' && (s1 == 1 || s4 == 1)){
            scanf("%c",&c);
            printf("%c%c",c,tmp);
            continue;
        }
        if(s2 != 1 && s3 != 1) printf("%c",c);
    }
    return 0;
}