#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct data{
    int day;
    char month[7];
    int year;
    int val;
}a[101];

int change_m(char *s) {
    static char* m19[] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
    for (int i = 0;; i++) {
        if (!strcmp(s,m19[i])) return i;
    }
}

int cmp(const void *a, const void *b) {
    struct data *a1 = (struct data *)a;
    struct data *b1 = (struct data *)b;
    return a1->val - b1->val;
}

int main()
{
    int T;
    scanf("%d",&T);

    for (int i = 0; i < T; i++) {
        int N;
        scanf("%d",&N);
        for (int j = 0; j < N; j++) {
            scanf("%d. %s %d\n",&a[j].day, a[j].month, &a[j].year);
            a[j].val = a[j].year*1000 + (change_m(a[j].month)) * 20 + a[j].day;
        }
        printf("case #%d:\n",i);
        qsort(a, N, sizeof(a[0]), cmp);

        for (int j = 0; j < N; j++) {
            printf("%d. %s %d\n",a[j].day, a[j].month, a[j].year);
        }

    }
    return 0;
}
