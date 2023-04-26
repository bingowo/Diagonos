#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int mo[1785]={0};

typedef struct{
    int year;
    char month[7];
    int nummon;
    int day;
}DATE;


int cmp(const void *a, const void *b){
    DATE *da=(DATE*)a, *db=(DATE*)b;
    if(da->year != db->year) return (da->year - db->year);
    if(da->nummon != db->nummon) return (da->nummon - db->nummon);
    return(da->day - db->day);
}


int main()
{
    mo['p'+'o'+'p'] = 0;  mo['n'+'o'] = 1;   mo['z'+'i'+'p'] = 2;  mo['z'+'o'+'t'+'z'] = 3; mo['t'+'z'+'e'+'c'] = 4;
    mo['x'+'u'+'l'] = 5;  mo['y'+'o'+'x'+'k'+'i'+'n'] = 6;   mo['m'+'o'+'l'] = 7;  mo['c'+'h'+'e'+'n'] = 8; mo['y'+'a'+'x'] = 9;
    mo['z'+'a'+'c'] = 10; mo['c'+'e'+'h'] = 11; mo['m'+'a'+'c'] = 12; mo['k'+'a'+'n'+'k'+'i'+'n'] = 13;  mo['m'+'u'+'a'+'n'] = 14;
    mo['p'+'a'+'x'] = 15; mo['k'+'o'+'y'+'a'+'b'] = 16;   mo['c'+'u'+'m'+'h'+'u'] = 17;   mo['u'+'a'+'y'+'e'+'t'] = 18;

    int R,T;
    scanf("%d",&T);
    for(R = 0; R < T; R++){
        int N;
        scanf("%d",&N);

        DATE *date=(DATE*)malloc(N*sizeof(DATE));
        for(int k = 0; k < N; k++){
            scanf("%d.",&date[k].day);
            scanf("%s",date[k].month);
            scanf("%d",&date[k].year);

            char *p = date[k].month;
            int temp = 0;
            while(*p) {
                temp += *p;
                p++;
            }

            date[k].nummon = mo[temp];
        }

        qsort(date,N,sizeof(DATE),cmp);

        printf("case #%d:\n",R);
        for(int k = 0; k < N; k++){
            printf("%d. %s %d\n",date[k].day,date[k].month,date[k].year);
        }

    }
    return 0;
}
