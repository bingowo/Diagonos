#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void *p1, const void *p2){
    return *(char*)p1 - *(char*)p2;
}

char str_comb[17] = "";
void Print(char *s, int depth, int k){
    if (depth) printf("%s\n", str_comb);
    for (int i = k; s[i]; i++){
        str_comb[depth] = s[i]; str_comb[depth+1] = 0; 
        Print(s, depth+1, i+1);
    }
}

int main(){
    int n; scanf("%d", &n);
    for (int i = 0; i != n; i++){
        char t[17];
        scanf("%s", t);
        qsort(t, strlen(t), sizeof(t[0]), cmp);
        char s[17] = {0}; int len = 0;
        for (int i = 0; i != strlen(t); i++)
            if (t[i] != t[i+1]) s[len++] = t[i];
        printf("case #%d:\n", i);
        Print(s, 0, 0); 
    }
}