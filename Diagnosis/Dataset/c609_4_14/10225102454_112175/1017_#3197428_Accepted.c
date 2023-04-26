#include <stdio.h>
#include <stdlib.h>

#define N 1006
int n, a[N], ans[N];

int cmp1 (const void* a, const void* b)
{
    return *((int*)a) - *((int*)b);
}

int cmp2 (const void* a, const void* b)
{
    return *((int*)b) - *((int*)a);
}

int main(void)
{ 
    
    int up = 1;
    char ch = getchar();
    if (ch != 'A')
        up = 0;

    int cnt = 1;
    while (scanf("%d", &a[cnt]) != EOF)
        cnt++;
    cnt--;
    if (up)
        qsort(a + 1, cnt, sizeof(a[1]), cmp1);
    else
        qsort(a + 1, cnt, sizeof(a[1]), cmp2);
    int pre = 0;
    int c = 0;
    for (int i = 1; i <= cnt; i++)
        if (a[i] != pre)
            ans[++c] = a[i] , pre = a[i];

    for (int i = 1; i <= c; i++)
        if (i != c)
            printf("%d ", ans[i]);
        else
            printf("%d", ans[i]);
    return 0;
}