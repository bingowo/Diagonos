#include <stdio.h>
#include<string.h>
#include<ctype.h>
#define N 100

int main(){ 
	int a[N], len, sum = 0, flag = 0, i;
	char s[N];
	scanf("%s",s);
	len = strlen(s);
	for(i = len -1; i >= 0; i--){
		a[i+N-len] = s[i] - '0';
	}
	do{
		a[N-1]++;
		if(a[N-1] < 9)sum++;
		else if(a[N-1] == 9){
			sum++; flag = 1;
		}
		else{
			sum = 0; flag = 0; 
			for(i = len -1; i >= 0; i--){
				if(a[i+N-len] == 9)flag = 1;
				if(a[i+N-len] > 9){
					a[i+N-len-1]++; a[i+N-len] -= 10;
					if(i == 0){
						len++; sum++;
					}
				}
				sum += a[i+N-len];
			}
		}
	}
	while(flag != 0 || ((sum % 9) == 0));
	for(i = N - len; i < N; i++){
		printf("%d", a[i]);
	}
	return 0;
}