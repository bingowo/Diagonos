#include <stdio.h>

int gcd(int a,int b)
{
	if(b%a==0) return a;
	return gcd(b%a,a);
}

void solve()
{
	int fz=0,fm=0;
	unsigned char c;
	c=getchar();
	while(c!='\n'){
		fm+=8;
		while(c>0){
			fz+=(c&1);
			c>>=1;
		}
		c=getchar();
	}
	int t;
	t=gcd(fz,fm);
	fz/=t;
	fm/=t;
	printf("%d/%d\n",fz,fm);
}

int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	for (int i=0;i<n;i++){
		solve();
	}
	return 0;
}