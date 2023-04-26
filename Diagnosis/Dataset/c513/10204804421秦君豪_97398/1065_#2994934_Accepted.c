/*
Created by Shizumu on 2022-03-14
	也是递归可以简单地解决，但是要把这个式子列出来，还是需要一张草稿纸的。
*/
#include <stdio.h>

typedef long long int lli;
lli feb[25], SumOfFeb[25];

lli CalculateFeb(int n)
{
	int ret;
	if(n == 1 || n == 2){
		ret = 1;
		feb[1] = feb[2] = 1;
	}else{
		if(feb[n] != 0){
			ret = feb[n];
		}else{
			ret = CalculateFeb(n - 1) + CalculateFeb(n - 2);
			feb[n] = ret;
		}
	}
	return ret;
}

lli CalculateFebSum(int n)
{
	int ret = 0;
	if(n == 1){
		ret = 1;
		SumOfFeb[1] = ret;
	}else{
		if(SumOfFeb[n] != 0){
			ret = SumOfFeb[n];
		}else{
			ret = CalculateFebSum(n - 1) + CalculateFeb(n);
			SumOfFeb[n] = ret;
		}
	}

	return ret;
}

int main(void)
{
	int a, n, m, x;
	scanf("%d %d %d %d", &a, &n, &m, &x);
	int delta, res;
	CalculateFeb(n);
	CalculateFebSum(n);
//	for(int i = 0 ; i <= n; i ++){
//		printf("%d %d\n", feb[i], SumOfFeb[i]);
//	}
	delta = (m - a - SumOfFeb[n - 3] * a + SumOfFeb[n - 4] * a) / (SumOfFeb[n - 2] - (1 + SumOfFeb[n - 3]));
//	printf("%d\n", delta);
	if(x == 1){
		res = a;
	}else{
		res = a + a * SumOfFeb[x - 2] + delta * SumOfFeb[x - 1] - ((1 + SumOfFeb[x - 2])* delta + SumOfFeb[x - 3] * a);
	}
	printf("%d", res);

	return 0;
 }
