#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct{int y;int d;char m[10];} time;
int month(char*m)
{int i;
static char*month[]={"pop", "no", "zip", "zotz", "tzec","xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab",
"cumhu","uayet"};
for(i=0;;i++) {if(!strcmp(m,month[i])) return i;}

}
int cmp(const void*a,const void*b)
{time*p1=(time*)a;
time*p2=(time*)b;
if((*p1).y<(*p2).y) return -1;
if((*p1).y>(*p2).y) return 1;
if(month((*p1).m)<month((*p2).m)) return -1;
if(month((*p1).m)>month((*p2).m)) return 1;
if((*p1).d<(*p2).d) return -1;
if((*p1).d>(*p2).d) return 1;
return -1;}
int main()
{time a[10000];
    int t,n;
scanf("%d",&t);
for(int i=0;i<t;i++)
{printf("case #%d:\n",i);
scanf("%d",&n);
for(int k=0;k<n;k++)
{scanf("%d.%s%d\n",&a[k].d,a[k].m,&a[k].y);}
qsort(a,n,sizeof(a[0]),cmp);
for(int k=0;k<n;k++)
    printf("%d. %s %d\n",a[k].d,a[k].y,a[k].y);
}

}
