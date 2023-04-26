#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int T;
	scanf("%d",&T);
	int i,j,n;
	long long int a,b,c,d,e, ans;
	for (i = 0; i < T; i++){
		int n;
		scanf("%ud",&n);
		printf("case #%d:\n",i);
		a = 1;
		b = 2;
		c = 4;
		d = 8;
		int j;
		if (n == 1){
			ans = 1;
		}else if( n == 2 ){
			ans = 2;
		}else if (n == 3){
			ans = 4;
		}else if (n == 4){
			ans = 8;
		}else if (n > 4){
			for (j = 5; j <= n; j++){
				e = a + b + c + d;
				a = b;
				b = c;
				c = d;
				d = e;
			}
			ans = e;
		}
		printf("%lld\n", ans);
		a = 1;
		b = 2;
		c = 4;
		d = 8;
		ans = 0;
	}
	return 0;
}

//unsigned int ans(unsigned int n){
//
//	return ans(n-1) + ans(n-2) + ans(n-3) + ans(n-4);
//}