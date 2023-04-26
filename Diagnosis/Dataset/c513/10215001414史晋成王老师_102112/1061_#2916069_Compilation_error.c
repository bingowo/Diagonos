#include <stdio.h>
#include<math.h>
struct tle{
  long long int ans;
  char c[100];
};
int cmp(const void*a,const void*b)
{ struct tle x,y;
 x=*((struct tle*)a);
  y=*((struct tle*)b);
   if(x.ans>y.ans) return 1;
   else return -1;
}
int main()
{ int b=0,T,i,j,k;  int a[128];struct tle p[11000];
  scanf("%d",&T);
  for (j=0;j<T;j++)
  { scanf("%s",p[j].c);
    for (i=0;i<128;i++) a[i]=-1;
  
  char* m=p[j].c; int digit=0,N=1,i;
  a[*m]=1;
  while(*++m)
   if (a[*m]==-1)
    {a[*m]=digit; digit=digit?digit+1:2; N++; }
  if (N<2) N=2;
  p[j].ans=0;
  m=p[j].c        
  while(*m) p[j].ans=p[j].ans*N+a[*m++];
 }
qsort(p,T,sizeof(p[0]),cmp);
for(k=0;k<T;k++)
{printf("%s\n",p[k].c);
}
}