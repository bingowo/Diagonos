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
long long min=0,temp=0;
scanf("%d%d",&n,&m);
long long *p=(long long*)malloc(sizeof(long long)*n);
long long*q=(long long*)malloc(sizeof(long long)*n);
for(int t=0;t<n;t++)
    scanf("%lld",&p[t]);
qsort(p,n,sizeof(p[0]),cmp);
for(int j=0;j<n-1;j++)
{q[j]=p[j]-p[j+1];}
for(k=0;k<m-1;k++)
{temp+=q[k]*(m-k-1);}
min=temp;
for(int i=0;i<n-m;i++)
{temp=temp-q[i]*(m-1);
temp+=p[i+1]-p[i+m];
if(temp<min) min=temp;
}

printf("%lld",min);
free(p);
free(q);
}
