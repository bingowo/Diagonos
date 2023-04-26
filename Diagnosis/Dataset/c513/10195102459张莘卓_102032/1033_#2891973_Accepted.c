#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char month[19][8]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};

typedef struct{
    int year;
    int cnt;
}M;

int cmp(const void* m, const void* n) {
    M *a = (M*)m, *b = (M*)n;
    if(a->year != b->year)
        return a->year - b->year;
    else return a->cnt - b->cnt;
}

int main()
{
    int T;  scanf("%d",&T);
    for(int j=0; j<T; ++j) {
        int N; scanf("%d",&N);
        M a[10000];
        for(int i=0; i<N; ++i) {
            int d;  char m[8];
            scanf("%d. %s %d",&d,m,&a[i].year);
            int k = 0;
            while(strcmp(month[k], m)) ++k;
            a[i].cnt = d + k * 20;
        }
        qsort(a, N, sizeof(M), cmp);
        printf("case #%d:\n",j);
        for(int i=0; i<N; ++i)
            printf("%d. %s %d\n",a[i].cnt%20,month[a[i].cnt/20],a[i].year);
    }
    return 0;
}
