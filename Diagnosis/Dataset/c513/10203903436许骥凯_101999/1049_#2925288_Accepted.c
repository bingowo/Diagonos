#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int find(char **table, char *s, int len){
    for (int i = 0; i != len; i++)
        if (!strcmp(table[i], s)) return 1;
    return 0;
}

int cmp(const void *p1, const void *p2){
    char *s1 = *(char**)p1, *s2 = *(char**)p2;
    return strcmp(s1, s2);
}

int main(){
    int n; scanf("%d", &n); getchar();
    for (int i = 0; i != n; i++){
        char c;
        char **p = (char **) malloc(sizeof(char*) * 501);
        int plen = 0;
        while ((c = getchar()) != '\n'){
            char temp[501]; int tlen = 0;
            while (c != ' ' && c != ',' && c != '.' && c != '?' && c != '!' && c != '\n'){
                temp[tlen++] = c;
                c = getchar();
            }
            temp[tlen] = 0;
            if(tlen != 0 && !find(p, temp, plen)){
                p[plen] = (char*)malloc(sizeof(char) * tlen);
                strcpy(p[plen++], temp);
            }
            if (c == '\n') break;
        }
        printf("case #%d:\n", i);
        qsort(p, plen, sizeof(p[0]), cmp);
        for (int j = 0; j != plen; j++){
            printf("%s%c", p[j], j == plen - 1? '\n': ' ');
            free(p[j]);
        }
        free(p);
    }
}