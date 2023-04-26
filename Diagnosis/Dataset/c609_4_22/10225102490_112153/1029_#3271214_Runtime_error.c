#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int c[1000];

int cmp(const void*a, const void*b)
{
    int x = *(int*)a;
    int y = *(int*)b;
    if (c[x] != c[y]) return c[x] - c[y];
    else return x - y;
}

int main()
{
    int m;//a中元素个数
    scanf("%d",&m);
    int *a = (int*)malloc(sizeof(int) * m);
    memset(c,1000,-1);
    for (int i = 0; i < m; i++)
    {
        scanf("%d",&a[i]);
        c[a[i]] = i;
    }
    int n;
    scanf("%d",&n);
    int *b = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) scanf("%d",&b[i]);
    qsort(b,n,sizeof(int),cmp);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",b[i]);
    }
}