#include<stdio.h>
#include<math.h>
int main()
{int T,k,i=0;
 scanf("%d",&T);
 for(k=0;k<T;k++)
 {int a,n;i=1;
  long long int s[100000];
  scanf("%d%d",&a,&n);
  if(n==0) s[i]=1;
  else if(n==1) s[i]=a;
  else 
  {
   while(i<=n)
  {s[1]=a;
   s[i]=a*s[i-1];
   i++;
  }
  }
  printf("case #%d:\n",k);
  printf("%lld\n",s[i]);
 }
 return 0;
}