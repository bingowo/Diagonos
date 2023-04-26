#include <stdio.h>
#include <math.h>

int main()
{  long long x,y,z;
   printf("%d\n",(scanf("%lld%lld",&x,&y),z=llabs(x)+llabs(y))%2?(int)(log2(z+1)+.5):-1);
   return 0;
}