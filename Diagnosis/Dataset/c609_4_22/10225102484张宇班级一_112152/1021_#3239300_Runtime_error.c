#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char p[26];

int trans(char t){
    if (t >= 'a' && t <= 'z')
        t = t - 32;
    int j = 0;
    for (; j < 26; j++){
        if (t == p[j])
            break;
    }
    return j;
}

int cmp(const void* a, const void* b){
    char *str1 = (char*)a;
    char *str2 = (char*)b;
    for (int i = 0; str1[i] != 0 && str2[i] != 0; i++){
        if (trans(str1[i]) > trans(str2[i]))
            return 1;
        else if (trans(str1[i]) < trans(str2[i]))
            return -1;
    }
    if (strlen(str1) > strlen(str2))
        return 1;
    else if (strlen(str1) < strlen(str2))
        return -1;
    else
        return 0;
}

int main(){
    while (fgets(p, 27, stdin) != NULL){
        char in[100][21];
        int n = 0;
        while (scanf("%s", in[n]) != EOF)
            n++;
        qsort(in, n, sizeof(in[0]), cmp);
        for (int i = 0; i < n; i++)
            printf("%s ", in[i]);
        printf("\n");
    }
    return 0;
}
