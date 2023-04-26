#include <stdio.h>

long long min(long long x,long long y){ return x<y?x:y; }
int main()
{ long long x,y,v=0,t;
  scanf("%lld%lld",&x,&y);
  while(x&&y) (x>(t=min(x,y)))? (v+=4*(x/t),x%=t):(v+=4*(y/t),y%=t);
  printf("%lld\n",v);
  return 0;
}
