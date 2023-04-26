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
		sum += s[i] - '0';
		if(s[i] - '0' == 9)flag = 1;
	}
	
	do{
		if(flag == 0){
			a[N-1]++; sum++;
			if(a[N-1] == 9){
				flag = 1;
			}
		}
		if(flag == 1){
			sum = 0; flag = 0;//printf("%d ", a[N-2]);
			for(i = len - 1; i >= 0; i--){
				if(a[i+N-len] == 9){
						a[i+N-len] = 0; a[i+N-len-1]++;
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