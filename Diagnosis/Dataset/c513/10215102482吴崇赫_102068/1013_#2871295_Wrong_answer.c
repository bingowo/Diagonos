#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
long long GCD(long long m, long long n) {
	return m % n ? n : GCD(n, m % n);
}
//无小数
void solveInt(char* s) {
	long long ans = 0;
	int len = strlen(s);
	for (int i = 0;i < len;++i) {
		ans *= 3;
		if (s[i] == '1')ans ++;
		if (s[i] == '0')ans += 0;
		if (s[i] == '2')ans--;
	}
	printf("%lld", ans);
}

void solveDouble(char* s) {
	long long ans=0, mu=1, zi=0;
	int len = strlen(s);int dot=0;
	for (int i = 0;i < len;++i) {
		if (s[i] == '.'){
		    dot=i;break;
		}
	}
	for (int i = 0;i < dot;++i) {
		ans *= 3;
		if (s[i] == '1')ans++;
		if (s[i] == '2')ans--;
	}
	for (int j = dot+1;j < len;++j) {
		mu *= 3;zi *= 3;
		if (s[j] == '1')zi++;
		if (s[j] == '2')zi--;
	}
	if (zi < 0 && ans != 0) {
		zi += mu;
		ans--;
	}
	else if (zi > 0 && ans < 0) {
		ans++;zi = mu - zi;
	}
	else;
	long long m = mu / GCD(mu, zi);
	long long z = zi / GCD(mu, zi);
	if(ans==0)printf("%lld %lld", z, m);
	else printf("%lld %lld %lld", ans, z, m);
	//printf("%d",ans);
}
int main() {
	char s[31] ={'\0'};
	scanf("%s",s);
	//printf("%ld\n",strlen(s));
	if(strchr(s,'.')==0)solveInt(s);
	else solveDouble(s);
	return 0;
}