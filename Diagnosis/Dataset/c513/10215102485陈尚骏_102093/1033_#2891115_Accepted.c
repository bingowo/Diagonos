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
    for(int i=0;i<19;i++)
        if(!strcmp(m,month[i])) return i;
}

int cmp(const void*a,const void*b)
{
    RECORD*aa=(RECORD*)a;
    RECORD*bb=(RECORD*)b;
    aa->val=(aa->year)*400+(aa->day)+(monthtrans(aa->mon))*20;
    bb->val=(bb->year)*400+(bb->day)+(monthtrans(bb->mon))*20;
    return (aa->val)>(bb->val);

}
int main()
{
    int T,N,k=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        for(int i=0;i<N;i++)
        {
            scanf("%d. %s %d",&a[i].day,a[i].mon,&a[i].year);
            a[i].val=a[i].year*1000+monthtrans(a[i].mon)+a[i].day;
        }
        qsort(a,N,sizeof(RECORD),cmp);
        printf("case #%d:\n",k);
        for(int i=0;i<N;i++)
        {
            printf("%d. %s %d\n",a[i].day,a[i].mon,a[i].year);
        }
        k++;
    }
    return 0;
}
