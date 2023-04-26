#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main(){
	
	int i, n, len, len1, len2, j, min1 = -1, min2 = -1, max1 = -1, max2 = -1, k, max;
	char s1[81];
	char s2[81];
	char s[81];
	char temp[81];
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%s", &s1); len1 = strlen(s1);
		scanf("%s", &s2); len2 = strlen(s2);
		scanf("%s", &s); len = strlen(s);
		for(j = 0; j < len - len1 + 1; j++){
			for(k = 0; k < len1; k++){
				temp[k] = s[j+k];
			}
			temp[k] = '\0';
			if(strcmp(temp, s1) == 0){
				min1 = j; break;
			}
		}
		for(j = 0; j < len - len2 + 1; j++){
			for(k = 0; k < len2; k++){
				temp[k] = s[j+k];
			}
			temp[k] = '\0';
			if(strcmp(temp, s2) == 0){
				min2 = j; break;
			}
		}
		for(j = 0; j < len - len1 + 1; j++){
			for(k = 0; k < len1; k++){
				temp[k] = s[j+k];
			}
			temp[k] = '\0';
			if(strcmp(temp, s1) == 0){
				max1 = j;
			}
		}
		for(j = 0; j < len - len2 + 1; j++){
			for(k = 0; k < len2; k++){
				temp[k] = s[j+k];
			}
			temp[k] = '\0';
			if(strcmp(temp, s2) == 0){
				max2 = j;
			}
		}
		//printf("%d %d %d\n", len1, len2, len);
		//printf("%d %d %d %d\n", min1, min2, max1, max2);
		max = max2 - (min1+len1);
		if((max1 - (min2+len2))>max)max = (max1 - (min2+len2));
		if(max < 0)max = 0;
		printf("case #%d:\n", i);
		printf("%d", max);
		if(i != n-1)printf("\n");
	}
	return 0;
} 