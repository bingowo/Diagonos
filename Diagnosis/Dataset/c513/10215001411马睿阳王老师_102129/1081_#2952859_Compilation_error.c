#include<stdio.h>
#include<math.h>
int main()
{int T,k,i=0;
 scanf("%d",&T);
 for(k=0;k<T;k++)
 {int a=0,n=0;i=0;
  long long int s[10000000000000000]=1;
  scanf("%d%d",&a,&n);
  if(n==0) s[0]=1;
  else 
  {while(i<=n)
  {s[i]*=a;
   i++;
  }
  }
  printf("case #%d:\n",k);
  printf("%lld\n",s[i]);
 }
 return 0;
}