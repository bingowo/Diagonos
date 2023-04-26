#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct{
    int val;
    int year;
    int day;
    char month[7];
}Maya;

Maya a[10001];

int montrans(char*mon)
{
    static char*month[]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
    for(int i=0;i<19;++i)
    {
        if(!strcmp(mon,month[i]))
            return i;
    }
    return 0;
}

int cmp(const void*a,const void*b)
{
    Maya*a1=(Maya*)a;
    Maya*b1=(Maya*)b;
    a1->val=(a1->year)*400+montrans((a1->month))*20+(a1->day);
    b1->val=(b1->year)*400+montrans((b1->month))*20+(b1->day);
    return (a1->val)>(b1->val);
}
int main()
{
    int T;
    scanf("%d",&T);
    int i,N;
    for(i=0;i<T;++i)
    {
        scanf("%d",&N);
        for(int j=0;j<N;++j)
        {
            scanf("%d.%s%d",&a[j].day,a[j].month,&a[j].year);
            a[j].val=a[j].year*1000+montrans(a[j].month)+a[j].day;
        }
        qsort(a,N,sizeof(Maya),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<N;++j)
        {
            printf("%d. %s %d\n",a[j].day,a[j].month,a[j].year);
        }
    }
    return 0;
}
