#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int val;//日期的“大小”
    int y;
    int d;
    char m[7];
}maya;
maya a[10000];

int getmonth(char* m)
{
    int i;
    static char* month[]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","y ax","zac","ceh","mac","kankin","muan","pax","koyab","cum hu","uayet"};
    for(i=0;;i++)
    {
        if(strcmp(m,month[i])==0)
        {
            return i;
            break;
        }
    }
}

int cmp(const void *a,const void *b)
{
    return ((maya*)a)->val-((maya*)b)->val;
}

int main()
{
    int t;
    scanf("%d\n",&t);
    for(int k=0;k<t;k++)
    {
        printf("case #%d:\n",k);
        int n;
        scanf("%d\n",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d. %s %d\n",&a[i].d,a[i].m,&a[i].y);
            a[i].val=a[i].y*1000+getmonth(a[i].m)*20+a[i].d;
        }
        qsort(a,n,sizeof(a[0]),cmp);
        for(int i=0;i<n;i++)
            printf("%d. %s %d\n",a[i].d,a[i].m,a[i].y);
    }
    return 0;
}