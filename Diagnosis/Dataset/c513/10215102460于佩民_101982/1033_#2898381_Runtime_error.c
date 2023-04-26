#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {int val;int y;int d;char m[7];} data;
data a[10000];
int month2idx(char* m)
{ int i;
  static char* month[] ={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
  for (i=0;;i++)
  {if (!strcmp(m,month[i])) return i;}}

int cmp(const void* c,const void* d)
{ return
    ((data*)c)->val - ((data*)d)->val; }

int main(){
    int num,now=0,N,i;
    scanf("%d",&num);
    while(now<num){
        scanf("%d",&N);
        for (i=0;i<N;i++) {
            scanf("%d.",&a[i].d);
            scanf("%s",a[i].m);
            scanf("%d\n",&a[i].y);
            a[i].val = a[i].y*1000+month2idx(a[i].m)*20+a[i].d;
        }
        qsort(a, N, sizeof(a), cmp);
        for (i=0;i<N;i++)
            printf("%d. %s %d\n",a[i].d,a[i].m,a[i].y);
        now++;}
    return 0;
}