#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define NUMOFCHARA 26

double table[128];
int seq_char[128];

int cmp(const void *p1, const void *p2){
    char left = *(char*)p1, right = *(char*)p2;
    if (table[left] == table[right])
        return seq_char[left] - seq_char[right];
    return (table[left] > table[right])? -1: 1;
}

int main(){
    for (int i = 'a', weight = 0; i != 'z'; ++i){
        seq_char[i] = weight++;
        seq_char[toupper(i)] = weight++;
    }
    int T; scanf("%d", &T);
    for (int i = 0; i != T; ++i){
        for (int j = 0; j != NUMOFCHARA; ++j){
            double temp; scanf("%lf", &temp);
            table['A' + j] = temp;
            table['a' + j] = temp;
        }
        char s[101]; scanf("%s", s);
        qsort(s, strlen(s), sizeof(char), cmp);
        printf("case #%d:\n%s\n", i, s);
    }
    return 0;    
}