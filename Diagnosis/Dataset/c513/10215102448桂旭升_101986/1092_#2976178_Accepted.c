#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string.h>
#define N 500
int a[N] = {0};
char s[1001] = {'\0'};
void f(int n){
	int i, len = 0, k;
	while(a[len] == 0)len++;
	for(k = N - 1; k >= len; k--){//printf("%d\n", k);
		a[k] *= n;
	}
	for(k = N - 1; k >= len; k--){
		if(a[k] > 9){
			a[k-1] += a[k] / 10;
			a[k] = a[k] % 10;
		}
	}
}
	
int main(){ 
	int i = 0, n, m, len, t, j, k;
	scanf("%s", &s); len = strlen(s);
	if(len == 1)printf("1");
	if(len == 2){
		if(s[0] == s[1])printf("1");
		else printf("4");
	}
	if(len > 2){
		if(s[0] == s[1])a[N-1] = 1;
		else a[N-1] = 2;
		if(s[len-1] == s[len-2])a[N-1] *= 1;
		else a[N-1] *= 2;
		for(i = 1; i < len -1; i++){
			if(s[i] == s[i-1] && s[i] == s[i+1]);
			else if(s[i] == s[i-1] || s[i] == s[i+1] || s[i-1] == s[i+1])f(2);
			else f(3);
		}
		i = 0;
		while(a[i] == 0)i++;
		for(; i < N; i++)printf("%d", a[i]);	
	}
	
	return 0;
}