#include<stdio.h>
#include<string.h>

int main(){
    char s[51];
    gets(s);
    int maxlen = 1, templen = 1;
    for (int i = 1; i < strlen(s); i++){
        if (s[i]!=s[i-1]) templen++;
        else {
            if (templen > maxlen) maxlen = templen;
            templen = 1;
        }
    }
    if (templen > maxlen) maxlen = templen;
    printf("%d\n", maxlen);
    return 0;
}