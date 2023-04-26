#include <stdio.h>
#include <string.h>
#include<stdlib.h>

char Month[19][10] ={"pop","no","zip","zotz","tzec","xul",
        "yoxkin","mol", "chen", "yax","zac",
         "ceh","mac","kankin","muan","pax",
        "koyab","cumhu","uayet"};

typedef struct Maya{
    int day;
    char month[10];
    int year;
}maya;
int cmp(const void *a,const void *b)
{
    int month_a,month_b;
    maya A = *(maya *)a;
    maya B = *(maya *)b;
    if(A.year != B.year){
        return A.year - B.year;
    }else if(A.month != B.month){
        for(int i=0;i<19;i++){
            if(A.month==Month[i]) month_a=i;
            if(B.month==Month[i]) month_b=i;
        }
        return month_a-month_b;
    }else{
        return A.day-B.day;
    }
}
int main( )
{
    int T,N,i,j;
    char c[11];
    scanf("%d",&T);
    for(i = 0;i<T;i++){
        scanf("%d",&N);
        maya calender[N];
        for(j = 0;j<N;j++)
        {
            scanf("%d. ",&calender[j].day);
            scanf("%s ",c);
            strcpy(calender[j].month,c);
            scanf("%d\n",&calender[j].year);
        }
        qsort(calender,N,sizeof(calender[0]),cmp);
        printf("case #%d:\n",i);
        for(j = 0;j<N;j++){
            printf("%d. ",calender[j].day);
            printf("%s ",calender[j].month);
            printf("%d\n",calender[j].year);
        }
    }
    return 0;
}
