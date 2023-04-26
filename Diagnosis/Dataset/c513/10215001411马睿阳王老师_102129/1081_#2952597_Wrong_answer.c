#include<stdio.h>
#include<math.h>
int main()
{int T,k,i=0;
 scanf("%d",&T);
 for(k=0;k<T;k++)
 {int a=0,n=0;
  long long int v=1;
  scanf("%d%d",&a,&n);
  while(i<=n)
  {v*=v;
   i++;
  }
  printf("case #%d:\n",k);
  printf("%lld\n",v);
 }
 return 0;
}