#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{int val;int y;int d;char month[7];} RECORD;

//将玛雅历的月份转为数字
int month2idx(char*m)
{
    int i;
    static char*month[]=
    {"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen",
    "y ax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
    for(i=0;i<19;i++)
    {
        if(!strcmp(m,month[i]))return i;
    }
}

int cmp(const void*a,const void*b)
{
    return ((RECORD*)a)->val-((RECORD*)b)->val;
}
int main()
{
    int T;
    scanf("%d",&T); //共T个问题
    for(int i=0;i<T;i++)
    {
        int N;

        scanf("%d",&N);//第T个问题中有N个日期
        RECORD a[N];
        for(int j=0;j<N;j++)
        {
            scanf("%d. %s %d",&a[j].d,a[j].month,&a[j].y);
            a[j].val=a[j].d+month2idx(a[j].month)*20+a[j].y*1000;
        }
        qsort(a,N,sizeof(RECORD),cmp);


        printf("case #%d:\n",i);
        for(int k=0;k<N;k++)
            printf("%d. %s %d\n",a[k].d,a[k].month,a[k].y);
    }

    return 0;
}