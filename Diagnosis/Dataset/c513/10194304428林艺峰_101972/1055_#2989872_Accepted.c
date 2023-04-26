#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int flag[260];
char str[1000010];
int max(int x, int y){
	return x > y ? x : y;
}
int main(){
	scanf("%s", &str);
	int i, l = strlen(str), left = 0, maxn = 0, pos = 0;
	for(i = 0; i <= 255; ++i)	flag[i] = -1;
	for(i = 0; i < l; ++i){
		if(flag[str[i]] != -1){
			left = max(left, flag[str[i]]+1);
		}
		flag[str[i]] = i;
		if(i - left + 1 > maxn){
			maxn = i - left + 1;
			pos = left;
		}
	}
	for(i = pos; i < pos + maxn; ++i){
		printf("%c", str[i]);
	}
	return 0;
}