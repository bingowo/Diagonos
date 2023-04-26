#include <stdio.h>

long long int swap(long long int a,long long int b)
{long long t;
 t=a;
 a=b;
 b=t;
}

long long int f(long long int x,long long int y)
 {
  if(x<y) return swap(x,y);
  else if(x==y) return 4*x;
  else if(x%y==0) return x*4;
  else return 4*x+f(x%y,y);
 }

int main()
{ long long int x,y,v;
  scanf("%lld %lld",&x,&y);
  v=f(x,y);
 printf("%lld",v);
 return 0;

}
