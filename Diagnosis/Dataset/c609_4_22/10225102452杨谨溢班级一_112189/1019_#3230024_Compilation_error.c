#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int num;
    int length;
}NUM;
NUM* a = (NUM*)malloc(1000009 * sizeof(NUM));

int cmp(const void* a, const void* b)  // 升序
{
    NUM A = *(NUM*)a, B = *(NUM*)b;
    /*int a2 = 0, b2 = 0;
    char aa[12];
    char bb[12];
    sprintf(aa, "%d", A);
    sprintf(bb, "%d", B);
    a2 = strlen(aa);
    b2 = strlen(bb);
    if (A < 0) a2--;
    if (B < 0)  b2--;*/
    if (A.length== B.length)   return A.num < B.num ? -1 : 1;
    else return B.length - A.length;
}

int main()
{
    int n = 0, i;
    while (scanf("%d", &a[n].num) != EOF)
    {
        int m = a[n].num <= 0 ? 1 : 0;
        int nn = a[n].num < 0 ? 0 - a[n].num : a[n].num;
        while (nn>0)
        {
            m++;
            nn /= 10;
        }
        a[n].length = m;
        n++;
    }
    qsort(a, n, sizeof(a[0]), cmp);
    for (i = 0; i < n; i++)
    {
        printf("%d%c", a[i].num, i == n - 1 ? '\n' : ' ');
    }
    return 0;
}