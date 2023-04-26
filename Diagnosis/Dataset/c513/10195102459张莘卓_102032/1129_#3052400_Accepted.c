#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char s[10001];
    scanf("%s",s);
    int start=0, end=0;
    while(s[end]) {
        int cnt = 0;
        while(isalpha(s[end])) ++end;
        for(int i=end; isdigit(s[i]); ++i)
            cnt = cnt*10 + s[i] - '0';
        if(cnt == 0) {
            printf("%s",&s[start]);
            break;
        }
        char t = s[end];
        s[end] = '\0';
        for(int i=0; i<cnt; ++i) printf("%s",&s[start]);
        s[end] = t;
        while(isdigit(s[end])) ++end;
        start = end;
    }
    printf("\n");
    return 0;
}