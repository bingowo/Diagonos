#include <stdio.h>
#include <stdlib.h>

int cmpA(const void *a, const void *b)
{
   return *(int *)a - *(int *)b;
}

int cmpD(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}

int main()
{
    int N[100], i, j;
    if (getchar() == 'A'){
        for (i = 0;scanf("%d", &N[i]) != EOF;i++){
            for (j = 0;j < i;j++){
                if (N[j] == N[i]){
                    i -= 1;
                }
            }
        }
        qsort(N, i, sizeof(int), cmpA);
    }else{
        for (i = 0;scanf("%d", &N[i]) != EOF;i++){
            for (j = 0;j < i;j++){
                if (N[j] == N[i]){
                    i -= 1;
                }
            }
        }
        qsort(N, i, sizeof(int), cmpD);
    }
    for (j = 0;j < i;j++){
        printf("%d", N[j]);
        if (j != i - 1){
            printf(" ");
        }
    }
    return 0;
}