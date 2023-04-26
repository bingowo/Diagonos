#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void *p1, const void *p2){
    return *(char*)p1 - *(char*)p2;
}

void Print(char *s, int len){
    for (int i = 0; i != len; i++){
        printf("%c\n", s[i]);
        for (int j = 2; j <= len - i; j++){
            char temp[17];
            strncpy(temp, s+i, j);
            temp[j] = 0;
            printf("%s\n", temp);
        }
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
        Print(s, len); 
    }
}