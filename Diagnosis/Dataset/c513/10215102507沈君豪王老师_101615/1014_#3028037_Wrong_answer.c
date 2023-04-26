#include <stdio.h>
#include <math.h>
#define N 200
typedef long long int lli;

lli gcd(lli a, lli b)
{
	return (a % b == 0) ? b : gcd(b, a % b);
}


int main(void)
{
	lli n1, n2;
	scanf("%lld %lld", &n1, &n2);
	int sig = n1 * n2 < 0 ? -1 : 1;
	n1 = abs(n1), n2 = abs(n2);
	lli intnum = n1 / n2;
	n1 -= (intnum * n2);
	lli g = gcd(n1, n2);
	n1 /= g, n2 /= g;
	int fracLen = log10(n2) / log10(3);
	int intLen = intnum == 0 ? 1 : ceil(log10(intnum)/ log10(3)) + 1;
	lli inte[N] = {0}, frac[N] = {0};
	
	for(lli i = N - 1, t = intnum; i >= 0 ; i --){
		inte[i] = t % 3;
		t /= 3;
		if(t == 0){
			break;
		}
	}
	
	for(lli i = N - 1, t = n1; i >= 0 ; i --){
		frac[i] = t % 3;
		t /= 3;
		if(t == 0){
			break;
		}
	}
	
	for(lli i = N - 1, cnt = 0; i >= 0 && cnt < fracLen; i --, cnt ++){
		frac[i] += 1;
		for(lli j = i; j > 0 && frac[j] > 2; j --){
			frac[j] %= 3;
			frac[j - 1] += 1;
		}
	}
	
	lli carry = frac[N - 1 - fracLen];
	frac[N - 1 - fracLen] = 0;
	for(lli i = N - 1, cnt = 0; i >= 0 && cnt < intLen; i --, cnt ++){
		if(cnt == intLen - 1 && inte[i] == 0 && carry == 0){
			break;
		}
		inte[i] += (1 + carry);
		carry = 0;
		for(lli j = i; j > 0 && inte[j] > 2; j --){
			inte[j] %= 3;
			inte[j - 1] += 1;
			if(j - 1 < N - intLen){
				intLen ++;
			}
		}		
	}
	
	lli idx = 0;
	for(idx; inte[idx] == 0; idx ++);
	if(intnum == 0){
		printf("0");
	}else{
		if(sig == 1){
			for(idx ; idx < N; idx ++){
				printf("%d", (inte[idx] + 2) % 3);
			}	
		}else{
			for(idx ; idx < N; idx ++){
				if(inte[idx] == 2){
					printf("2");
				}else if(inte[idx] == 1){
					printf("0");
				}else{
					printf("1");
				}
			}			
		}
	}
	if(fracLen != 0){
		printf(".");
		if(sig == 1){
			for(idx = N - fracLen ; idx < N; idx ++){
				printf("%d", (frac[idx] + 2) % 3);
			}	
		}else{
			for(idx = N - fracLen ; idx < N; idx ++){
				if(frac[idx] == 2){
					printf("2");
				}else if(frac[idx] == 1){
					printf("0");
				}else{
					printf("1");
				}
			}			
		}
	}
	
	return 0;
}