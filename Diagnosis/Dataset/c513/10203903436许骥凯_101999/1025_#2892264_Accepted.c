#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void input(char** strings, int number){
    for (int i = 0; i != number; i++){
        char temp[20];
        scanf("%s", temp);
        strings[i] = (char*)malloc(sizeof(char) * strlen(temp));
        strcpy(strings[i], temp);
    }
}

int difFind(char *string){
    int table[128] = {0}, len = strlen(string), cnt = 0;
    for (int i = 0; i != len; i++){
        if (table[string[i]] == 0) cnt++;
        table[string[i]]++;
    }
    return cnt;
}

int compare(const void *p1, const void *p2){
    char *string1 = *(char**)p1, *string2 = *(char**)p2;
    int difLen1 = difFind(string1), difLen2 = difFind(string2);
    if (difLen1 == difLen2) return strcmp(string1, string2);
    return  difLen2 - difLen1;
}

void output(char **strings, int len, int times){
    printf("case #%d:\n", times);
    for (int i = 0; i != len; i++){
        printf("%s\n", strings[i]);
        free(strings[i]);
    }
    free(strings);
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i != n; i++){
        int number;
        scanf("%d", &number);
        char **strings = (char**)malloc(sizeof(char*) *number);
        input(strings, number);
        qsort(strings, number, sizeof(strings[0]), compare);
        output(strings, number, i);
    }
    return 0;
}