#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int year;
    char month[7];
    int day;
    int monum;
}date;

int cmp(const void* a, const void* b)
{
    date m = *(date*)a, n = *(date*)b;
    if(m.year != n.year)
        return m.year-n.year;
    else
    {
        if(m.monum != n.monum)
            return m.monum-n.monum;
        else
        {
            if(m.day != n.day)
                return m.day-n.day;
            if(m.day == n.day)
                return 0;
        }
    }
}

int main()
{
    int T, N, i, j, t;
    scanf("%d", &T);
    for(i=0; i<T; i++)
    {
        scanf("%d", &N);
        date cal[N];
        char mon[19][7] = {"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
        for(j=0; j<N; j++)
        {
            scanf("%d", &cal[j].day);
            char c = getchar();
            scanf("%s", &cal[j].month);
            scanf("%d", &cal[j].year);
            /*printf("day=%d\n", cal[j].day);
            printf("month=%s\n", cal[j].month);
            printf("year=%d\n", cal[j].year);*/
            for(t=0; t<19; t++)
            {
                if(strcmp(cal[j].month,mon[t])==0)
                {
                    cal[j].monum = t;
                    break;
                }
            }
            //printf("monum=%d\n", cal[j].monum);
        }

        qsort(cal,N,sizeof(cal[0]),cmp);

        printf("case #%d:\n", i);
        for(j=0; j<N; j++)
            printf("%d. %s %d\n", cal[j].day, cal[j].month, cal[j].year);
    }

    return 0;
}
