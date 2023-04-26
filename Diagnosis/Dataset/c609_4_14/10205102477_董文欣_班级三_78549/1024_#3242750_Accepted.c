#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct data {
    char day[11];
    char time[6];
    int size;
    unsigned char name[64];
}info[101];

int cmp_name(const void *a, const void *b) {
    struct data *aa = (struct data *)a;
    struct data *bb = (struct data *)b;
    return (strcmp(aa->name, bb->name));
}

int cmp_size(const void *a, const void *b) {
    struct data *aa = (struct data *)a;
    struct data *bb = (struct data *)b;
    if (aa->size != bb->size) return ((aa->size) > (bb->size) ? 1 : -1);
    else return (strcmp(aa->name, bb->name));
}

int cmp_time(const void *a, const void *b) {
    struct data *aa = (struct data *)a;
    struct data *bb = (struct data *)b;
    if (strcmp(aa->day, bb->day) != 0) {
        return strcmp(aa->day, bb->day);
    }
    else if (strcmp(aa->time, bb->time) != 0) return strcmp(aa->time, bb->time);
    else return (strcmp(aa->name, bb->name));
}

int main()
{
    int n;
    while (scanf("%d",&n) != EOF && n != 0) {
        for (int i = 0; i < n; i++) {
            scanf("%s %s %d %s\n",info[i].day, info[i].time, &info[i].size, info[i].name);
        }
        char rule[11];
        gets(rule);


        if (strstr(rule, "LIST /NAME") != NULL) qsort(info, n, sizeof(info[0]), cmp_name);
        else if (strstr(rule, "LIST /SIZE") != NULL) qsort(info, n, sizeof(info[0]), cmp_size);
        else if (strstr(rule, "LIST /TIME") != NULL) qsort(info, n, sizeof(info[0]), cmp_time);

        for (int i = 0; i < n; i++) {
            printf("%s %s %16d %s\n",info[i].day, info[i].time, info[i].size, info[i].name);
        }
        printf("\n");
    }
    return 0;
}
