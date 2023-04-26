#include <stdio.h>
#define N 32

int main()
{ int n,m;
  while (scanf("%d%d",&n,&m),n+1)
  { unsigned f[N]={0}; int i,j; f[m]=1;
    for(i=m;i<n; i++) f[i+1]=2*f[i]+(1<<(i-m))-f[i-m];
    printf("%u\n",f[n]);
  }
  return 0;
}

