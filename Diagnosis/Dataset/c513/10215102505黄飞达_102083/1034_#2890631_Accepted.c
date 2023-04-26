#include<stdio.h>
#include<stdlib.h>
#include<string.h>

double value[128] = {0};

int cmp(const void*a, const void*b){
    char x = *(char*)a;
    char y = *(char*)b;
    if (value[x] != value[y]) return value[x] > value[y] ? -1 : 1;
    else if (abs(x-y)<26) return x < y ? -1 : 1;
    else {
        if (x >= 'a') return x-'a'+'A' <= y ? -1 : 1;
        else return y-'a'+'A' < x ? -1 : 1;
    }
}

int main(){
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        char s[101];    
        for (int i = 0; i < 26; i++){
            scanf("%lf ", &value['A' + i]);
            value['a' + i] = value['A' + i]; 
        }
        gets(s);
        int len = strlen(s);
        qsort(s, len, sizeof(char), cmp);
        printf("case #%d:\n", t);
        for (int i = 0; i < len; i++) printf("%c", s[i]);
        printf("\n");        
    }

    return 0;

    // bBBc ', bcBB ...'
}