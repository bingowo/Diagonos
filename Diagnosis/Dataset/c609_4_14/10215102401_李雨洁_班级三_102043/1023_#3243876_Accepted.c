#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct date {
    int year;
    int month;
    int day;
}D;

char tb[20][7] = { "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol",
                "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax",
                "koyab", "cumhu", "uayet" };

int cmp(const void* _a, const void* _b)
{
    D a, b;
    a = *((D*)_a);
    b = *((D*)_b);
    if (a.year != b.year) 
        return a.year - b.year;
    else
    {
        if (a.month != b.month) 
            return a.month - b.month;
        else 
            return a.day - b.day;
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int N;
        scanf("%d", &N);
        D* d = (D*)malloc(sizeof(D) * (N + 1));//动态分配空间
        int day;
        char month[10] = { '\0' };
        int year;
        for (int j = 0; j < N; j++)
        {

            scanf("%d", &d[j].day);
            getchar();//输入字符'.'
            scanf("%s", month);
            scanf("%d", &d[j].year);
            for (int k = 0; k < 19; k++)
            {
                if (!strcmp(month, tb[k]))
                {
                    d[j].month = k + 1;//将字符信息转化为数字月份方便比较
                    break;
                }
            }
        }
        qsort(d, N, sizeof(d[0]), cmp);
        printf("case #%d:\n", i);
        for (int j = 0; j < N; j++)
            printf("%d. %s %d\n", d[j].day, tb[d[j].month - 1], d[j].year);
        free(d);
    }
    return 0;
}