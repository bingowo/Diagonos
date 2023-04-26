#include <stdio.h>
#include<string.h>
#include<math.h>
char s[501] = {'\0'};
int main(){
	long long n, len, num = 1, i, j;
	char c;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%s", &s); len = strlen(s);
		printf("case #%d:\n", i);
		c = s[0];
		for(j = 1; j < len; j++){
			if(s[j] == c && num < 255)num++;
			else{
				printf("%d%c", num, c);
				c = s[j]; num = 1;
			}
		}
		
		printf("%d%c\n", num, c);
	}
	return 0;
}