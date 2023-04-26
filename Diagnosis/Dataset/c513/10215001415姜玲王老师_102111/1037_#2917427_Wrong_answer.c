#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b)
{long long p1=*(long long*)a;
long long p2=*(long long*)b;
if(p1>p2) return -1;
else return 1;
}
int main()
{int n,m,k;
long long max=0,temp=0;
scanf("%d%d",&n,&m);
long long *p=(long long*)malloc(sizeof(long long)*n);
for(int t=0;t<n;t++)
    scanf("%lld",&p[t]);
qsort(p,n,sizeof(p[0]),cmp);
for(k=m-1;k<n;k++)
{for(int i=0;i<m;i++)
{temp=temp+p[k-m+1]-p[k-i];}
if(temp>max) max=temp;
}
printf("%lld",max);
free(p);
}
