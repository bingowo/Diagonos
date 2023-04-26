#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char str[110];
int ans[256];
int main(){
	int t, i, j, k;
	scanf("%d", &t);
	for(i = 0; i < t; ++i){
		scanf("%s", &str);
		memset(ans, 0, sizeof(ans));
		int l = strlen(str);
		for(j = 0; j < l; ++j){
			if(str[j] == '!'){
				for(k = 0; k < l; ++k){
					if((j - k) % 4 == 0 && str[k] != '!'){
						str[j] = str[k];
						ans[str[j]] += 1;
						break;
					}
				}
			}
		}
		printf("case #%d:\n%d %d %d %d\n", i, ans['R'], ans['B'], ans['Y'], ans['G']);
	}
}