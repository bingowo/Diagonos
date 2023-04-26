#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Maya
{
    int val;
    int year;
    char month[19];
    int day;

}Date;

int monthtonum(char *m)
{
    static char *months[] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
    for(int i = 0; ; i++)
        if(!strcmp(m, months[i]))
            return i;//返回月份的编号i
}
int cmp(const void *a, const void *b)
{
    return ((Date*)a)->val - ((Date*)b)->val;
}
int main()
{
    Date a[10001];
    int T;
    scanf("%d\n", &T);
    for(int i = 0; i < T; i++)
    {

        int N;
        scanf("%d", &N);
        for(int j = 0; j < N; j++)
        {
            scanf("%d. %s %d", &a[j].day, a[j].month, &a[j].year);//输入年月日
            a[j].val = a[j].year * 1000 + monthtonum(a[j].month) * 20 + a[j].day;
        }
        qsort(a, N, sizeof(Date), cmp);
        printf("case #%d:\n", i);
        for(int k = 0; k < N; k++)
            printf("%d. %s %d\n", a[k].day, a[k].month, a[k].year);
    }
    return 0;
}
