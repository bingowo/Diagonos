#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char str[21];
    int num;
} STRING;

int cmp(const void *a1, const void *b1)
{
    STRING a = *(STRING*)a1;
    STRING b = *(STRING*)b1;
    if (a.num != b.num){
        return b.num - a.num;
    }
    else{
        return strcmp(a.str, b.str);
    }
}

int count(char *s, int length)
{
    int ans = 0, letter[26] = {0};
    for (int i = 0; i < length; i ++){
        letter[s[i] - 'A'] ++;
    }
    for (int i = 0; i < 26; i ++){
        if (letter[i] != 0) ans ++;
    }
    return ans;
}

int main()
{
    int T, n;
    scanf("%d", &T);
    for (int t = 0; t < T; t ++){
        scanf("%d", &n);
        STRING *a = (STRING*)malloc(sizeof(STRING) * n);
        for (int i = 0; i < n; i ++){
            scanf("%s", a[i].str);
            a[i].num = count(a[i].str, strlen(a[i].str));
        }
        qsort(a, n, sizeof(STRING), cmp);
        printf("case #%d:\n", t);
        for (int i = 0; i < n; i ++){
            printf("%s\n", a[i].str);
        }
        free(a);
    }
    return 0;
}