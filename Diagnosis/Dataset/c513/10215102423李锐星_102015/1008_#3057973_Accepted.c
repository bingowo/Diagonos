#include <stdio.h>

void solve()
{
	int x,y;
	scanf("%d %d",&x,&y);
	int a[32]={0},b[32]={0};
	int i;
	int res=0;
	for (i=0;i<32;i++){
		a[i]=x&1;
		x>>=1;
		b[i]=y&1;
		y>>=1;
		res+=(a[i]^b[i]);
	}
	printf("%d\n",res);
}

int main()
{
	int T;
	scanf("%d",&T);
	for (int i=0;i<T;i++){
		solve();
	}
	return 0;
}