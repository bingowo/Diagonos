#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char str[31];
    int num;
} STRING;

int count(STRING *a, int n)
{
    int i = 0;
    while (i < strlen(a[n].str) && !(a[n].str[i] >= '0' && a[n].str[i] <= '9')){
        i ++;
    }
    if (i == strlen(a[n].str)){
        return -1;
    }
    else{
        int ans = 0;
        while (i < strlen(a[n].str) && a[n].str[i] >= '0' && a[n].str[i] <= '9'){
            ans = ans * 10 + a[n].str[i] - '0';
            i ++;
        }
        return ans;
    }
}

int strnumcmp(const void *a1, const void *b1)
{
    STRING a = *(STRING*)a1;
    STRING b = *(STRING*)b1;
    if (a.num > b.num) return 1;
    else if (a.num < b.num) return -1;
    else return strcmp(a.str, b.str);
}

int main()
{
    char s[31];
    int n = 0;
    STRING *a = (STRING*)malloc(sizeof(STRING) * 100);
    while (scanf("%s", s) != EOF){
        strcpy(a[n].str, s);
        a[n].num = count(a, n);
        n ++;
    }
    if (n == 1){
        printf("%s", a[0]);
    }
    else{
        qsort(a, n, sizeof(STRING), strnumcmp);
        for (int i = 0; i < n; i ++){
            printf("%s ", a[i].str);
        }
    }
    free(a);
    return 0;
}