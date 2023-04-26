#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int y;
    int m;
    int d;
    char month[10];
} DATE;

int cmp(const void *a1, const void *b1)
{
    DATE a = *(DATE*)a1;
    DATE b = *(DATE*)b1;
    if (a.y != b.y){
        return a.y - b.y;
    }
    else{
        if (a.m != b.m){
            return a.m - b.m;
        }
        else{
            return a.d - b.d;
        }
    }
}

int nmonth(char *m)
{
    char *M[] = {"pop", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
    for (int j = 0;; j ++){
        if (!strcmp(M[j], m)) return j;
    }
}

int main()
{
    int T, N;
    scanf("%d", &T);
    for (int t = 0; t < T; t ++){
        scanf("%d", &N);
        DATE *a = (DATE*)malloc(sizeof(DATE) * N);
        for (int i = 0; i < N; i ++){
            scanf("%d. %s %d", &a[i].d, a[i].month, &a[i].y);
            a[i].m = nmonth(a[i].month);
        }
        qsort(a, N, sizeof(DATE), cmp);
        printf("case #%d:\n", t);
        for (int i = 0; i < N; i ++){
            printf("%d. %s %d\n", a[i].d, a[i].month, a[i].y);
        }
        free(a);
    }
    return 0;
}
