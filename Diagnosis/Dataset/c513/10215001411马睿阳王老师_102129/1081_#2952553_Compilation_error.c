#include<stdio.h>
#include<math.h>
int main()
{int T,k,i;
 scanf("%d",&T);
 for(k=0;k<T;k++)
 {int a=0,n=0;
  long long int v=0;
  scanf("%d%d",&a,&n);
  v=power(a,n);
  printf("%lld",v);
 }
 return 0;
}