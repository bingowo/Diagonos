#include <stdio.h>

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
	int n;
	scanf("%d", &n);
	char num[100];
	lli sn1 = 0, sn2 = 0;
	for(int i = 0 ; i < n ; i++){
		scanf("%s", num);
		char *p = num;
		lli n1 = 0, n2 = 0;
		lli g = 0;
		while(*p != '/'){
			n1 = n1 * 10 + (*p - '0');
			p ++;
		}
		p ++;
		while(*p){
			n2 = n2 * 10 + (*p - '0');
			p ++;
		}
		if(sn1 == 0 && sn2 == 0){
			sn1 = n1, sn2 = n2;
		}else{
			sn1 = sn1 * n2 + n1 * sn2;
			sn2 = sn2 * n2;
			g = gcd(sn1, sn2);
			sn2 = sn2 / g, sn1 = sn1 / g; 
		}
	}
	printf("%lld/%lld", sn1, sn2);

	
	return 0;
}