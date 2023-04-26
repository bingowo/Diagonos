#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
typedef struct {
    int y;
    int d;
    char m[7];
    int sum;
} maya;

int mton(char *m)
{
    static char* month[]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
    for(int k=0;;k++)
        if(strcmp(m,month[k])==0)
            return  k;
}

int cmp(const void *a,const void *b)
{
    return ((maya*)a)->sum-((maya*)b)->sum;
}

int main()
{
    int t;
    maya a[10001];
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
    for(int m=0;m<n;m++)
    {
        scanf("%d. %s %d",&a[m].d,&a[m].m,&a[m].y);
        a[m].sum=a[m].y*1000+ mton(a[m].m)*20+a[m].d;
    }
        qsort(a,n, sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for(int r=0;r<n;r++)
        printf("%d. %s %d\n",a[r].d,a[r].m,a[r].y);
    }
    return 0;
}