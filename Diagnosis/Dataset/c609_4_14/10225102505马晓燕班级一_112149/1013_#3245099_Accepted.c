#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[1005];
int pow[4][2] = {1, 0, -1, 1, 0, -2, 2, 2};//分别代表(-1+i)的0~3次 
long long a = 0, b = 0;//a代表实数部分，b代表虚数部分 

void out(long long x) {//复数的输出函数 
	if(x == 1) puts("i");
	else if(x == -1) puts("-i");
	else printf("%lldi\n",b);
}
int main() {
	scanf("0x%s",s);
	int l = strlen(s);
	long long res = 1;
	for(int i = l-1; i >= 0; i --) {
		int num = 0;
		if(s[i] >= 'A' && s[i] <= 'F') num = 10 + s[i] - 'A';
		else num = s[i] - '0';//十六进制数字读入 
		for(int c = 0; c < 4; c ++) {//每个十六进制对应四个二进制位 
			if(num & 1) a += res * pow[c][0], b += res * pow[c][1];
			num >>= 1;
		}
		res *= -4;//（-1+i）^4 
	}
	if(b == 0) printf("%lld", a);
	else if(a == 0) out(b);
	else if(b < 0) printf("%lld", a), out(b);
	else printf("%lld+", a), out(b);
	return 0;
}