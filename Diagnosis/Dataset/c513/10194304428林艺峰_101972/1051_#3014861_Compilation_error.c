#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char str[110], cha[64];
int str_num[1010], base[110];
int main(){
	int t, i, j, k;
	for(i = 0; i <= 25; ++i)	cha[i] = 'A' + i;
	for(i = 26; i <= 51; ++i)	cha[i] = 'a' + i - 26;
	for(i = 52; i <= 61; ++i)	cha[i] = '0' + i - 52;
	cha[62] = '+'; cha[63] = '/';
	scanf("%d", &t);
	for(i = 0; i < t; ++i){
		memset(str_num, 0, sizeof(str_num));
		memset(base, 0, sizeof(base));
		scanf("%s", &str);
		int l = strlen(str);
		for(j = 0; j < l; ++j){
			int len0 = 0, val = str[j];
			while(val){
				str_num[(j+1)*8-1-len] = val % 2;
				val /= 2;
				len0++;
			}
		}
		int len = 0;
		if((8 * l) % 6 != 0){
			len = (8 * l) / 6 + 1;
		}
		else{
			len = (8 * l) / 6;
		}
		for(j = 0; j < len; ++j){
			int sum = 0, mul = 1;
			for(k = 5; k >= 0; --k){
				sum += mul * str_num[j*6+k];
				mul *= 2;
			}
			base[j] = sum;
		}
		printf("case #%d:\n", i);
		for(j = 0; j < len; ++j){
			printf("%c", cha[base[j]]);
		}
		for(j = (4 - (len % 4)) % 4; j > 0; --j){
			printf("=");
		}
		printf("%\n");
	}
	return 0;
}