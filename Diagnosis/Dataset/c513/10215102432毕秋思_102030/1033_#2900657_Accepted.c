#include<stdio.h>

typedef struct{
    int val;
    int y;
    int d;
    char m[7];
}RECORD;

int month2idx(char*m)
{
    int i;
    static char*month[]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
    for(i=0;;i++)
    {
        if(!strcmp(m,month[i])) return i;
    }
}

int cmp(const void*a,const void*b)
{
    return((RECORD*)a)->val-((RECORD*)b)->val;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N=0;
        scanf("%d",&N);
        RECORD a[10000];
        for(int j=0;j<N;j++)
        {
            scanf("%d. %s %d\n",&a[j].d,&a[j].m,&a[j].y);
            a[j].val=a[j].y*1000+month2idx(a[j].m)*20+a[j].d;
        }
        qsort(a,N,sizeof(RECORD),cmp);
        printf("case #%d:\n",i);
        for(int k=0;k<N;k++)
            printf("%d. %s %d\n",a[k].d,a[k].m,a[k].y);
    }
    return 0;
}
