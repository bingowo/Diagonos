#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int min;
} Time;

typedef struct {
    Time tm;
    int sz;
    char name[130];
} Info;

int cmp_by_time(const void* p1, const void* p2) {
    Time time_a = (*(Info*)p1).tm, time_b = (*(Info*)p2).tm;
    if (time_a.year == time_b.year) {
        if (time_a.month == time_b.month) {
            if (time_a.day == time_b.day) {
                if (time_a.hour == time_b.hour)
                    return time_a.min - time_b.min;
                return time_a.hour - time_b.hour;
            }
            return time_a.day - time_b.day;
        }
        return time_a.month - time_b.month;
    }
    return time_a.year - time_b.year;
}

int cmp_by_size(const void* p1, const void* p2) {
    return (*(Info*)p1).sz - (*(Info*)p2).sz;
}

int cmp_by_name(const void* p1, const void* p2) {
    return strcmp((*(Info*)p1).name, (*(Info*)p2).name);
}

int main() {
    int n;
    scanf("%d", &n);
    while (n) {
        Info files[100];
        for (int i = 0; i != n; ++i) {
            scanf("%d-%d-%d %d:%d %d %s", &files[i].tm.year, &files[i].tm.month,
                  &files[i].tm.day, &files[i].tm.hour, &files[i].tm.min,
                  &files[i].sz, files[i].name);
        }
        char gab[5], cmd[6];
        scanf("%s%s", gab, cmd);
        if (strcmp(cmd, "/NAME") == 0)
            qsort(files, n, sizeof(files[0]), cmp_by_name);
        else if (strcmp(cmd, "/SIZE") == 0)
            qsort(files, n, sizeof(files[0]), cmp_by_size);
        else if (strcmp(cmd, "/TIME") == 0)
            qsort(files, n, sizeof(files[0]), cmp_by_time);
        for (int i = 0; i != n; ++i)
            printf("%04d-%02d-%02d %02d:%02d %16d %s\n", files[i].tm.year,
                   files[i].tm.month, files[i].tm.day, files[i].tm.hour,
                   files[i].tm.min, files[i].sz, files[i].name);
        scanf("%d", &n);
    }
    return 0;
}