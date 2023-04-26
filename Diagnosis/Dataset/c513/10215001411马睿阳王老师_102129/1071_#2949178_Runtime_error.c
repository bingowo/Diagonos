#include<stdio.h>

int range(int n,int m)
{ int i,jc1=1,jc2=1,jc3=1;
  for(i=n;i>0;i--)
  {jc1*=n;}
  for(i=m;i>0;i--)
  {jc2*=m;}
  for(i=n-m;i>0;i--)
  {jc3*=n-m;}
  if(n==m) return 1;
  else return jc1/(jc2*jc3);
}

int main()
{int T,t,a,b,k,n,m,i,j,v,u;
 int dp[1005][1005];
 scanf("%d",&T);
for(t=0;t<T;t++)
 {scanf("%d %d %d %d %d ",&a,&b,&k,&n,&m);
 v=range(n,m);
 u=v%10007;
 printf("case #%d:\n",t);
 printf("%d\n",u);
 }
 return 0;
}