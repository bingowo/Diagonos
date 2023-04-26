#include <stdio.h>
#include <stdlib.h>
int Inter[1100], Fractional[1100], num[1100];
int main(){
	int i, a, b, leni = 0, lenf = 0, len = 0;
	scanf("%d%d", &a, &b);
	int la = a / b;
	while(la){
		Inter[leni++] = la % 3;
		la /= 3;
	}
	int flag = 0, lb = b, l = a % b;
	while(lb){
		if(flag){
			Fractional[lenf++] = l % 3;
		}
		else if(l % 3 != 0){
			flag = 1;
			Fractional[lenf++] = l % 3;
		}
		lb /= 3;
		l /= 3;
	}
	for(i = 0; i < lenf; ++i){
		num[len++] = Fractional[i];
	}
	for(i = 0; i < leni; ++i){
		num[len++] = Inter[i];
	}
	for(i = 0; i < len; ++i){
		num[i] += 1;
		num[i+1] += num[i] / 3;
		num[i] %= 3;
	}
	if(num[len] != 0){
		num[len] += 1;
		len ++;
	}
	for(i = 0; i < len; ++i){
		num[i] -= 1;
	}
	flag = 0;
	for(i = len - 1; i >= 0; --i){
		if(num[i] == -1)	printf("2");
		else{
			printf("%d", num[i]);
		}
		if(i == lenf && lenf != 0)	printf(".");
	}
	return 0;
}