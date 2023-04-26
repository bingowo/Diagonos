#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    char *A = *(char **)a, *B = *(char **)b;
    return strcmp(A, B);
}

int main()
{
    char **I, C[501];
    int T, l, i, j, k, c;
    scanf("%d", &T);
    for (i = 0;i < T;i++){
        scanf("%s", C);
        l = 0;
        I = (char **)malloc(sizeof(char *) * 501);
        I[l] = (char *)malloc(sizeof(char) * (strlen(C) + 1));
        strcpy(I[l], C);
        for (l = 1;getchar() != '\n';l++){
            scanf("%s", C);
            c = strlen(C);
            for (k = 0;k < c && C[k] != ',' && C[k] != '.' && C[k] != '!' && C[k] != '?';k++);
            if (k == 0){
                if (c == 1){
                    l -= 1;
                    continue;
                }else if(C[k + 1] == ',' || C[k + 1] == '.' || C[k + 1] == '!' || C[k + 1] == '?'){
                    l -= 1;
                    continue;
                }
                I[l] = (char *)malloc(sizeof(char) * (strlen(C) + 1));
                strcpy(I[l], C);
            }
            C[k] = '\0';
            if (k == c || k == c - 1){
                I[l] = (char *)malloc(sizeof(char) * (strlen(C) + 1));
                strcpy(I[l], C);
            }else{
                I[l] = (char *)malloc(sizeof(char) * (strlen(C) + 1));
                strcpy(I[l++], C);
                I[l] = (char *)malloc(sizeof(char) * (strlen(C + k + 1) + 1));
                strcpy(I[l], C + k + 1);
            }
        }
        qsort(I, l, sizeof(char *), cmp);
        printf("case #%d:\n", i);
        for (j = 0;j < l;j++){
            if (j > 0 && strcmp(I[j - 1], I[j]) == 0){
                continue;
            }else{
                printf("%s ", I[j]);
            }
        }
        printf("\n");
        free(I);
    }
    return 0;
}