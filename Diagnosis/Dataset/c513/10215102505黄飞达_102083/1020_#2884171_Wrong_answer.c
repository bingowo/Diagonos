#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct file{
    int year, month, day, hour, min, size;
    char name[200];
}F;

int cmp1(const void* a, const void* b){
    F* x = (F*)a;
    F* y = (F*)b;
    return strcmp(x->name, y->name);
}

int cmp2(const void* a, const void* b){
    F* x = (F*)a;
    F* y = (F*)b;
    if (x->size != y->size) return x->size - y->size;
    else return strcmp(x->name, y->name);
}

int cmp3(const void* a, const void* b){
    F* x = (F*)a;
    F* y = (F*)b;
    if (x->year != y->year) return x->year - y->year;
    else if (x->month != y->month) return x->month - y->month;
    else if (x->day != y->day) return x->day - y->day;
    else if (x->hour != y->hour) return x->hour - y->hour;
    else if (x->min != y->min) return x->min - y->min;
    else return strcmp(x->name, y->name);
}


int main(){
    int n = 0;
    while(scanf("%d", &n)){
        if (n == 0) break;
        F f[102] = {0};
        for (int i = 0; i < n; i++){
            f[i].day=0;f[i].hour=0;f[i].min=0;f[i].month=0;f[i].size=0;f[i].year=0;memset(f[i].name, '\0', 200);
        }
        char list[12] = {0};
        for (int i = 0; i < n; i++){
            scanf("%d-%d-%d %d:%d %d ", &f[i].year, &f[i].month, &f[i].day, &f[i].hour, &f[i].min, &f[i].size);
            scanf("%s ", &f[i].name);
        } 
        gets(list);
        if (strcmp(list, "LIST /NAME") == 0) qsort(f, n, sizeof(F), cmp1);
        else if (strcmp(list, "LIST /SIZE") == 0) qsort(f, n, sizeof(F), cmp2);
        else if (strcmp(list, "LIST /TIME") == 0) qsort(f, n, sizeof(F), cmp3);
        for (int i = 0; i < n; i++){
            printf("%d-%02d-%02d %02d:%02d %16d ", f[i].year, f[i].month, f[i].day, f[i].hour, f[i].min, f[i].size);
            printf("%s\n", f[i].name);
        }
        printf("\n");
    }
    return 0;
}
