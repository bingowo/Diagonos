#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int year;
    int val;
    int day;
    char month[7];
}record;

int cmp(const void* a,const void* b)
{
    return ((record*)a)->val-((record*)b)->val;
}

int month1(char *month)
{
    char *month2[19]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};//刚开始写成了month2[7]，所以7以后的一直无法读取
    int i;
    for(i=0;i<19;i++)
    {
        if(strcmp(month,month2[i])==0)
        {
            return i;
        }
    }
}

int main()
{
    int T,i,N,j;
    scanf("%d",&T);
    record a[10001];
    for(i=0;i<T;i++)
    {
        scanf("%d",&N);
        for(j=0;j<N;j++)
        {
            scanf("%d. %s %d",&a[j].day,&a[j].month,&a[j].year);
            a[j].val=1000*a[j].year+20*month1(a[j].month)+a[j].day;
        }
        qsort(a,N,sizeof(record),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<N;j++)
        {
            printf("%d. %s %d\n",a[j].day,a[j].month,a[j].year);
        }
    }
    return 0;
}
