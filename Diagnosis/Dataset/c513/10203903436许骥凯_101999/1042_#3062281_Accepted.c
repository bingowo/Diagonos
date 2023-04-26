#include<stdio.h>
#include<string.h>

void process(char *s, char *t){
    int table[128]; memset(table, 0, 128 * 4);
    while(*s) table[*s++] = 1;
    for (int i = 0; i != 128; ++i)
        if (table[i]) *t++ = i;
    *t++ = '\0';
}

void Print(char *t, char *predix, int len_pre){
    for (int i = 0; i != strlen(t); ++i){
        printf("%s%c\n", predix, t[i]);
        char temp[17]; strcpy(temp, predix);
        temp[len_pre] = t[i];
        temp[len_pre + 1] = '\0';
        Print(t + i + 1, temp, len_pre + 1);
    } 
}

int main(){
    int n; scanf("%d", &n);
    for (int i = 0; i != n; ++i){
        printf("case #%d:\n", i);
        char s[17];
        scanf("%s", s);
        char t[17];
        process(s, t);
        char predix[17] = {'\0'};
        Print(t, predix, 0);
    } 
    return 0;   
}