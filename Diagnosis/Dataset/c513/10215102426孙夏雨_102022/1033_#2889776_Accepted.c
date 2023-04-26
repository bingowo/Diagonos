#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int day;
    int month;
    char m[10];
    int year;
} DATE;

int cmp(const void* p3,const void* p4)
{
    DATE* p1=(DATE* )p3;
    DATE* p2=(DATE* )p4;
    if((p1->year)<(p2->year)) return -1;
    else if((p1->year)>(p2->year)) return 1;
    else{
        if((p1->month)<(p2->month)) return -1;
        else if((p1->month)>(p2->month)) return 1;
        else{
            if((p1->day)<(p2->day)) return -1;
            else return 1;
        }
    }
}

int main()
{
    char* months[19]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
    int T=0;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int line=0;
        scanf("%d",&line);
        DATE* p=(DATE* )malloc(line*sizeof(DATE));
        char sday[4],smonth[10];
        for(int i=0;i<line;i++){
            scanf("%s",sday);
            char sday1[3];
            for(int ii=0;ii<(strlen(sday)-1);ii++) sday1[ii]=sday[ii];
            sday1[strlen(sday)-1]=0;
            int day1=atoi(sday1);
            (p+i)->day=day1;
            scanf("%s",smonth);
            strcpy((p+i)->m,smonth);
            int month1=0;
            for(;month1<19;month1++){
                if(!strcmp(smonth,*(months+month1))) (p+i)->month=month1;
            }
            int year1=0;
            scanf("%d",&year1);
            (p+i)->year=year1;
        }
        qsort(p,line,sizeof(DATE),cmp);
        printf("case #%d:\n",t);
        for(int j=0;j<line;j++) printf("%d. %s %d\n",(p+j)->day,(p+j)->m,(p+j)->year);
        free(p);
    }
    return 0;
}
