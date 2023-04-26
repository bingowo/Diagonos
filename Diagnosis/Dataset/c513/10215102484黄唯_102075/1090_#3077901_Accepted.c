/*
	Created by Shizumu on 2022-03-21
	这是一个数学题。
	n^n = 10^i * a;
	a的整数部分就是这个题目的答案。两边取对数有：
	nlog10(n) = i + log10(a)
	其中i是整数，a是小数，我们使用库函数完成这些运算。 
*/

#include <stdio.h>
#include <math.h>

int main(void) 
{
	int n;
	scanf("%d", &n);
	while(n){
		double n_ = n * log10(n), i = 0;
		double f = modf(n_, &i);
		/*
		_________________________________________________________________________
		modf
		语法：
		#include <math.h>
		double modf(double num, double *i);
		
		功能：函数将参数num分割为整数和小数，返回小数部分并将整数部分赋给i	
		_________________________________________________________________________ 
		*/
		int a = (int)pow(10, f);
		printf("%d\n", a);
		scanf("%d", &n);
	}
	
	return 0;
}
