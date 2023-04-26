#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char str[110];
int main(){
	scanf("%s", &str);
	int l = strlen(str), maxn = 0, len = 0, i, j;
	for(i = 0; i < l; ++i){
		if(a[i] >= '1' && a[i] <= '9'){
			len = 1;
			for(j = i + 1; j < l; ++j){
				if(a[j] >= '0' && a[j] <= '9')	len += 1;
				else	break;
			}
			if(len > maxn)	maxn = len;
		}
	}
	printf("%d", maxn);
	return 0;
}