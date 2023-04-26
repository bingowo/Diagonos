#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char month[19][10]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
struct time
{
    int day;
    char m[10];
    int year;
};
int cmp(const void *a,const void *b)
{
    int c1,c2;
    struct time t1,t2;
    t1=*((struct time *)a);
    t2=*((struct time *)b);
    if(t1.year!=t2.year) return t1.year-t2.year;
    else
    {
        for(c1=0;c1<19;c1++)
            if(strcmp(month[c1],t1.m)==0) break;
        for(c2=0;c2<19;c2++)
            if(strcmp(month[c2],t2.m)==0) break;
        if(c1!=c2) return c1-c2;
        else return t1.day-t2.day;
    }
}
int main()
{
    int T,N;
    struct time t[10000];
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        scanf("%d",&N);
        for(int j=0;j<N;j++)
        {
            scanf("%d. %s %d",&t[j].day,t[j].m,&t[j].year);
        }
        qsort(t,N,sizeof(t[0]),cmp);
        printf("case #%d:\n",cas);
        for(int k=0;k<N;k++)
        {
            printf("%d. %s %d\n",t[k].day,t[k].m,t[k].year);
        }
    }
    return 0;
}
