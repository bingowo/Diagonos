#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct N{
	int num[8], val;
}a[210];
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
		memset(a, 0, sizeof(a));
		memset(str, 0, sizeof(str));
		memset(str_num, 0, sizeof(str_num));
		memset(base, 0, sizeof(base));
		scanf("%s", &str);
		int l = strlen(str);
		for(j = 0; j < l; ++j){
			int len = 0;
			while(str[j]){
				str_num[(j+1)*8-1-len] = str[j] % 2;
				str[j] /= 2;
				len++;
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
				//printf("%d", str_num[j*6+k]);
			}
			base[j] = sum;
			//printf("%d\n", base[j]);
			//printf("\n");
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