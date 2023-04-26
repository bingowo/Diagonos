#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int strnumcmp(const void *a, const void *b)
{
    char *A = *(char **)a, *B = *(char **)b, C[8];
    int i, j, n = 0, x = 100000000, y = 100000000;
    memset(C, '\0', 8);
    for (i = 0;i < strlen(A);i++){
        if (A[i] > 47 && A[i] < 58){
            for (j = 0;A[i] > 47 && A[i] < 58;i++){
                C[j] = A[i];
                j++;
            }
            x = atoi(C);
            memset(C, '\0', 8);
            n += 1;
            break;
        }
    }
    for (i = 0;i < strlen(B);i++){
        if (B[i] > 47 && B[i] < 58){
            for (j = 0;B[i] > 47 && B[i] < 58;i++){
                C[j] = B[i];
                j++;
            }
            y = atoi(C);
            memset(C, '\0', 8);
            n += 1;
            break;
        }else if(i == strlen(B) - 1 && n == 0){
            return strcmp(A, B);
        }
    }
    if (n == 2){
        if (x == y){
            return strcmp(A, B);
        }
        return x - y;
    }else{
        if (x == 100000000 && y != 100000000){
            return -1;
        }else{
            return 1;
        }
    }
}

int main()
{
    char **I;
    int i, j;
    I = (char **)malloc(sizeof(char *) * 90);
    for (i = 0;i < 90;i++){
        I[i] = (char *)malloc(sizeof(char) * 31);
    }
    for (i = 0;scanf("%s", I[i]) != EOF;i++);
    qsort(I, i, sizeof(char *), strnumcmp);
    for (j = 0;j < i;j++){
        printf("%s ", I[j]);
    }
    free(I);
    return 0;
}
