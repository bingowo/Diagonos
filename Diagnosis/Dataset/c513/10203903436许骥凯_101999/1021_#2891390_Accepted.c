#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int tableI[128] = {0};
void createTable(int *target, char *table){
    for (int i = 0; i != 26; i++){
        target[table[i]] = i;
        target[table[i] + 32] = i;
    }
}

int compare(const void *p1, const void *p2){
    char *string1 = *(char**) p1;
    char *string2 = *(char**) p2;
    int len1 = strlen(string1);
    int len2 = strlen(string2);
    int len = (len1 > len2)? len2: len1;
    for (int i = 0; i != len; i++){
        if (tableI[string1[i]] > tableI[string2[i]]) return 1;
        else if(tableI[string1[i]] < tableI[string2[i]]) return -1;
    }
    return len1-len2;
}

void output(char **strings, int len){
    for (int i = 0; i != len; i++)
        if (i != len-1) printf("%s ", strings[i]);
        else printf("%s\n", strings[i]);
}

int main(){
    char c;
    do{
        char table[26];
        scanf("%s", table);
        createTable(tableI, table);
        char **strings = (char**)malloc(sizeof(char*) * 100);
        int len = 0;
        do{
            char temp[20];
            scanf("%s", temp);
            strings[len] = (char*)malloc(sizeof(char) * strlen(temp));
            strcpy(strings[len++], temp);
        }while((c = getchar()) != '\n');
        qsort(strings, len, sizeof(strings[0]), compare);
        output(strings, len);
        for (int i = 0; i != len; i++)
            free(strings[i]);
        free(strings);
        c = getchar();
        if (c == EOF) break;
        else ungetc(c, stdin);
    }while(1);
    return 0;
}