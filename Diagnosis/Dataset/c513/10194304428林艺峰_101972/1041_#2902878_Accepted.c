#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char str[60];
int main(){
	scanf("%s", &str);
	int l = strlen(str), i, j, len = 0, maxn = 1;
	for(i = 0; i < l; ++i){
		len = 1;
		for(j = i + 1; j < l; ++j){
			if(str[j] != str[j-1])	len += 1;
			else	break;
		}
		if(len > maxn)	maxn = len;
	}
	printf("%d", maxn);
	return 0;
}