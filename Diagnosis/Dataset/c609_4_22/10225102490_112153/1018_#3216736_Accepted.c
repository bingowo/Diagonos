#include <stdio.h>
#include <stdlib.h>

int cmp (const void *a, const void *b)
{
    if (*(int*)a > *(int*)b) return 1;
    else return -1;
}

int main()
{
    int n;
    scanf("%d",&n);
    int *a = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(int),cmp);
    int sum = 0;
    for (int i = 0; i < n; i += 2)
    {
        sum = sum + a[i+1] - a[i];
    }
    printf("%d",sum);
    return 0;
}
