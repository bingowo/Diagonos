#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b)
{
    int* pa = (int*)a;
    int* pb = (int*)b;
    if(*pa > *pb) return 1;
    else return -1;
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    int* p = (int*)malloc(sizeof(int)*n);
    long int sum = 0;
    int i = 0;
    for(i = 0; i<n; i++)
    {
        scanf("%d", &p[i]);
    }
    qsort(p, n, sizeof(int), cmp);
    for(i = 1; i<n; i += 2)
    {
        sum += p[i] - p[i-1];
    }
    printf("%ld", sum);
    free(p);
    return 0;
}
