#include <stdio.h>

long long int max(long long int a,long long int b)
{if(a>b) return a;
 else return b;
}

long long int min(long long int a,long long int b)
{if(a>b) return b;
 else return a;
}


long long int m(long long int x,long long int y)
{ long long int min,max;
  min=min(x,y);
  max=max(x,y);
  if(max==min) return 4*x;
  else if(max%min==0) return x*4;
  else return max*4+min(max%min,min);
}
int main()
{ long long int x,y,v=0;
  scanf("%lld %lld",&x,&y);
  min=min(x,y);
  max=max(x,y);
  v=m(max,min);
 printf("%lld",v);
 return 0;

}
