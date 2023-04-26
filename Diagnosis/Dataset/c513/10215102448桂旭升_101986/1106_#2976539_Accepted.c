#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string.h>
#define N 1000000007
char s[1001] = {'\0'};
	
int main(){ 
	int i = 0, n, m, len, t, j, k;
	long long a;
	scanf("%s", &s); len = strlen(s);
	if(len == 1)printf("1");
	if(len == 2){
		if(s[0] == s[1])printf("1");
		else printf("4");
	}
	if(len > 2){
		if(s[0] == s[1])a = 1;
		else a = 2;
		if(s[len-1] == s[len-2])a *= 1;
		else a *= 2;//printf("%d\n", len);
		for(i = 1; i < len -1; i++){
			if(s[i] == s[i-1] && s[i] == s[i+1]);
			else if(s[i] == s[i-1] || s[i] == s[i+1] || s[i-1] == s[i+1])a = a*2 % N;
			else a = a*3 % N;
		}
		printf("%lld", a);	
	}
	return 0;
}