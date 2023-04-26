#include <stdio.h>
#include <stdlib.h>
typedef struct{long long r;long long h;long long d;long long c;} zhu;
int cmp(const void*a,const void*b)
{long long p1=(*(zhu*)a).c;
long long p2=(*(zhu*)b).c;
if(p1>p2) return -1;
else return 1;
}
int main()
{int n,m,i;
long long max,temp,store,S;
zhu a[1000];
scanf("%d%d",&n,&m);
for(int i=0;i<n;i++)
{scanf("%lld%lld",&a[i].r,&a[i].h);
a[i].c=a[i].r*2*a[i].h;
a[i].d=a[i].r*a[i].r;}
qsort(a,n,sizeof(a[0]),cmp);
max=a[0].d;
for( i=0;i<m;i++)
{if(max<a[i].d) max=a[i].d;
S+=a[i].c;}
S+=max;

    printf("%lld",S);
}
