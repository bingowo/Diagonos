#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char month[][21]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu"};
typedef struct
{
    int day,year;
    char month[20];
}date;
int cmp(const void* a,const void* b)
{
    int i,j;
    date c=*(date*)a,d=*(date*)b;
    if(c.year!=d.year) return c.year-d.year;
    for(i=0;i<20;i++)
    {
        if(strcmp(c.month,month[i])==0)
            break;
    }
    for(j=0;j<20;j++)
    {
        if(strcmp(d.month,month[j])==0)
            break;
    }
    if(i!=j) return i-j;
    return c.day-d.day;
}
int main()
{
    int N,T,i;
    date* da;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        int day=0,year=0;
        char month[20]={0};
        scanf("%d\n",&N);
        da=(date*)malloc(sizeof(date)*N);
        for(int j=0;j<N;j++)
        {
            scanf("%d.",&day);
            scanf("%s",month);
            scanf("%d",&year);
            da[j].day=day;
            da[j].year=year;
            strcpy(da[j].month,month);
        }
        qsort(da,N,sizeof(da[0]),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<N;j++)
            printf("%d. %s %d\n",da[j].day,da[j].month,da[j].year);
        free(da);
    }
    return 0;
}
