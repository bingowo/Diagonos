#include <stdio.h>
#define N 20

int main()
{ int n,f[N]={2,4,7,12};
  for (n=3;n<N-1; n++)  f[n+1]=f[n]+f[n-1]+f[n-3];
  while (scanf("%d",&n),n+1) printf("%d\n",f[n-1]);
  return 0;
}


