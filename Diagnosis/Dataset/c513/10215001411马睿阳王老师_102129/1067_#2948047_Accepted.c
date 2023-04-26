#include<stdio.h>
int main()
{int T,i,k;
 long long int v;
 scanf("%d",&T);
 long long int s[75];
 for(i=3;i<75;i++)
 {s[0]=0,s[1]=1,s[2]=1;
  s[i]=s[i-1]+s[i-2]+s[i-3];
 }
 for(k=0;k<T;k++)
 {int n;
  printf("case #%d:\n",k);
  scanf("%d",&n);
  v=s[n];
  printf("%lld\n",v);
 }
 return 0;
}