#include <stdio.h>
#include <math.h>
#include <string.h>

int dp[10000];
int idx = 0;
void push_back(int n)
{
	dp[idx ++] = n;
}

int size(void){
	return idx;
}


int main(void)
{
	int n;
	scanf("%d", &n);
	int w[n], len = 0;
	for(int i = 0 ; i < n ; i ++){
		scanf("%d", &w[i]);
		len += w[i];
	}
	char s[len + 1];
	memset(s, 0, sizeof(s));
	for(int i = 0 ; i < n ; i ++){
		int lim_j = size();
		push_back(w[i]);
		for(int j = 0 ; j < lim_j; j ++){
			push_back(dp[j] + w[i]);
			push_back(abs(dp[j] - w[i]));
		}
	}
	for(int i = 0 ; i < size(); i ++){
		s[dp[i] - 1] = '1';
	}
	for(int i = 0 ; i < len; i ++){
		if(s[i] != '1'){
			s[i] = '0';
		}
	}
	printf("%s", s);
	
	
	return 0;
}