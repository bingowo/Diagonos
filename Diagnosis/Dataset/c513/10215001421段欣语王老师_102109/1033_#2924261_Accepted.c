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

int month2idx(char*m)
{
    int i;
    static char* month[]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
    for(int i=0;;i++)if(!strcmp(m,month[i]))return i;
}

int cmp(const void*a,const void*b)
{
    return ((RECORD*)a)->val-((RECORD*)b)->val;
}

int main()
{
    int T,N;
    scanf("%d",&T);
    for(int k=0;k<T;k++)
    {
        printf("case #%d:\n",k);
        scanf("%d",&N);
        RECORD a[10000];
        for(int i=0;i<N;i++)
        {
            scanf("%d. %s %d\n",&a[i].d,a[i].m,&a[i].y);
            a[i].val=a[i].y*1000+month2idx(a[i].m)*20+a[i].d;
        }
        qsort(a,N,sizeof(RECORD),cmp);
        for(int i=0;i<N;i++)printf("%d. %s %d\n",a[i].d,a[i].m,a[i].y);
    }
    return 0;
}