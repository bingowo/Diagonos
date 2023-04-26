#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
int GCD(int m, int n) {
	return m % n ? n : GCD(n, m % n);
}
//无小数
void solveInt(char* s) {
	int ans = 0;
	int len = strlen(s);
	for (int i = 0;i < len;++i) {
		ans *= 3;
		if (s[i] == '1')ans ++;
		if (s[i] == '0')ans += 0;
		if (s[i] == '2')ans--;
	}
	printf("%d", ans);
}

void solveDouble(char* s) {
	int ans=0, mu=1, zi=0;
	int len = strlen(s);int dot;
	for (int i = 0;i < len;++i) {
		if (s[i] == '.')dot = i;
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
	int m = mu / GCD(mu, zi);
	int z = zi / GCD(mu, zi);
	if(ans==0)printf("%d %d", zi, mu);
	else printf("%d %d %d", ans, zi, mu);
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