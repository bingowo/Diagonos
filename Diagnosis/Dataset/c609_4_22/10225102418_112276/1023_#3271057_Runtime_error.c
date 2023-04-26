#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Date
{
    int year;
    int month;
    int day;
} D;

char tb[20][10] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol",
                   "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax",
                   "koyab", "cumhu", "uayet"};

int cmp(D a, D b)
{
    if (a.year != b.year)
        return b.year - a.year;
    else
    {
        if (a.month != b.month)
            return b.month - a.month;
        else
            return b.day - a.day;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int N;
        scanf("%d", &N);
        D *d = (D *)malloc(sizeof(D) * (N + 1));
        int day;
        char month[10] = {'\0'};
        int year;
        for (int j = 0; j < N; ++j)
        {
            scanf("%d", &d[j].day);
            getchar();
            scanf("%s", &month);
            scanf("%d", &d[j].year);
            for (int k = 0; k < 19; ++k)
            {
                if (!strcmp(month, tb[k]))
                {
                    d[j].month = k + 1;
                    break;
                }
            }
        }
        qsort(d, N, sizeof(d), cmp);
        printf("case #%d:\n", i);
        for (int j = 0; j < N; j++)
        {
            printf("%d. %s %d\n", d[j].day, tb[d[j].month - 1], d[j].year);
        }
        free(d);
    }
    return 0;
}
