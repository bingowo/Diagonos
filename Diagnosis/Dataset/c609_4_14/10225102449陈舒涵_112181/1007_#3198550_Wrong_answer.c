#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a1, const void *b1)
{
    int a = *(int*)a1;
    int b = *(int*)b1;
    int x = a, y = b, na = 0, nb = 0;
    while (x > 0){
        if (x % 2 == 1) na ++;
        x /= 2;
    }while (y > 0){
        if (y % 2 == 1) nb ++;
        y /= 2;
    }
    if (na != nb){
        return nb - na;
    }
    else{
        return a - b;
    }
}

int main()
{
    int T, N;
    for (int t = 0; t < T; t ++){
        scanf("%d", &N);
        int num[10000];
        for (int i = 0; i < N; i ++){
            scanf("%d", &num[i]);
        }
        qsort(num, N, sizeof(int), cmp);
        printf("case #%d:\n");
        for (int i = 0; i < N; i ++){
            printf("%d ", num[i]);
        }
    }
    return 0;
}
