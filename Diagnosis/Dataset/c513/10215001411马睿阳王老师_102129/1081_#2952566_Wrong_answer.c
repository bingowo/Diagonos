#include<stdio.h>
#include<math.h>
int main()
{int T,k,i;
 scanf("%d",&T);
 for(k=0;k<T;k++)
 {int a=0,n=0;
  long long int v=0;
  scanf("%d%d",&a,&n);
  v=pow(a,n);
  printf("case #%d:\n",k);
  printf("%lld\n",v);
 }
 return 0;
}