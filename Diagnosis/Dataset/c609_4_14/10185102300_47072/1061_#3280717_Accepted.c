#include <stdio.h>

#define N 1000

void findPrimes(int*a)
{ int i,j,b[N+1];  for (i=2; i<=N; i++) b[i]=1;
  for (i=2; i*i<N; i++) if (b[i])  for (j=2;i*j<=N;j++) b[i*j]=0;
  for (i=2;i<=N;i++) if (b[i]) *a++=i; *a=N+1;
}

long long f(int n,int start,int *primes)
{   static long long m[N+1][N/5];
     if (!m[n][start])
    { int i; if (!n) return m[n][start]=1;
       for (i=start;primes[i]<=n;i++) m[n][start]+=f(n-primes[i],i,primes);
    }
    return m[n][start];
}

int main()
{ int n,primes[N/5]; findPrimes(primes);
  printf("%lld\n",f((scanf("%d",&n),n),0,primes));
  return 0;
}