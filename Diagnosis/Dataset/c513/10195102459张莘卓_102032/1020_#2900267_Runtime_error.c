#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char t[5];
typedef struct{
    char day[11];
    char time[6];
    int size;
    char name[200];
} F;

int cmp(const void* m, const void* n){
    F *a = (F*)m, *b = (F*)n;
    if(strcmp(t, "SIZE") == 0){
        if(a->size != b->size)
            return a->size - b->size;
    }else if(strcmp(t, "TIME") == 0) {
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
        F a[100];
        for(int i=0; i<n; ++i) {
            scanf("%s %s",a[i].day,a[i].time);
            //scanf("%s",a[i].time);
            scanf("%d",&(a[i].size));
            scanf("%s",a[i].name);
            if(i==n-1) scanf("LIST /%s",t);
        }
        qsort(a, n, sizeof(F), cmp);
        for(int i=0; i<n; ++i) {
            printf("%s %s %16d %s\n",a[i].day,a[i].time,a[i].size,a[i].name);
        }
        scanf("%d",&n);
        //free(a);
    }
    return 0;
}
/*
5
2011-01-26 07:32              388 ScoreStat.c
2011-01-26 19:48              429 ScoreStat.cpp
2011-01-25 20:11            22016 成绩统计.doc
2011-01-26 19:48           307200 ScoreStat++.exe
2011-01-25 20:08           270336 ScoreStat.exe
 LIST /NAME
 0
 
*/
