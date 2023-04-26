#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int val; int y; int d; char m[7];
} RECORD;

RECORD a[10];

int month2idx(char *m)
{
    static char* month[] = {"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu"};
    for(int i=0; ;i++)
        if(!strcmp(m,month[i]))
            return i;
}

int cmp(const void*a,const void*b)
{
    return ((RECORD*)a)->val - ((RECORD*)b)->val;
}

int main()
{
    int T; scanf("%d",&T);
    int N; 
    for(int j=0;j<T;j++)
    {
        scanf("%d",&N);
        int i;
        for(i=0;i<N;i++)
        {
            scanf("%d. %s %d",&a[i].d,a[i].m,&a[i].y);
            a[i].val = a[i].y*800 + month2idx(a[i].m)*20 + a[i].d;
        }
        qsort(a,N,sizeof(RECORD),cmp);
        printf("case #%d:\n",j);
        for(i=0;i<N;i++) printf("%d. %s %d\n",a[i].d,a[i].m,a[i].y);
    }
    return 0;
}
