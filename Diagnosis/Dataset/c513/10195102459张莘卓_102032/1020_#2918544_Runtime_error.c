#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char t[12];
typedef struct{
    char day[11];
    char time[6];
    int size;
    char name[200];
} F;

int cmp(const void* m, const void* n){
    F *a = (F*)m, *b = (F*)n;
    if(strcmp(t, "LIST /SIZE") == 0){
        if(a->size != b->size)
            return a->size - b->size;
    }else if(strcmp(t, "LIST /TIME") == 0) {
        if(a->day != b->day)
            return strcmp(a->day, b->day);
        else if(a->time != b->time)
            return strcmp(a->time, b->time);
    }
    return strcmp(a->name, b->name);
}


int main()
{
    int n;
    scanf("%d",&n);
    while(n) {
        if(n == 0) break;
        F a[100];
        for(int i=0; i<n; ++i) {
            scanf("%s%s%d%s",a[i].day,a[i].time,&a[i].size,a[i].name);
        }
        getchar();  gets(t);
        qsort(a, n, sizeof(F), cmp);
        for(int i=0; i<n; ++i) {
            printf("%s %s %16d %s\n",a[i].day,a[i].time,a[i].size,a[i].name);
        }
        scanf("%d",&n);
    }
    return 0;
}
