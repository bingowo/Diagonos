#include <stdio.h>
#include <stdlib.h>
int weishu(int n)
{
    if (n < 0) n = -n;
    if (n == 0) return 1;
    int sum = 0;
    while (n != 0)
    {
        sum++;
        n /= 10;
    }
    return sum;
}

int cmp(const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;
    if (weishu(x) != weishu(y)) return weishu(y) - weishu(x);
    else return x - y;
}
int a[111111];
int main()
{
    int i = 0;
    while ((scanf("%d",&a[i])) != EOF) i++;
    qsort(a,i,sizeof(int),cmp);
    for (int j = 0; j < i; j++)
    {
        printf("%d ",a[j]);
    }
    return 0;
}
