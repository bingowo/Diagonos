#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char s[10001];
    scanf("%s",s);
    int i = 0;
    while(s[i]) {
        char t[10001];
        int k = 0, cnt = 0;
        while(isalpha(s[i])) t[k++] = s[i++];
        t[k] = '\0';
        for(; isdigit(s[i]); ++i)
            cnt = cnt*10 + s[i] - '0';
        if(! cnt) cnt = 1;
        for(int i=0; i<cnt; ++i) printf("%s",t);
    }
    printf("\n");
    return 0;
}