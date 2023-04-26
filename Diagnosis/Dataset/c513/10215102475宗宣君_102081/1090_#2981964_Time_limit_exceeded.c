#include<stdio.h>
int main()
{
 double m,n;
 while(scanf("%lf",&n)!=EOF)
 {
  m=1;int i;
  for(i=1;i<=n;i++)
  {
   m=m*n;
   if(m>1000000)
       m=m/1000000;
  }
  while(m>=10)
  {
   m=m/10;
  }
  printf("%d\n",(int)m);
 }
 return 0;
}
