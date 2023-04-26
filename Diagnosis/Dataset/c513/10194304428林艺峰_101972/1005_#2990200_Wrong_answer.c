#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char str[60];
int main(){
	int t, i, j;
	scanf("%d", &t);
	for(i = 0; i < t; ++i){
		scanf("%s", &str);
		double ans = 0, k = 1.0 / 8.0;
		int l = strlen(str);
		for(j = 2; j < l; ++j){
			ans += (str[j] - '0') * k;
			k /= 8;
		}
		printf("case #%d:\n%0.45g\n", i, ans);
	}
	return 0;
}