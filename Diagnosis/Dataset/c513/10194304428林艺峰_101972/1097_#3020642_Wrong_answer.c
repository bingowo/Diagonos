#include<stdio.h>
#include<string.h>
char str[110], ans[210][110];
int min(int a, int b){
	return a < b ? a : b; 
}
int max(int a, int b){
	return a > b ? a : b;
}
int main(){
	while(scanf("%s", &str) != EOF){
		int l = strlen(str), pos = 100, len = 0, minn = 100, maxn = 100, i, j;
		ans[pos][len++] = str[0];
		for(i = 1; i < l; ++i){
			if(str[i] > str[i-1]){
				pos -= 1;
				ans[pos][len++] = str[i];
			}
			else if(str[i] < str[i-1]){
				pos += 1;
				ans[pos][len++] = str[i];
			}
			else{
				ans[pos][len++] = str[i];
			}
			for(j = 0; j < len; ++j)	if(ans[pos][j] == 0)	ans[pos][j] = ' ';
			minn = min(pos, minn);
			maxn = max(pos, maxn);
		}
		for(i = minn; i <= maxn; ++i){
			printf("%s\n", ans[i]);
		}
	}
    return 0;
}