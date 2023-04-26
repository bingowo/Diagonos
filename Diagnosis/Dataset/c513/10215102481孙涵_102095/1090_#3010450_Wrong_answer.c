#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h> 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*
思路
N^N = 10^(N*log(N))中， 
由于 N <100 000 000， 
N*log(N)取值在[0,800 000 000]，没有超出double数据的范围，没有溢出。 
设N*log(N)的整数部分为intpart，分数部分为fractpart， 
则N^N = 10^(intpart + fractpart) = 10^intpart * 10^fractpart. 
其中10^intpart肯定为10的倍数，不影响结果，可忽略。 
所以： 
10^fractpart的最高位即为结果。*/

int main(int argc, char *argv[]) {
	long long int n,result;
	double x,y;
	while (scanf("%lld",&n) != 0 && scanf("%lld",&n) != EOF){
		x = n * log10(n);
		y = (long long)x;
		x = x - y;
		result =(long long)pow(10.0,x); 
		printf("%d\n",result);
	}
	return 0;
}