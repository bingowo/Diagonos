#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char C[27];

int cmp(const void *a, const void *b)
{
    char *A = *(char **)a, *B = *(char **)b;
    int i, x, y;
    for (i = 0;A[i] == B[i] && i < 31;i++);
    for (x = 0;C[x] != A[i] && C[x] != A[i] - 32 && x < 27;x++);
    for (y = 0;C[y] != B[i] && C[y] != B[i] - 32 && y < 27;y++);
    if (x == 26){
        return 1;
    }else if (y == 26){
        return 1;
    }
    
    return x - y;
}



int main()
{
    char **I;
    int i, j;
    while (scanf("%s", C) != EOF){

        I = (char **)malloc(sizeof(char *) * 100);
        for (i = 0;i < 101;i++){
            I[i] = (char *)malloc(sizeof(char) * 101);
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
        free(I);
    }
    return 0;
}