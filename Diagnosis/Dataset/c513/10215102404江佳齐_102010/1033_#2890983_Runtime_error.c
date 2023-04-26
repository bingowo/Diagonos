#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int val;
    int y;
    int d;
    char m[7];
}RECORD;

int cmp(const void*a,const void*b)
{
    return ((RECORD*)a)->val-((RECORD*)b)->val;
}

int month2num(char* m)
{
    int i;//1-19月份数组
    static char* month[]={"pop","no","zip","zotz","tzec","xul","yoxkin",\
     "mol","chen","yax","zac","ceh","mac","kankin","muan","pax",\
     "koyab","cumhu","uayet"};
     for(i=0;;i++)if(!strcmp(m,month[i])) return i;
}

int main()
{
    int T,n;
    RECORD a[1000];
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N;
        scanf("%d",&N);
        for(n=0;n<N;n++)
        {
            scanf("%d.%s %d\n",&a[n].d,a[n].m,a[n].y);
            a[n].val=a[n].y*1000+month2num(a[n].m)*20+a[n].d;
        }
        qsort(a,N,sizeof(RECORD),cmp);
        for(n=0;n<N;n++)
        {
            printf("%d.%s %d\n",a[n].d,a[n].m,a[n].y);
        }
    }
    return 0;
}
