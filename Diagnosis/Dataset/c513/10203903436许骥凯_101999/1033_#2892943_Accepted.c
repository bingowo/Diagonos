#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int year;
    int day;
    char month[10];
}Maya;

int convert(char *p){
    char *month[19] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin","mol", "chen", "yax",
                       "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
    int index = 0;
    for (; index != 19; index++)
        if (strcmp(p, month[index]) == 0) return index + 1;
    return -1;
}

int compare(const void *p1, const void *p2){
    Maya time1 = *(Maya*)p1, time2 = *(Maya*)p2;
    if (time1.year == time2.year){
        if (convert(time1.month) == convert(time2.month))
            return time1.day - time2.day;
        return convert(time1.month) - convert(time2.month);
    }
    return time1.year -  time2.year;
}
int main(){
    int pro;
    scanf("%d", &pro);
    for (int i = 0; i != pro; i++){
        int n;
        scanf("%d", &n);
        Maya* maya = (Maya*)malloc(sizeof(Maya)*n);
        for (int j = 0; j != n; j++)
            scanf("%d.%s%d", &maya[j].day, maya[j].month, &maya[j].year);
        qsort(maya, n, sizeof(maya[0]), compare);
        
        printf("case #%d:\n", i);
        for (int j = 0; j != n; j++)
            printf("%d. %s %d\n", maya[j].day, maya[j].month, maya[j].year);
        free(maya);  
    }
    return 0;
}