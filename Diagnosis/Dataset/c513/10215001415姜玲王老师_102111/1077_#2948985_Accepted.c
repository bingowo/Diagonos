#include <stdio.h>
#include <stdlib.h>
int a[1001];
int cmp(const void*c,const void*b)
{int p1=*(int*)c;
int p2=*(int*)b;
if(a[p1]>a[p2]) return 1;
if(a[p1]<a[p2]) return -1;
 return p1-p2;
}

int main()
{for(int i=0;i<1001;i++)
{a[i]=500;}
int n,m,i;
int b[500],c[500];
scanf("%d",&n);
for(i=0;i<n;i++)
{scanf("%d",&b[i]);
a[b[i]]=i;}
scanf("%d",&m);
for( i=0;i<m;i++)
{scanf("%d",&c[i]);}

qsort(c,m,sizeof(int),cmp);

for(int i=0;i<m;i++)
{printf("%d ",c[i]);
}

}
