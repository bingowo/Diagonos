#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char c = getchar();
    //char hex[32] = {'\0'};
    unsigned int ans = 0;
    int flag = 0;

    while(c != EOF && c != '\n'){
        if(c != '0') {
            c = getchar();
            continue;
        }

        if(c == '0'){
            c = getchar();
            if(c != 'x') continue;
            if(c == EOF || c == '\n') break;

            c = getchar();
            if(c > 'f' && c <= 'z') continue;
            if(c == EOF || c == '\n') break;

            flag++;
            //int i = 0;
            while(isdigit(c) || (c <= 'f' && c >= 'a')){
                if(isdigit(c)) ans = ans * 16 + c -'0';
                else ans = ans * 16 + c - 'a' + 10;
                c = getchar();
            }

            if(flag == 1) printf("%u",ans);
            if(flag > 1) printf(" %u",ans);
            ans = 0;

            c = getchar();
        }
    }
    if(flag == 0) printf("-1");

    return 0;
}
