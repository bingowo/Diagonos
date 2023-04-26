#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int day;
    char month[10];
    int year;
    int val;
}Maya;
int month2idx(char* m)
{ int i;
  static char* month[] =
{"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
  for (i=0;;i++) if (!strcmp(m,month[i])) return i;
}
int main()
{
   int T;
   scanf("%d",&T);
   for(int i=0;i<T;i++)
   {
       int N;
       scanf("%d",&N);
       Maya a[100001];
       for(int j=0;j<N;j++)
       {
           scanf("%d.%s %d\n", &a[j].day, a[j].month, &a[j].year);
            a[j].val = a[j].year*1000+month2idx(a[j].month)*20+a[j].day;
       }
           int cmp(const void* a,const void* b)
            { return ((Maya*)a)->val - ((Maya*)b)->val; }
            qsort(a, N, sizeof(Maya), cmp);
            printf("case #%d:\n",i);
            for (int i=0;i<N;i++)
            printf("%d. %s %d\n",a[i].day,a[i].month,a[i].year);
    }
}
