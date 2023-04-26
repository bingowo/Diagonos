#include<stdio.h>

int main(){
    int pro; scanf("%d", &pro);
    for (int i = 0; i != pro; i++){
        int table[128]; for (int i = 0; i != 128; i++) table[i] = -1;
        char s[60]; scanf("%s", s);
        char *p = s; int r = 0;
        table[*p] = 1;
        while(*++p){
            if (table[*p] == -1){
                table[*p] = r;
                r = r? r + 1: 2;
            }
        }
        if (r < 2) r = 2;
        p = s;
        long long res = 0;
        while(*p) res = res * r + table[*p++];
        printf("case #%d:\n%lld\n", i, res);
    }
    return 0;
}