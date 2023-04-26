#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{ long long int x,y,q,g; int m,n;
q=*(long long int*)a;
g=*(long long int*)b;
x=labs(q);
y=labs(g);
while(x>=10)
{ m=x%10;
    x=x-m;
  x=x/10;
}
while(y>=10)
{ n=y%10;
    y=y-n;
  y=y/10;
}
if(x!=y) return y-x;
else if(q>g) return 1;
else if(q<g) return -1;
}
int main()
{ int T,i,N,j,d; long long int a[100000];
scanf("%d\n",&T);
for(i=0;i<T;i++)
{scanf("%d",&N);
for(j=0;j<N;j++)
scanf("%lld ",&a[j]);
qsort(a,N,sizeof(a[0]),cmp);
printf("case #%d:\n",i);
for(d=0;d<N-1;d++)
printf("%lld ",a[d]);
printf("%lld\n",a[d]);
}

    
}