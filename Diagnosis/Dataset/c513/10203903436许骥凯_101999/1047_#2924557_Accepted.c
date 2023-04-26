#include<stdio.h>
#include<string.h>

int main(){
    int n; scanf("%d", &n);
    for (int i = 0; i != n; i++){
        char s[501] = {0}; scanf("%s", s);
        int cnt = 1, len = strlen(s);
        printf("case #%d:\n", i);
        for (int i = 0; i != len - 1; i++){
            if (s[i] != s[i+1] || cnt == 255) {printf("%d%c", cnt, s[i]); cnt = 1;}
            else cnt++;
        }
        printf("%d%c\n", cnt, s[len - 1]);
    }
}