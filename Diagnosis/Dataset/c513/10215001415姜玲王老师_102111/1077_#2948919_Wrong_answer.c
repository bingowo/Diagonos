#include <stdio.h>
#include <stdlib.h>
int a[10]={500};

int main()
{int n,m;
int b[500],c[500];
scanf("%d",&n);
for(int i=0;i<n;i++)
{scanf("%d",&b[i]);
a[b[i]]=i;}
scanf("%d",&m);
for(int i=0;i<m;i++)
{scanf("%d",&c[i]);}
int cmp(const void*c,const void*b)
{int p1=*(int*)c;
int p2=*(int*)b;
if(a[p1]!=a[p2]) return a[p1]-a[p2];
else return p1-p2;
}
qsort(c,m,sizeof(int),cmp);

for(int i=0;i<m;i++)
{printf("%d ",c[i]);
}

}
