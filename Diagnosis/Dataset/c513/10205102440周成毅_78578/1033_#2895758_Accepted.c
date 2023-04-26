#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct DATE {
    int day;
    int month;
    char Month[8];
    int year;
} date;

int hash(char *s, int len) {
    int sum = 0;
    for (int i = 0; i < len; i++)
        sum = 2 * sum + (s[i] - 'A');
    return sum;
}

int cmp(const void *a, const void *b) {
    date *a1 = (date *) a;
    date *b1 = (date *) b;
    if(a1->year!=b1->year)
        return a1->year-b1->year;
    else if(a1->month!=b1->month)
        return a1->month-b1->month;
    else
        return a1->day-b1->day;
}

int map[4000];

int main() {
    map[327] = 0, map[136] = 1, map[355] = 2, map[799] = 3, map[742] = 4, map[367] = 5;
    map[3261] = 6, map[311] = 7, map[545] = 8, map[343] = 9, map[326] = 10, map[247] = 11;
    map[274] = 12, map[2509] = 13, map[669] = 14, map[307] = 15, map[1361] = 16, map[1266] = 17, map[1435] = 18;
    int T;
    date list[10000];
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int N;
        scanf("%d", &N);
        for (int j = 0; j < N; j++) {
            scanf("%d", &list[j].day);
            scanf("%s", list[j].Month);
            scanf("%s", list[j].Month);
            scanf("%d", &list[j].year);
            int len = strlen(list[j].Month);
            list[j].month = map[hash(list[j].Month, len)];
        }
        qsort(list, N, sizeof(date), cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<N;j++){
            printf("%d. %s %d\n",list[j].day,list[j].Month,list[j].year);
        }
    }
    return 0;
}
