#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<math.h>
struct point
{int a,b;};
int main()
{ long long int n,i,j,m,count;
  struct point x;
  x.a=0;x.b=0;
  scanf("%lld",&n);
  count=1;
  while(n-2*count>0)
  { n-=2*count;
     count++;
  }
  printf("%lld",count);
    
}