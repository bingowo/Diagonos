#include <stdio.h>
#include <string.h>

const char *month[] =
        {
                "pop","no","zip", "zotz", "tzec", "xul",
                "yoxkin", "mol", "chen", "yax", "zac",
                "ceh", "mac", "kankin", "muan", "pax",
                "koyab", "cumhu","uayet"
        };

typedef struct {
    int y;
    char m[10];
    int d;
    int m_num;
} date;

void init(date *d) {
    for (int i = 0; i < 19; i++) {
        if (strcmp(d->m, month[i]) == 0) {
            d->m_num = i;
            return;
        }
    }
}

int cmp(const void *a, const void *b) {
    date *da = (date *)a;
    date *db = (date *)b;
    if (da->y == db->y) {
        if (da->m_num == db->m_num) {
            return da->d - db->d;
        }
        return da->m_num - db->m_num;
    }
    return da->y - db->y;
}

int main() {
    int total;
    scanf("%d", &total);
    for (int i = 0; i < total; i++) {
        int alld;
        scanf("%d", &alld);
        date *D = (date *)malloc(sizeof(date) * alld);

        for (int j = 0; j < alld; j++) {
            scanf("%d", &D[j].d);
            getchar();
            scanf("%s", D[j].m);
            scanf("%d", &D[j].y);
            init(&D[j]);
        }

        qsort(D, alld, sizeof(date), cmp);
        printf("case #%d:\n", i);
        for (int j = 0; j < alld; j++) {
            printf("%d. %s %d\n", D[j].d, D[j].m, D[j].y);
        }
        free(D);
    }
    return 0;
}
