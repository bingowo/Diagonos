#include <stdio.h>
#include <stdlib.h>
int Inter[1100], Fractional[1100], num[1100];
int main(){
	int i, a, b, leni = 0, lenf = 0, len = 0;
	scanf("%d%d", &a, &b);
	int flag = 0, la = a / b, lb = b, l = a % b;
	while(lb != 1){
		if(flag){
			num[len++] = l % 3;
		}
		else if(l % 3 != 0){
			flag = 1;
			num[len++] = l % 3;
		}
		lb /= 3;
		l /= 3;
	}
	int point = len - 1;
	while(la){
		num[len++] = la % 3;
		la /= 3;
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
	for(i = len - 1; i >= 0; --i){
		if(i == point && point != 0)	printf(".");
		if(num[i] == -1)	printf("2");
		else{
			printf("%d", num[i]);
		}
	}
	return 0;
}