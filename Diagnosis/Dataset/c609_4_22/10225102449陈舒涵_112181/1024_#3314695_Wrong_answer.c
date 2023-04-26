#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char date[11];
    char time[6];
    char size[10];
    char name[200];
} my_FILE;

int namecmp(const void *a1, const void *b1)
{
    my_FILE a = *(my_FILE*)a1;
    my_FILE b = *(my_FILE*)b1;
    return strcmp(a.name, b.name);
}

int sizecmp(const void *a1, const void *b1)
{
    my_FILE a = *(my_FILE*)a1;
    my_FILE b = *(my_FILE*)b1;
    if (strlen(a.size) != strlen(b.size)){
        return strlen(a.size) - strlen(b.size);
    }
    else if (strcmp(a.size, b.size) != 0){
        return strcmp(a.size, b.size);
    }
    else{
        return strcmp(a.name, b.name);
    }
}

int timecmp(const void *a1, const void *b1)
{
    my_FILE a = *(my_FILE*)a1;
    my_FILE b = *(my_FILE*)b1;
    if (strcmp(a.time, b.time) != 0){
        return strcmp(a.time, b.time);
    }
    else {
        return strcmp(a.name, b.name);
    }
}

int main()
{
    int n, T = 0;
    char command[10];
    scanf("%d", &n);
    while (n != 0){
        T ++;
        if (T != 1) printf("\n");
        my_FILE *a = (my_FILE*)malloc(sizeof(my_FILE) * n);
        for (int i = 0; i < n; i ++){
            scanf("%s %s %s %s", a[i].date, a[i].time, a[i].size, a[i].name);
        }
        scanf("%s", command);
        scanf("%s", command);
        if (strcmp(command, "/NAME") == 0){
            qsort(a, n, sizeof(my_FILE), namecmp);
        }
        else if (strcmp(command, "/SIZE") == 0){
            qsort(a, n, sizeof(my_FILE), sizecmp);
        }
        else if (strcmp(command, "/TIME") == 0){
            qsort(a, n, sizeof(my_FILE), timecmp);
        }
        for (int i = 0; i < n; i ++){
            printf("%s %s ", a[i].date, a[i].time);
            for (int j = 0; j < 16 - strlen(a[i].size); j ++) {printf(" ");}
            printf("%s %s\n", a[i].size, a[i].name);
        }
        free(a);
        scanf("%d", &n);
    }
    return 0;
}