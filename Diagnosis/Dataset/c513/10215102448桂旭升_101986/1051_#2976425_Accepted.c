#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string.h>
#define N 200
char base64_chart[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="};
int a[N] = {0};

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
	int len, i, t, bits, ret, ch, pos, index, cur;
	char src[N] = {'\0'};
	char res[N] = {'\0'};
	scanf("%d", &t); 
	for(i = 0; i < t; i++){
		scanf("%s", &src);
		len = strlen(src);
		pos = 0; index = 0; bits = 0;
		ret = 0;
		while(index < len){ 
			ch = src[index];
			cur = (ret << (6 - bits)) + (ch >> (2 + bits));
			res[pos++] = base64_chart[cur];
			index++;
			bits += 2;
			ret = ch % (1 << bits);
			if(bits == 6){ 
				res[pos++] = base64_chart[ret];
				bits = 0;
				ret = 0;
			}
		}
		if(bits == 2) //最后一组只有1个字符
{
res[pos++] = base64_chart[ret << 4];
res[pos++] = '=';
res[pos++] = '=';
}
else if(bits == 4) //最后一组只有2个字符
{
res[pos++] = base64_chart[ret << 2];
res[pos++] = '=';
}
res[pos] = '\0';
printf("case #%d:\n", i);
printf("%s\n", res);
	}
	return 0;
}