#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 义时间结体
typedef struct
{
    int year;
    int month;
    int day;
    int hours;
    int mins;
} Time;
// 义件结体
typedef struct
{
    Time time;
    unsigned long long size;
    char name[200];
} FileInfo;
// 照件较两件的⼤⼩
int cmp_name(const void* a, const void* b)
{
    FileInfo f_a = *(FileInfo*)a, f_b = *(FileInfo*)b;
    return strcmp(f_a.name, f_b.name);
}
// 照件⼤⼩较两件的⼤⼩
int cmp_size(const void* a, const void* b)
{
    FileInfo f_a = *(FileInfo*)a, f_b = *(FileInfo*)b;
    if (f_a.size > f_b.size) return 1;
    else if (f_a.size == f_b.size) return cmp_name(a, b); // 果
件⼤⼩相等，则照件
    else return -1;
}
// 照时间较两件的⼤⼩
int cmp_time(const void* a, const void* b)
{
    FileInfo f_a = *(FileInfo*)a, f_b = *(FileInfo*)b;
    Time ta = f_a.time, tb = f_b.time;
    int res = 0;
    if (ta.year == tb.year) {
        if (ta.month == tb.month) {
            if (ta.day == tb.day) {
                if (ta.hours == tb.hours) {
                    if (ta.mins == tb.mins) {
                        res = cmp_name(a, b); 
                   }
                    else res = ta.mins - tb.mins;
               }
                else res = ta.hours - tb.hours;
           }
            else res = ta.day - tb.day;
       }
        else res = ta.month - tb.month;
   }
    else res = ta.year - tb.year;
    return res;
}
int main()
{
    int n = 0;
    FileInfo* infos = NULL;
    char choice[20] = {0};
    do {
        scanf("%d", &n);
        if (n != 0) {
            infos = (FileInfo*)malloc(n * sizeof(FileInfo));
            for (int i = 0; i < n; i++) {
                scanf("%d-%d-%d %d:%d%llu",
                      &infos[i].time.year, &infos[i].time.month,
&infos[i].time.day,
                      &infos[i].time.hours, &infos[i].time.mins,
&infos[i].size);
                scanf("%s", infos[i].name);
           }
            scanf("%s", choice);
            scanf("%s", choice);
            int (*fp)(const void*, const void*);
            // 据⽤户的选择设指针
            if (strcmp(choice, "/NAME") == 0) {
                fp = cmp_name;
           }
            else if (strcmp(choice, "/SIZE") == 0) {
                fp = cmp_size;
           }
            else {
                fp = cmp_time;
           }
            qsort(infos, n, sizeof(FileInfo), fp); 
            for (int i = 0; i < n; i++) {
                printf("%d-%02d-%02d %02d:%02d%17llu %s\n",
                       infos[i].time.year, infos[i].time.month,
infos[i].time.day,
                      infos[i].time.hours, infos[i].time.mins,
infos[i].size,
                      infos[i].name);
           }
                      printf("\n");
            free(infos); // 释内
            infos = NULL;
       }
   } while (n != 0);
    return 0;
}