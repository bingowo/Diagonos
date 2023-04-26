#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define HASHSIZE 190
int table[HASHSIZE];

int hash(char *s){
    unsigned int res;
    for (res = 0; *s; ++s)
        res = *s + res * 32;
    return res % HASHSIZE;
}

void init(){
    char s[][10] = {"pop", "no", "zip", "zotz", "tzec",
                  "xul", "yoxkin", "mol", "chen", "yax",
                  "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
    for (int i = 0; i != 19; ++i)
        table[hash(s[i])] = i;
}

typedef struct{
    int day;
    char mon[10];
    int mon_int;
    int year;
}Maya;

int cmp(const void *p1, const void *p2){
    Maya maya_1 = *(Maya*)p1, maya_2 = *(Maya*)p2;
    if (maya_1.year == maya_2.year){
        if (maya_1.mon_int == maya_2.mon_int)
            return maya_1.day - maya_2.day;
        return maya_1.mon_int - maya_2.mon_int;
    }
    return maya_1.year - maya_2.year;
}

int main(){
    init();
    int T; scanf("%d", &T);
    for (int i = 0; i != T; ++i){
        Maya arr_Maya[10000];
        int N; scanf("%d", &N);
        for (int j = 0; j != N; ++j){
            scanf("%d.%s%d", &arr_Maya[j].day, arr_Maya[j].mon, &arr_Maya[j].year);
            arr_Maya[j].mon_int = table[hash(arr_Maya[j].mon)];
        }
        qsort(arr_Maya, N, sizeof(Maya), cmp);
        printf("case #%d:\n", i);
        for (int j = 0; j != N; ++j)
            printf("%d. %s %d\n", arr_Maya[j].day, arr_Maya[j].mon, arr_Maya[j].year);
    }
    return 0;
}