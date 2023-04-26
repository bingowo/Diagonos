#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int c[500];

int cmp(const void*a, const void*b)
{
    int x = *(int*)a;
    int y = *(int*)b;
    if (c[x] != c[y]) //return c[x] - c[y];
    {
        if (c[x] > c[y]) return 1;
        else return -1;
    }
    else //return x - y;
    {
        if (x > y) return 1;
        else return -1;
    }
}

int main()
{
    int m;//a中元素个数
    scanf("%d",&m);
    int *a = (int*)malloc(sizeof(int) * m);
    memset(c,m,sizeof(c));
    for (int i = 0; i < m; i++)
    {
        scanf("%d",&a[i]);
        c[a[i]] = i;
    }
    free(a);
    int n;
    scanf("%d",&n);
    int *b = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) scanf("%d",&b[i]);
    qsort(b,n,sizeof(int),cmp);
    free(c);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",b[i]);
    }
    free(b);
}