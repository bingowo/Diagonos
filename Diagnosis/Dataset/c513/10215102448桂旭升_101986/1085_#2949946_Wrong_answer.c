#include <stdio.h>
#include<string.h>
#include<math.h>
char s1[501] = {'\0'};
char s2[501] = {'\0'};
int a[500];
int b[500];
int d[500];
int main(){
	int n, len1, len2, len, i, j;
	while(scanf("%s%s", &s1, &s2) != EOF){
		len1 = strlen(s1); len2 = strlen(s2);
		for(i = 0; i < len1; i++){
			a[i] = s1[i] - '0';
		}
		for(i = 0; i < len2; i++){
			b[i] = s2[i] - '0';
		}
		//printf("%d %d\n", a[0], b[0]);
		if(len1 == len2){
			for(i = 0; i < len1; i++){
				if(a[i] != b[i])break;
			}
			if(a[i] > b[i]){
				for(i = 0; i < len1; i++){
					d[i] = a[i] - b[i];
				}
			}
			else{
				for(i = 0; i < len1; i++){
					d[i] = b[i] - a[i];
				}
			}
		}
		else if(len1 > len2){
			for(i = 0; i < len1; i++){
				if(i < len1 - len2)d[i] = a[i];
				else d[i] = a[i] - b[i - len1 + len2];
			}
		}
		else{
			for(i = 0; i < len2; i++){
				if(i < len2 - len1)d[i] = b[i];
				else d[i] = b[i] - a[i - len2 + len1];
			}
		}//printf("%d\n", a[2]);
		len = len1 > len2? len1:len2;
		for(i = len-1; i >=1; i--){
			if(d[i] < 0){
				d[i] += 10; d[i-1]--;
			}
		}
		i = 0;
		while(d[i] == 0)i++;
		//printf("%d\n", i);
		for(; i < len; i++){
			printf("%d", d[i]);
		}
	}
	
	return 0;
}