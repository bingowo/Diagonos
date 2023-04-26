#include <stdio.h>
#include <stdlib.h>
typedef struct{long long r;long long h;long long s;long long c;} zhu;
int cmp1(const void*a,const void*b)
{long long p1=(*(zhu*)a).s;
long long p2=(*(zhu*)b).s;
if(p1>p2) return 1;
else return -1;
}
int cmp2(const void*a,const void*b)
{long long p1=(*(zhu*)a).c;
long long p2=(*(zhu*)b).c;
if(p1>p2) return -1;
else return 1;
}
int main()
{int n,m,S;
zhu a[1000];
scanf("%d%d",&n,&m);
for(int i=0;i<n;i++)
{scanf("%lld%lld",&a[i].r,&a[i].h);
a[i].c=a[i].r*2*a[i].h;
a[i].s=a[i].c+a[i].r*a[i].r;}
qsort(a,n,sizeof(a[0]),cmp1);
qsort(a,n-1,sizeof(a[0]),cmp2);
S=a[n-1].s;
for(int k=0;k<m-1;k++)
    S+=a[k].c;
printf("%lld",S);
}
