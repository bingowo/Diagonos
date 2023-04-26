#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[210];
int cha[26];
int main(){
	int t, i, j, k;
	scanf("%d", &t);
	gets(s);
	for(i = 0; i < t; ++i){
		gets(s);
		for(j = 0; j < 26; ++j)	cha[j] = 0;
		for(j = 0; j < strlen(s); ++j)	if(s[j] >= 'A' && s[j] <= 'Z')	cha[s[j]-'A'] += 1;
		for(j = 0; j < strlen(s); ++j){
			if(s[j] >= 'A' && s[j] <= 'Z'){
				for(k = 0; k < 26; ++k){
					if(cha[k]){
						cha[k] -= 1;
						printf("%c", 'A'+k);
						break;
					}
				}
			}
			else	printf("%c", s[j]);
		}
		printf("\n");
	}
	return 0;
}