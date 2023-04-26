#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char c;
    double f;
}input;

int cmp(const void *a, const void *b)
{
    input *A = (input *)a, *B = (input *)b;
    if (A->f == B->f){
        return B->c - A->c;
    }else{
        return (A->f > B->f) ? -1 : 1;
    }
}

int main()
{
    int T, i, j, l;
    double C[26];
    char str[101];
    input s[101];
    scanf("%d", &T);
    for (i = 0;i < T;i++){
        memset(str, '\0', sizeof(char) * 101);
        for (j = 0;j < 26;j++){
            scanf("%lf", &C[j]);
        }
        scanf("%s", str);
        l = strlen(str);
        for (j = 0;j < l;j++){
            s[j].c = str[j];
            if (str[j] < 91){
                s[j].f = C[str[j] - 65];
            }else{
                s[j].f = C[str[j] - 97];
            }
        }
        qsort(s, l, sizeof(input), cmp);
        printf("case #%d:\n", i);
        for (j = 0;j < l;j++){
            printf("%c", s[j].c);
        }
        printf("\n");

    }
    return 0;
}