#include <stdio.h>
#include <string.h>
#include <stdlib.h>



typedef  struct dat{
    int day;
    char month[8];
    int monthint;
    int year;
} calendar;


char hei[19][8] = {"pop","no","zip","zotz","tzec","xul",
                   "yoxkin","mol","chen","yax","zac",
                   "ceh","mac","kankin","muan","pax",
                   "cumhu","koyab","uayet"};


int qcmp(const void * q1, const void *q2)
{
    struct dat * p1 = (struct dat *) q1;
    struct dat * p2 = (struct dat *) q2;
    if(p1 ->year == p2 ->year){
        if(p1 -> monthint == p2 -> monthint){
            return p1 -> day - p2 -> day;
        }
        return p1 -> monthint - p2 -> monthint;
    }
    return p1 ->year - p2 ->year;
}


int main() {
    int loop;
    scanf("%d",&loop);
    getchar();
    for (int i = 0; i < loop; ++i) {
        int deepl;
        scanf("%d",&deepl);
        getchar();
        calendar date[deepl];
        for (int j = 0; j < deepl; ++j) {
            char less;
            scanf("%d%c",&date[j].day,&less);
            scanf("%s",date[j].month);
            for (int k = 0; k < 19; ++k) {
                if(strcmp(hei[k],date[j].month) == 0)
                    date[j].monthint = k;
            }scanf("%d",&date[j].year);
            getchar();
        }
        qsort(date,deepl,sizeof(calendar),qcmp);
        printf("case #%d:\n",i);
        for (int h = 0; h < deepl; ++h) {
            printf("%d. %s %d\n",date[h].day,date[h].month,date[h].year);
        }

    }

}
