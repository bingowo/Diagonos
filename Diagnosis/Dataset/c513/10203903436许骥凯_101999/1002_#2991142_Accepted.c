#include<stdio.h>

int main(){
    int pro; scanf("%d", &pro);
    for (int i = 0; i != pro; i++){
        printf("case #%d:\n", i);
        int table[128]; for (int i = 0; i != 128; i++) table[i] = -1;
        char s[100]; scanf("%s", s);
        int r = 0; char *p = s;
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
        while(*p) res =  res * r + table[*p++];
        printf("%lld\n", res);
    }
    return 0;
}