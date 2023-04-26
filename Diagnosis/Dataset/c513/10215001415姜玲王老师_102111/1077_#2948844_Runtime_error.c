#include <stdio.h>
#include <stdlib.h>
int a['9'+1]={500};
int cmp(const void*c,const void*b)
{int p1=*(int*)c;
int p2=*(int*)b;
if(a[p1+'0']!=a[p2+'0']) return a[p1+'0']-a[p2+'0'];
return p1-p2;
}
int main()
{int n,m;
char b[500];
int c[500];
scanf("%d",&n);
for(int i=0;i<n;i++)
{scanf("%c",&b[i]);
a[b[i]]=i;}
scanf("%d",&m);
for(int i=0;i<m;i++)
{scanf("%d",c[i]);}
qsort(c,m,sizeof(int),cmp);
for(int i=0;i<m;i++)
{printf("%d ",c[i]);
}

}
