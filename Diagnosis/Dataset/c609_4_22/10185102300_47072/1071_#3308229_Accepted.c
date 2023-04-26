#include <stdio.h>
#include <math.h>

int Steps(long long x, long long y)
{ long long dist=llabs(x)+llabs(y);int r=log2(dist+1)+1;
  return (!dist)?0:(dist%2)?r-((1LL<<(r-1))>=dist+1):-1;
}

int main()
{ long long x,y,z;
  printf("%d\n",(scanf("%lld%lld",&x,&y),Steps(x,y)));
  return 0;
}