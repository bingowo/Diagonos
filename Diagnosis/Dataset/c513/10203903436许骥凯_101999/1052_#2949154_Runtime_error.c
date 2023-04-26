#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char t[10][6] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NIGHT"};
char *table[999];

int cmp(const void *p1, const void *p2){
    return *(char*)p1 - *(char*)p2;
}

char *getString(char *s1, char *s2, char *s3){
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int len3 = strlen(s3);
    int len = len1 + len2 + len3;
    char *temp = (char*)malloc(sizeof(char) * len + 1);
    strcpy(temp, s1); strcpy(temp + len1, s2);
    strcpy(temp + len1 + len2, s3);
    temp[len] = 0;
    qsort(temp, len, sizeof(temp[0]), cmp);
    return temp;
}

void init(){
    for (int i = 0; i != 10; i++){
        for (int j = 0; j != 10; j++){
            for (int k = 0; k != 10; k++){ 
                char *temp = getString(t[i], t[j], t[k]);
                table[i*100 + j*10 + k] = (char*)malloc(sizeof(char) * strlen(temp));
                strcpy(table[i*100 + j*10 + k], temp);
                free(temp);
            }
        }
    }
}


int Scmp(char *s){
    for (int i = 0; i != 1000; i++)
        if (!strcmp(table[i], s)) return i;
}
int main(){
    init();
    int n; scanf("%d", &n);
    for (int i = 0; i != n; i++){
        char s[16]; scanf("%s", s);
        int len = strlen(s); qsort(s, len, sizeof(s[0]), cmp);
        printf("case #%d:\n%03d\n", i, Scmp(s));
    }
    for(int i = 0; i != 1000; i++)
        free(table[i]);
    return 0;
}