#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b)
{long long *p1=(long long *)a;
long long *p2=(long long*)b;
for(int i=0;p1[i]==p2[i]&&i<50;i++)
if(p1[i]>p2[i]) return -1;
else return 1;
}
int main()
{int t,n;
long long a[1000][51]={0},temp;
scanf("%d",&t);
for(int i=0;i<t;i++)
{scanf("%d",&n);
for(int k=0;k<n;k++)
   {for(int j=0;scanf("%lld",&temp)&&temp!=-1;j++)
   {a[k][j]=temp;}}
   qsort(a,n,sizeof(a[0]),cmp);
for(int k=0;k<n;k++)
{for(int j=0;a[k][j]!='0';j++)
{printf("%lld ",a[k][j]);
}
printf("\n");
}

}

}