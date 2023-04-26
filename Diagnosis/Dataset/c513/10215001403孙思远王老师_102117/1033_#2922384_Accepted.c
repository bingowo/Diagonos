#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char mo[19][10]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
struct maya
{
    int day;
    char month[10];
    int year;
};
int cmp(const void *a,const void *b)
{
    struct maya *p1,*p2;
    p1=(struct maya *)a;
    p2=(struct maya *)b;
    int i,m1,m2;
    for(i=0;i<19;i++)
    {
        if(strcmp(p1->month,mo[i])==0)
        {
            m1=i;
            break;
        }
    }
    for(i=0;i<19;i++)
    {
        if(strcmp(p2->month,mo[i])==0)
        {
            m2=i;
            break;
        }
    }
    if(p1->year!=p2->year)
        return p1->year-p2->year;
    else if(m1!=m2)
        return m1-m2;
    else
        return p1->day-p2->day;
}

int main()
{
    int t,T;
    scanf("%d\n",&T);
    for(t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        int n,i;
        scanf("%d",&n);
        struct maya t[n];
        for(i=0;i<n;i++)
        {
            scanf("%d",&t[i].day);
            getchar();
            getchar();
            scanf("%s",t[i].month);
            scanf("%d",&t[i].year);
        }
        qsort(t,n,sizeof(t[0]),cmp);
        for(i=0;i<n;i++)
        {
            printf("%d. %s %d\n",t[i].day,t[i].month,t[i].year);
        }
    }
    return 0;
}
