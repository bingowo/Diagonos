#include <stdio.h>
#include <string.h>
int Gcd(int x, int y){
	if (x < y)
		return Gcd(y,x);
	while (x % y){
		int swap = y;
		y = x % y;
		x = swap;
	}
	return y;
}

int num(char *L, int len){
	int ret = 0;
	int i = 0;
	for (i = 0; i < len; i++){
		int res = L[i];
		int j = sizeof(char) * 8;
		while (j--){
			if (res & 1)
				++ret;
			res = res >> 1;
		}
	}
	return ret;
}
int main()
{
	int T;
	scanf("%d",&T);
	getchar();
	while (T--){
		char L[121];
		gets(L);
		
		int len = strlen(L);

		int a = num(L,len);
		int b = 8 *len * sizeof(char);

		int gcd = Gcd(a,b);
		printf("%d/%d\n",a/gcd,b/gcd);
	}
	return 0;
}