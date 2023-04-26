#include <stdio.h>
#include <stdlib.h>
#include <string.h>
unsigned char str[250];
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
				if(str[j] & 1 == 1)	num += 1;
				str[j] >>= 1;
			}
		}
		int total = l * 8;
		int g = gcd(total, num);
		if(num != 0)	printf("%d/%d\n", num/g, total/g);
		else	printf("0/1\n");
	}
	return 0;
}