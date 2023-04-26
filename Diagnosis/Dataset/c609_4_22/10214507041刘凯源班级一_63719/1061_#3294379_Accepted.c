#include<stdio.h>
#define MAXN 1005
int v[MAXN];
int primes[MAXN], cnt;
void ini(int n)
{
	for(int i = 2; i <= n; ++i)
	{
		if(!v[i])
		{
			primes[++cnt] = i;
			for(int j = 1; i * j <= n; ++j)
				v[i * j] = 1;
		}
	}
}
int n;
long long f[MAXN];
int main()
{
	scanf("%d", &n);
	ini(n);
	for(int i = 1; i <= cnt; ++i)
	{
		f[primes[i]] += 1;
		for(int j = primes[i]; j <= n; ++j)
		{
			f[j] += f[j - primes[i]];
		}
	}
	printf("%lld", f[n]);
}