#include <stdio.h>

unsigned long long gcd(unsigned long long x,unsigned long long y)
{
	if(y%x==0) return x;
	return gcd(y%x,x);
}

void solve(int T)
{
	int m,n;
	scanf("%d%d",&m,&n);
	if(n==0){
		printf("1\n");
	}
	else{
		int i,j;
		unsigned long long fz=1,fm=1;
		if(n>m/2){
			n=m-n;
		}
		for (i=n,j=m;i>0;i--,j--){
			fz*=j;
			fm*=i;
			unsigned long long t=gcd(fm,fz);
			fz/=t;
			fm/=t;
		}
		printf("%llu\n",fz/fm);
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	for (int i=0;i<T;i++){
		printf("case #%d:\n",i);
		solve(i);
	}
	return 0;
}