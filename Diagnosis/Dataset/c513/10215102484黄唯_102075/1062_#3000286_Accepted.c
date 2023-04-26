#include<stdio.h>
#include<stdlib.h>

typedef long long int lli;
//纯递归思想 会超时
//lli CountWays(lli n) {
//	if (n == 0) return 0;
//	else if (n == 1) return 1;
//	else if (n == 2) return 2;
//	else if (n == 3) return 4;
//	else if (n == 4) return 8;
//	else {
//		return CountWays(n - 1) + CountWays(n - 2) + CountWays(n - 3) + CountWays(n - 4);
//	}
//
//}

//迭代思想

lli map[51] = { 1,2,4,8 };
lli Ways(lli n) {
		lli ret;
		if (n == 0) return 0;
		else if (n == 1) return 1;
		else if (n == 2) return 2;
		else if (n == 3) return 4;
		else if (n == 4) return 8;
		else {
		if (map[n] != 0) {
			ret = map[n];
		}
		else {
			ret = Ways(n - 1) + Ways(n - 2) + Ways(n - 3) + Ways(n - 4);  //相当于记录下了每次计算结果的值，只需要在上一次的基础上再加就好了，效率更高
			map[n] = ret;
		}
		return ret;
	}

}
int main() {
	int t;
	lli ret,n;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%lld", &n);
		ret = Ways(n);
		printf("case #%d:\n", i);
		printf("%lld\n", ret);
	
	}	
	return 0;
}