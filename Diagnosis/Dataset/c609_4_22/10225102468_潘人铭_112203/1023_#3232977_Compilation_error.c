#include<stdio.h>
int main()
{
typedef struct{
    int val;
    int y;
    int d;
    char m[7];
}RECORD;
int month2idx(char*m)
{
    int i;
    static char*month[]=
    {
        "pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"
    };
    for(i=o;;i++) if(!strcmp(m,month[i])) return i;
}
for(i=0;i<N;i++){
    scanf("%d.%s %d\n",&a[i].d,a[i].m,&a[i].y);
    a[i].val=a[i].y*1000+month2idx(a[i].m)*20+a[i].d;
}
int cmp(const void*a,const void*b)
{
    return
    （（ RECORD*)a)->val-(RECORD*)b->val;
}
qsort(a,N,sizeof(RECORD),cmp);
fot(i=0;i<N,i++)
printf("%d.%s %d\n",a[i].d,a[i].m,a[i].y);
return 0;
}
