#include <stdio.h>
#include<math.h>
int main()
{ int b=0,T,i,j; char c[100]; int a[128];
 int digit=0,N=1; char *p; long long int ans=0;
  scanf("%d",&T);
  for (j=0;j<T;j++)
  { scanf("%s",c);
    for (i=0;i<128;i++) a[i]=-1;
  
  *p=c; a[*p]=1;
  while(*++p)
  { if (a[*p]==-1)
    a[*p]=digit;digit=digit?digit+1:2;N++; 
  }
  if (N<2) N=2;
  *p=c;
  while(*p) ans=ans*N+a[*p++];
  printf("case #%d:\n",j);
  printf("lld\n",ans); }
}