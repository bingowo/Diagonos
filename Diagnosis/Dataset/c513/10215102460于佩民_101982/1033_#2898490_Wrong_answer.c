#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data{int val;int y;int d;char m[7];};
struct data a[10000];
int month2idx(char* m)
{ int i;
    static char* month[] ={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
    for (i=0;;i++)
    {if (!strcmp(m,month[i])) return i;}}

int cmp(const void* c,const void* d)
{   struct data a1,a2;
    a1=*((struct data*)c);
    a2=*((struct data*)d);
    return a1.val - a2.val; }

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
        qsort(a, N, sizeof(struct data), cmp);
        printf("case #");
        printf("%d:\n",&now);
        for (i=0;i<N;i++)
            printf("%d. %s %d\n",a[i].d,a[i].m,a[i].y);
        now++;}
    return 0;
}