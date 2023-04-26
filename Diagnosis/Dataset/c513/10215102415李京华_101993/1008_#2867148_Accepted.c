#include <stdio.h>

int f(int x, int y){
	int res = 0;
	while (x || y){
		int p = x & 1;
		int q = y & 1;
		if (p != q)
			++res;
		x = x >> 1;
		y = y >> 1;
	}
	return res;
}

int main()
{
	int T;
	scanf("%d",&T);
	while (T--){
		int ans = 0;
		int x, y;
		scanf("%d%d",&x,&y);
		ans = f(x, y);
		printf("%d\n",ans);
	}
	return 0;
}