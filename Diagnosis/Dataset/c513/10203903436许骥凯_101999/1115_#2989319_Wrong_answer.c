#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n; scanf("%d", &n);
    for (int i = 0; i != n; i++){
        printf("case #%d:\n", i);
        char s[20]; scanf("%s", s);
        int slen = strlen(s);
        for (int j = slen - 1; j >= 1; j--){
            if (s[j] > s[j-1]){
                char t = s[j];
                s[j] = s[j-1];
                s[j-1] = t;
                break;
            }
        }
        printf("%lld\n", atoll(s));
    }
}