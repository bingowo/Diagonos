#include <stdio.h>
#define N 10007

unsigned long long c[1001];

void factors()
{
	for (unsigned long long i=0;i<1001;i++){
		if(i<=1){
			c[i]=1;
		}
		else{
			c[i]=(c[i-1]%N)*i%N;
		}
	}
}

unsigned long long cal(unsigned long long a,unsigned long long b)
{
	unsigned long long ans=1;
	while(b>0){
		if(b&1){
			ans=ans*a%N;
		}
		a=a*a%N;
		b>>=1;
	}
	return ans;
}

unsigned long long co(unsigned long long k,unsigned long long n,unsigned long long m)
{
	return c[k]*cal(c[n]*c[m]%N,N-2)%N;
}



void solve()
{
	factors();
	unsigned long long a,b,k,n,m;
	scanf("%llu %llu %llu %llu %llu",&a,&b,&k,&n,&m);
	a=cal(a,n)%N;
	b=cal(b,m)%N;
	unsigned long long ans=co(k,n,m)%N;
	ans=(ans*a*b)%N;
	printf("%llu\n",ans);
}

int main()
{
	int T;
	scanf("%d",&T);
	for (int i=0;i<T;i++){
		printf("case #%d:\n",i);
		solve();
	}
	return 0;
}