#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char table[64];

void reverse(int *t, int len){
    int lo = len - 8, hi = len - 1;
    while(lo <= hi){
        int temp = t[lo];
        t[lo++] = t[hi];
        t[hi--] = temp;
    }
}

char *process(char *s, int len){
    if (len == 0){char *temp = (char *)malloc(sizeof(char));  temp[0] = 0; return temp;}
    
    char *temp = (char *)malloc(sizeof(char) * 5);
    int *l = (int *)malloc(sizeof(int) * 24);
    int llen = 0;
    for (int i = 0; i != len; i++){
        int ct = s[i];
        for (int j = 0; j != 8; j++){
            l[llen++] = ct % 2;
            ct /= 2;
        }
        reverse(l, llen);
    }
    while (llen % 6) l[llen++] = 0;
    
    int tlen = 0; int sum = 0;
    for (int i = 0; i != llen; i++){
        if (i != 0 && !(i % 6)) {temp[tlen++] = table[sum]; sum = 0;}
        sum = l[i] + sum * 2;
    }
    temp[tlen++] = table[sum]; //maybe false

    while(tlen != 4) temp[tlen++] = '=';
    temp[tlen] = 0;

    free(l);
    return temp;
}

void Init(){
    int i = 0;
    for (; i != 26; i++)
        table[i] = 'A' + i;
    for (; i != 52; i++)
        table[i] = 'a' + i - 26;
    for (; i != 62; i++)
        table[i] = '0' + i - 52;
    table[62] = '+', table[63] = '/';
}

int main(){
    int n; scanf("%d", &n);
    Init();
    for (int i = 0; i != n; i++){
        char s[101]; scanf("%s", s);
        int len = strlen(s);
        printf("case #%d:\n", i);
        for (int j = 2; j < len; j += 3){
            char *temp = process(s + j - 2, 3);
            printf("%s", temp);
            free(temp);
        }

        char *temp = process(s + len - (len % 3), len % 3);
        printf("%s\n", temp);
        free(temp);
    }
    return 0;
}