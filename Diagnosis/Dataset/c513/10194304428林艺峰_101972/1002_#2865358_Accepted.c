#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
int sum[70];
int main(){
	int t, i, j, k, n, flag = 0;
	char str[70];
	scanf("%d", &t);
	for(i = 0; i < t; ++i){
		scanf("%s", &str);
		int l = strlen(str), num = 0;
		long long ans = 0;
		for(j = 0; j < 70; ++j)	sum[j] = 0;
		for(j = 0; j < l; ++j){
			flag = 0;
			for(k = j - 1; k >= 0; --k)	if(str[j] == str[k])	flag = 1;
			if(!flag)	num += 1;
		}
		if(num == 1)	num = 2;
		n = 0;
		for(j = 0; j < l; ++j){
			if(j == 0)	sum[j] = 1;
			else{
				flag = 0;
				for(k = j - 1; k >= 0; --k){
					if(str[j] == str[k]){
						flag = 1;
						sum[j] = sum[k];
					}
				}
				if(!flag){
					if(n != 0)	sum[j] = n++;
					else if(n == 0){
						sum[j] = n;
						n = 2;
					}
				}
			}
		}
		long long c = 1;
		for(j = l - 1; j >= 0; --j){
			ans += sum[j] * c;
			c *= num;
		}
		printf("case #%d:\n%lld\n", i, ans);
	}
	return 0;
}