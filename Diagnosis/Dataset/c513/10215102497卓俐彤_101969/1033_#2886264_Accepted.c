#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct date{
    int year;
    int month;
    int day;
    char mon[7];
};

int compar(const void*a,const void*b){
    struct date d1,d2;
    d1=*((struct date*)a);
    d2=*((struct date*)b);
    if(d1.year==d2.year){
        if(d1.month==d2.month)return d1.day-d2.day;
        else return d1.month-d2.month;
    }
    else return d1.year-d2.year;
}

static char* months[]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
int main(){
    int T,N;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        scanf("%d",&N);
        struct date dates[N];
        for(int n=0;n<N;n++){
            int x1,x2;
            scanf("%d",&x1);
            char s[2];
            scanf("%s %s",s,dates[n].mon);
            scanf("%d",&x2);
            dates[n].day=x1;
            dates[n].year=x2;
            int m=0;
            for(;;m++)if(!strcmp(dates[n].mon,months[m])){
                dates[n].month=m;
                break;
            }
        }
        qsort(dates,N,sizeof(dates[0]),compar);
        printf("case #%d:\n",t);
        for(int i=0;i<N;i++){
            printf("%d. %s %d\n",dates[i].day,dates[i].mon,dates[i].year);
        }
    }
    return 0;
}
