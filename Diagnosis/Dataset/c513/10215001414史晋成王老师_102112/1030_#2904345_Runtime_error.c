#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{ long long int x,y; int m,n;
x=*(long long int*)a;
y=*(long long int*)b;
while(x!=0)
{ m=x%10;
    x=x-m;
  x=x/10;
}
}
int main()
{ int T,i,N,j; long long int a[100000];
scanf("%d\n",&T);
for(i=0;i<T;i++)
{scanf("%d",&N);
for(j=0;j<N;j++)
scanf("%lld ",a[j]);
qsort(a,N,sizeof(a[0]),cmp);
}
    
}