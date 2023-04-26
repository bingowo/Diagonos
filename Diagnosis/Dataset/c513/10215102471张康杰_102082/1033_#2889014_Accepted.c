#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int day;
    char month[10];
    int year;
}DATE;
int Search(char*s)
{
    int i;
    char*table[19]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
    for(i = 0;i < 19;i++)
    {
        if(strcmp(s,table[i]) == 0)
            return i;
    }
}
int cmp(const void*a,const void*b)
{
    //enum month{pop, no, zip, zotz, tzec, xul, yoxkin, mol, chen, yax, zac, ceh, mac, kankin, muan, pax, koyab, cumhu}Mon;
    DATE*st1,*st2;
    st1 = (DATE*)a,st2 = (DATE*)b;
    if(st1->year != st2->year)
        return st1->year - st2->year;
    else
    {
        if(Search(st1->month) != Search(st2->month))
            return Search(st1->month) - Search(st2->month);
        else
            return st1->day - st2->day;
    }


}
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        int N;
        scanf("%d",&N);
        DATE date[N];
        for(int j = 0;j < N;j++)
        {
            scanf("%d. %s %d",&date[j].day,date[j].month,&date[j].year);
        }
        qsort(date,N,sizeof(date[0]),cmp);
        printf("case #%d:\n",i);
        for(int j = 0;j < N;j++)
        {
            printf("%d. %s %d\n",date[j].day,date[j].month,date[j].year);
        }

    }
    return 0;
}
