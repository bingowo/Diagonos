#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct{
    int val;
    int year;
    int day;
    char mon[7];
}RECORD;

RECORD a[10001];

int monthtrans(char *m)
{
    static char *month[]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
    for(int i=0;;i++)
        if(!strcmp(m,month[i])) return i;
}

int cmp(const void *a,const void *b)
{
    return ((RECORD*)a)->val-((RECORD*)b)->val;
}

int main()
{
    int T,N,k=0;
    scanf("%d",&T);
    scanf("%d",&N);
    while(T--)
    {
        for(int i=0;i<N;i++)
        {
            scanf("%d. %s %d",&a[i].day,a[i].mon,&a[i].year);
            a[i].val=a[i].year*1000+monthtrans(a[i].mon)+a[i].day;
        }
        qsort(a,N,sizeof(RECORD),cmp);
        printf("case #%d:\n",k);
        for(int i=0;i<N;i++)
        {
            printf("%d. %s %d",a[i].day,a[i].mon,a[i].year);
        }
        k++;
    }
    return 0;
}
