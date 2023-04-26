#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{int val;int y;int d;char m[7];} a;

int month2idx(char* m)
{ int i;
  static char* month[] ={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
  for (i=0;;i++)
  {if (!strcmp(m,month[i])) return i;}}

int cmp(const void* c,const void* d)
{ return
    ((a*)c)->val - ((a*)d)->val; }

int main(){
    int Num,Now=0,N,i;
    while(Now<Num){
        scanf("%d",&N);
        for (i=0;i<N;i++) {
            scanf(“%d. %s %d\n”, &a[i].d, a[i].m, &a[i].y);
            a[i].val = a[i].y*1000+month2idx(a[i].m)*20+a[i].d;
        }
        qsort(a, N, sizeof(a), cmp);
        for (i=0;i<N;i++)
            printf("%d. %s %d\n",a[i].d,a[i].m,a[i].y)
    }
    Now++;
}