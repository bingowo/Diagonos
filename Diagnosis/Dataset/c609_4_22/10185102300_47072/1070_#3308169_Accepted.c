#include <stdio.h>
#define N 64

int main()
{ int n;
  long long f[N]={2,4,7,12};
  for (n=3;n<N-1; n++)  f[n+1]=f[n]+f[n-1]+f[n-3];
  while (scanf("%d",&n),n+1) printf("%lld\n",f[n-1]);
  return 0;
}
