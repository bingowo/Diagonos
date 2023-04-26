#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
  int d;
  int y;
  int val;
  char m[7];
  }Record;
int cmp(const void* a,const void* b)
{
     return ((Record*)a)->val - ((Record*)b)->val; }

int month2idx(char* m)
{
   static char* month[]   =
{"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};

    for (int i=0;; i++)
          if (!strcmp(m,month[i])) return i;
}
int main()
{ int T;
scanf("%d",&T);
for(int i=0;i<T;i++){
int N;
scanf("%d",&N);
printf("case #%d:\n",i);
  Record a[10001];
  for (int i=0;i<N;i++)
 {
      scanf("%d.%s %d", &a[i].d, a[i].m, &a[i].y);
      a[i].val = a[i].y*1000 + month2idx(a[i].m)*20 + a[i].d;
}
qsort(a,N,sizeof(Record),cmp);
for (int i=0;i<N;i++)
     printf("%d. %s %d\n",a[i].d,a[i].m,a[i].y);

}}
