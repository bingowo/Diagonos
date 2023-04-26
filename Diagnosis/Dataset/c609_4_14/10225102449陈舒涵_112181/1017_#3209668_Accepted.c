#include <stdio.h>
#include <stdlib.h>

int cmp1(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;  //升序
}

int cmp2(const void *a, const void *b)
{
    return *(int*)b - *(int*)a;  //降序
}

int main()
{
    char order;
    scanf("%c", &order);
    int n = 0, num;
    int a[100];
    while (scanf("%d", &num) != EOF){
        a[n] = num;
        n ++;
    }
    if (order == 'A'){
        qsort(a, n, sizeof(int), cmp1);
    }
    else{
        qsort(a, n, sizeof(int), cmp2);
    }
    int last = 0;
    for (int i = 0; i < n; i ++){
        if (a[i] != last){
            printf("%d ", a[i]);
            last = a[i];
        }
    }
    return 0;
}