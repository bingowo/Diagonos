#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char s[105] = {0};
    gets(s);
    int slen = strlen(s);
    int maxlen = 0;
    for (int i = 0; i < slen; i++){
        if ('0'<s[i] && s[i]<='9'){
            int len = 0;
            while ('0'<=s[i] && s[i]<='9'){
                len++;
                i++;
            }
            if (maxlen < len) maxlen = len;
        }
    }
    printf("%d\n", maxlen);
    return 0;
}