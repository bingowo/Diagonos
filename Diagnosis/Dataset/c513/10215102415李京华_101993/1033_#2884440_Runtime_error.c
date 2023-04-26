#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int day;
    int month;
    int year;
}Maya;

int cmp(const void *_a, const void *_b){
    Maya a = *(Maya *)_a;
    Maya b = *(Maya *)_b;
    if (a.year != b.year)
        return a.year - b.year;
    if (a.month != b.month)
        return a.month - b.month;
    return a.day - b.day;
}

int main()
{
    int t, T;
    scanf("%d", &T);
    char Tab[19][7] = {"pop", "no", "zip", "zotz", "tzec",
        "xul", "yoxkin", "mol", "chen", "yax",
        "zac", "ceh", "mac", "kankin", "muan",
        "pax", "koyab", "cumhu", "uayet"};

    for (t = 0; t < T; t++) {
        int n;
        scanf("%d", &n);
        Maya a[n];
        int i;
        //输入
        for (i = 0; i < n; i++){
            //日
            scanf("%d.", &a[i].day);
            //月
            char res[7];
            scanf("%s", res);
            for (int j = 0; j < 19; j++)
                if (strcmp(res, Tab[j]) == 0){
                    a[i].month = j;
                    break;
                }
                    
            //年
            scanf("%d", &a[i].year);
        }

        qsort(a, n, sizeof(a[0]), cmp);

        //输出
        printf("case #%d:\n", t);
        for (i = 0; i < n; i++)
            printf("%d. %s %d\n", a[i].day, a[i].month, a[i].year);
    }
    return 0;
}