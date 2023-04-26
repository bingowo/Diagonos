#include <stdio.h>
#include <string.h>
int main(){
    char s[51];
    scanf("%s", s);
    int max = 1;
    int i, j;
    int cnt = 1;
    for (i = 1; i < strlen(s); ++i) {
        if (s[i] != s[i-1]){
            cnt++;
            if (cnt > max)
                max = cnt;
        }
        else
            cnt = 1;
    }
    printf("%d", max);
    return 0;
}