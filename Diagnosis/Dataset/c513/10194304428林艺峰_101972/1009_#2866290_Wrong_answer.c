#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char str[150];
int gcd(int x, int y){
	if(y > x){
		int c = x;
		x = y;
		y = c;
	}
	if(y == 0)	return x;
	return gcd(y, x % y);
}
int main(){
	int n, i, j;
	scanf("%d", &n);
	gets(str);
	for(i = 0; i < n; ++i){
		gets(str);
		int l = strlen(str), num = 0;
		for(j = 0; j < l; ++j){
			while(str[j]){
				if(str[j]%2 == 1)	num += 1;
				str[j] /= 2;
			}
		}
		int total = l * 8;
		int g = gcd(total, num);
		printf("%d/%d", num/g, total/g);
	}
	return 0;
}