#include <stdio.h>

void solve()
{
	int n;
	scanf("%d",&n);
	int w,x,y,z;
	int cnt=0;
	for (w=0;4*w<=n;w++){
		for (x=0;3*x<=n;x++){
			for (y=0;2*y<=n;y++){
				if(4*w+3*x+2*y<=n){
					cnt++;
				}
			}
		}
	}
	printf("%d\n",cnt);
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		solve();
	}
	return 0;
}