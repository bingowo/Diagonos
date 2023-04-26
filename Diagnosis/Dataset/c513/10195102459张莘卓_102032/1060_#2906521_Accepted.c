#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isNumber(char c){
    if(c >= '0' && c <= '9') return 1;
    return 0;
}

int main()
{
    char s[101];
    scanf("%s",s);
    int max = 0, i = 0;
    while(s[i]) {
        int cnt = 0;
        while(s[i] && !isNumber(s[i])) ++i;
        while(s[i] == '0') ++i;
        while(isNumber(s[i++])) ++cnt;
        if(cnt > max) max = cnt;
    }
    printf("%d\n",max);
    return 0;
}
