#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
    static char C[27];
    char *A = *(char **)a, *B = *(char **)b;
    int i, x, y;
    for (i = 0;A[i] == B[i] && i < 30;i++);
    if (A[i] != B[i]){
        for (x = 0;C[x] != A[i] && C[x] != A[i] - 32;x++);
        for (y = 0;C[y] != B[i] && C[y] != B[i] - 32;y++);
        return x - y;
    }else{
        return 0;
    }
}

int main()
{
    static char C[27];
    char **I;
    int i, j;
    while (scanf("%s", C) != EOF){
        I = (char **)malloc(sizeof(char *) * 100);
        for (i = 0;i < 101;i++){
            I[i] = (char *)malloc(sizeof(char) * 31);
        }
        i = 0;j = 0;
        I[i][j] = getchar();
        do
        {
            scanf("%s", I[i]);
            i += 1;
        }while(getchar() != '\n');
        qsort(I, i, sizeof(char *), cmp);
        for (j = 0;j < i;j++){
            printf("%s", I[j]);
            if (j != i - 1){
                printf(" ");
            }else{
                printf("\n");
            }
        }
    }
    return 0;
}