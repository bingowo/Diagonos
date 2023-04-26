#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char str[110];
int num[256];
long long data[110];
int main(){
	scanf("%s", &str);
	num['I'] = 1;
	num['V'] = 5;
	num['X'] = 10;
	num['L'] = 50;
	num['C'] = 100;
	num['D'] = 500;
	num['M'] = 1000;
	int i, l = strlen(str), cnt = 0;
	long long times = 1, ans = 0;
	for(i = 0; i < l; ++i){
		if(str[i] == '('){
			times *= 1000;
		}
		else if(str[i] == ')'){
			times /= 1000;
		}
		else{
			data[cnt++] = num[str[i]] * times;
		}
	}
	for(i = 0; i < cnt; ++i){
		if(data[i] < data[i+1])	ans -= data[i];
		else	ans += data[i];
	}
	printf("%lld", ans);
	return 0; 
}