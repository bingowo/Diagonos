#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    int x = *(int *)a, y = *(int *)b, X = 0, Y = 0;
    while(x != 0){
        X += 1;
        x /= 10;
    }
    while(y != 0){
        Y += 1;
        y /= 10;
    }
    if (X == Y){
        return *(int *)a - *(int *)b;
    }else{
        return Y - X;
    }
}

int main()
{
    int *N, i, j;
    N = (int *)malloc(sizeof(int) * 1000000);
    for (i = 0;scanf("%d", &N[i]) != EOF;i++);
    qsort(N, i, sizeof(int), cmp);
    for (j = 0;j < i;j++){
        printf("%d ", N[j]);
    }
    return 0;
}