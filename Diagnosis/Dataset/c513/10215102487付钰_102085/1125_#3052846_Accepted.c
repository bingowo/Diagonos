#include <stdio.h>
#include <ctype.h>

typedef long long int lli;

lli gcd (lli a, lli b)
{
	lli ret, rest = a % b;
	while(rest){
		a = b;
		b = rest;
		rest = a % b;
	}
	ret = b;
	return ret;
}

int main(void)
{
	int t;
	scanf("%d", &t);
	for(int i = 0 ; i < t; i ++){
		char s[20];
		scanf("%s", s);
		char *p = s;
		lli inte = 0;
		while(*p && *p != '.'){
			inte = inte * 10 + (*p - '0');//整数
			p ++;
		}
		printf("case #%d:\n", i);
		if(*p == '\0'){
			printf("%lld\n", inte);
		}else{
			p ++;
			int isLoop = 0;
			lli frac = 0, loop = 0, multi1 = 1, multi2 = 1;
			while(*p){
				if(isdigit(*p)){
					if(isLoop){//[]循环节里的
						loop = loop * 10 + (*p - '0');//loop是无限循环的个数
						frac = frac * 10 + (*p - '0');//frac是不循环的个数
						multi2 *= 10;
					}else{
						frac = frac * 10 + (*p - '0');//小数非循环
					}
					multi1 *= 10;//小数个数*10
				}else if(*p == ']'){
					break;
				}else if(*p == '['){
					isLoop = 1;
				}
				p ++;
			}
			lli n1, n2;
			//muti1=全部小数个数*10 muti2=无限循环小数个数*10
			//test:4.1[23]
			if(!isLoop){
				n1 = frac;
				n2 = multi1;
			}else if(multi2 == multi1){//纯循环
				n1 = frac;//循环节的数
				n2 = multi1 - 1;//9
			}else{//混循环
				n1 = frac * multi2 + loop - frac;
				n2 = multi1 * multi2 - multi1;
			}
			n1 = n1 + n2 * inte;
			lli g = gcd(n1, n2);
			n1 /= g, n2 /= g;
			printf("%lld/%lld\n", n1, n2);
		}
	}
	return 0;
}
