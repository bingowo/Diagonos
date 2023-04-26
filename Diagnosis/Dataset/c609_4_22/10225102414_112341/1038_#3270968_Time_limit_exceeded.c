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
    int T, l, pass, i, j, k, c;
    scanf("%d", &T);
    for (i = 0;i < T;i++){
        memset(C, '\0', 501);
        scanf("%s", C);
        l = 0;
        I = (char **)malloc(sizeof(char *) * 501);
        I[l] = (char *)malloc(sizeof(char) * (strlen(C) + 1));
        strcpy(I[l], C);
        for (l = 1;getchar() != '\n';l++){
            pass = 0;
            memset(C, '\0', 501);
            scanf("%s", C);
            c = strlen(C);
            for (k = 0;k < c && C[k] != ',' && C[k] != '.' && C[k] != '!' && C[k] != '?';k++);
            if (k == 0){
                if (c == 1){
                    l -= 1;
                    continue;
                }
            }
            C[k] = '\0';
            if (k == c || k == c - 1){
                for (j = 0;j < l;j++){
                    if (strcmp(I[j], C) == 0){
                        pass = 1;
                        break;
                    }
                }
                if (pass == 1){
                    l -= 1;
                    continue;
                }
                I[l] = (char *)malloc(sizeof(char) * (strlen(C) + 1));
                strcpy(I[l], C);
            }else{
                for (j = 0;j < l;j++){
                    if (strcmp(I[j], C) == 0){
                        pass = 1;
                        break;
                    }
                }
                if (pass == 0 && k != 0){
                    I[l] = (char *)malloc(sizeof(char) * (strlen(C) + 1));
                    strcpy(I[l++], C);
                }
                pass = 0;
                for (j = 0;j < l;j++){
                    if (strcmp(I[j], C + k + 1) == 0){
                        pass = 1;
                        break;
                    }
                }
                if (pass == 0){
                    I[l] = (char *)malloc(sizeof(char) * (strlen(C + k + 1) + 1));
                    strcpy(I[l], C + k + 1);
                }
                if (pass != 0){
                    l -= 1;
                }
            }
        }
        qsort(I, l, sizeof(char *), cmp);
        printf("case #%d:\n", i);
        for (j = 0;j < l;j++){
            printf("%s", I[j]);
            if (j == l - 1){
                printf("\n");
            }else{
                printf(" ");
            }
        }
        free(I);
    }
    return 0;
}