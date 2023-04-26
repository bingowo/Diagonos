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
        return (A->c > B->c) ? -1 : 1;
    }else{
        return (A->f > B->f) ? -1 : 1;
    }
}

int main()
{
    int T, i, j, l;
    double C[26];
    char str[101];
    input *s;
    scanf("%d", &T);
    for (i = 0;i < T;i++){
        memset(str, '\0', sizeof(char) * 101);
        s = (input *)malloc(sizeof(input) * 100);
        for (j = 0;j < 26;j++){
            scanf("%lf", &C[j]);
        }
        scanf("%s", str);
        l = strlen(str);
        for (j = 0;j < l;j++){
            s[j].c = str[j];
            if (str[j] <= 90 && str[j] >= 65){
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
        free(s);
    }
    return 0;
}