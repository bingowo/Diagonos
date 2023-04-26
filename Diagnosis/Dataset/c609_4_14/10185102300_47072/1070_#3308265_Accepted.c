#include <stdio.h>
#define N 20

int main()
{ int n,f[N]={1,2,4,7};
  for (n=4;n<=N;n++)  f[n]=f[n-1]+f[n-2]+f[n-4];
  while (scanf("%d",&n),n+1) printf("%d\n",f[n]);
  return 0;
}


