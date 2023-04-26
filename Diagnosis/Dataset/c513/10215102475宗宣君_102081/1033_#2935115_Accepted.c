#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
int val;
int y;
int d;
char m[7];
}RECORD;
int monthidx(char *m)
{
int i;
static char *month[] = {"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
for(i = 0;;i++)
    if(!strcmp(m,month[i])) return i;
}
int cmp(const void*a,const void*b)
{
    return ((RECORD*)a)->val-((RECORD*)b)->val;
}
int main()
{
   int T,i,j;
   scanf("%d",&T);
   for(i = 0;i<T;i++)
   {
       int N;
       scanf("%d",&N);
       RECORD a[10001];
       for(j = 0;j<N;j++)
        {scanf("%d. %s %d",&a[j].d,a[j].m,&a[j].y);
        a[j].val = a[j].y*1000+monthidx(a[j].m)*20+a[j].d;
        }
        qsort(a,N,sizeof(RECORD),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<N;j++)
            printf("%d. %s %d\n",a[j].d,a[j].m,a[j].y);
   }
   return 0;

}
