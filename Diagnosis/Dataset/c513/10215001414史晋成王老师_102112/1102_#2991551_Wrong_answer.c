#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<math.h>
struct point
{long long int a,b;};
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
  for(j=1;j<=count-1;j++)
    { if(j%2==0)
       { x.a+=j; x.b-=j;}
      else if(j%2!=0)
       {x.a-=j; x.b+=j;}
    }
    if(n>count&&count%2==0)
    { x.b-=count;x.a+=(n-count);  }
    else if(n<=count&&count%2==0)
    { x.b-=count;  }
    else if(n>count&&count%2!=0)
    { x.b+=count;x.a-=(n-count);  }
    else if(n<=count&&count%2!=0)
    { x.b+=count;  }
    if(n!=0)
    printf("(%lld,%lld)",x.a,x.b);
    else printf("(0,0)");
}