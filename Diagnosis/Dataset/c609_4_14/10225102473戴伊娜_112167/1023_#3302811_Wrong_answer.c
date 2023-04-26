#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
     int val;
     int y;
     int d;
     char m[7];
} record;

int month2idx(char* m)
{
    int i;
    char* month[] = {"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","y ax","zac","ceh","mac","kankin","muan","pax","koyab","cum hu","uayet"};
    for (i=0;;i++)
        {if (strcmp(m,month[i])==0);
        return i;}
}

int cmp(const void*a,const void*b)
{
    return ((record*)a)->val - ((record*)b)->val;
}

int main()
{
    int n,t;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&t);
        record a[t];
        for(int q=0;q<t;q++)
        {
            scanf("%d.%s %d\n",&a[i].d, a[i].m, &a[i].y);
            a[i].val = a[i].y*1000+month2idx(a[i].m)*20+a[i].d;
            qsort(a,t,sizeof(record),cmp);
        }
        for (int k=0;k<t;k++)
            printf("%d. %s %d\n",a[k].d,a[k].m,a[k].y);
    }
    return 0;
}
