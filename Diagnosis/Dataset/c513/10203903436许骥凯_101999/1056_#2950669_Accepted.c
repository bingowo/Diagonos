#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp(const void *p1, const void *p2){
    return strlen(*(char**)p2) - strlen(*(char**)p1);
}


int find(char *s, int lo, int len, char** table, int tlen, int slen){
    s[len--] = 0;
    while(strlen(s) != 1){
        for (int i = 0; i != tlen; i++){
            if (!strcmp(s, table[i])){ 
                printf("%s%c", s, (lo + len == slen? '\n': ' '));
                return strlen(s);
            }
        }
        s[len--] = 0;
    }
    printf("%s%c", s, (lo + len == slen? '\n': ' '));
    return 1;
}
int main(){
    int n; scanf("%d", &n);
    char **s = (char**)malloc(sizeof(char*) * n);
    for (int i = 0; i != n; i++){
        char temp[15]; scanf("%s", temp);
        s[i] = (char*)malloc(sizeof(char) * strlen(temp));
        strcpy(s[i], temp);
    }
    qsort(s, n, sizeof(s[0]), cmp);

    char spS[5001]; scanf("%s", spS);
    int slen = strlen(spS);
    for (int i = 0; i < slen;){
        char temp[slen]; strcpy(temp, spS+i);
        i += find(temp, i, strlen(s[0]), s, n, slen);
    }
    for (int i = 0; i != n; i++) free(s[i]);
    free(s);
    return 0;
}