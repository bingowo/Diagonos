#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const char *table[19] = {"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};

int getMonth(char month[]){
    for (int i = 0; i < 19; i++){
        if (strcmp(month, table[i]) == 0){
            return i;
        }
    }
    return -1;
}

typedef struct time{
    int day, month, year;
}time;

int cmp(const void* a, const void* b){
    time* x = (time*)a;
    time* y = (time*)b;
    if (x->year != y->year) return x->year - y->year;
    else if (x->month != y->month) return x->month - y->month;
    else return x->day - y->day;
}

int main(){
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++){
        int n;
        scanf("%d", &n);
        time tarr[n];
        for (int i = 0; i < n; i++){
            time t0;
            char tempmonth[10];
            scanf("%d. ", &t0.day);
            scanf("%s ", &tempmonth);
            t0.month = getMonth(tempmonth);
            scanf("%d", &t0.year);  
            tarr[i] = t0;          
        }
        qsort(tarr, n, sizeof(time), cmp);
        printf("case #%d:\n", t);
        for (int i = 0; i < n; i++) printf("%d. %s %d\n", tarr[i].day, table[tarr[i].month], tarr[i].year);
    }
    return 0;
}