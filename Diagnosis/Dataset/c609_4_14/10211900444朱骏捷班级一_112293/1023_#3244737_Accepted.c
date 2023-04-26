#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int val;   // 表示日期“大小”的值
    int y;     // 年
    int d;     // 日
    char m[7]; // 玛雅历的月份
} RECORD;

RECORD a[10001]; // 存储N个Maya日期

int month2idx(char *m)
{
    // 1-19月份数组，为静态字符串数组
    static char *month[] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
    for (int i = 0;; i++)
        if (!strcmp(m, month[i]))
            return i; // 返回月份编号i
}

int cmp(const void *a, const void *b)
{
    return ((RECORD *)a)->val - ((RECORD *)b)->val;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int z = 0; z < T; z++)
    {
        int N;
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
        {
            scanf("%d.%s %d", &a[i].d, a[i].m, &a[i].y); // 输入日月年
            a[i].val = a[i].y * 1000 + month2idx(a[i].m) * 20 + a[i].d;
        }
        qsort(a, N, sizeof(RECORD), cmp);
        printf("case #%d:\n", z);
        for (int i = 0; i < N; i++)
            printf("%d. %s %d\n", a[i].d, a[i].m, a[i].y);
    }
    return 0;
}
