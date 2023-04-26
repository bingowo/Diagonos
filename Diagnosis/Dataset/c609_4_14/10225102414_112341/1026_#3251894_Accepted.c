#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char str[21];
    int num;
}input;

int cmp(const void *a, const void *b)
{
    input *A = (input *)a, *B = (input *)b;
    if (A->num == B->num){
        return strcmp(A->str, B->str);
    }else{
        return B->num - A->num;
    }
}

int main()
{
    int T, n, i, j, k, l, m, jud;
    input I[100];
    scanf("%d", &T);
    for (i = 0;i < T;i++){
        scanf("%d", &n);
        for (j = 0;j < n;j++){
            scanf("%s", I[j].str);
            I[j].num = 0;
        }
        for (j = 0;j < n;j++){
            l = strlen(I[j].str);
            for (k = 0;k < l;k++){
                jud = 0;
                for (m = k - 1;m >= 0;m--){
                    if (I[j].str[k] == I[j].str[m]){
                        jud = 1;
                        break;
                    }
                }
                if (jud == 0){
                    I[j].num += 1;
                }
            }
        }
        qsort(I, n, sizeof(input), cmp);
        printf("case #%d:\n", i);
        for (j = 0;j < n;j++){
            printf("%s\n", I[j].str);
        }
    }
    return 0;
}