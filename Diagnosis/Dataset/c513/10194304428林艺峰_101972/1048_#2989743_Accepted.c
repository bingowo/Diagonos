#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a[60], b[60], c[110];
char str1[110], str2[110];
int main(){
	while(scanf("%s%s", &str1, &str2) != EOF){
		int i, j, l1 = strlen(str1), l2 = strlen(str2), pos1 = 0, pos2 = 0, h1 = 0, h2 = 0;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		for(i = 0; i < l1; ++i){
			if(str1[i] == 'x'){
				if(str1[i+1] == '^'){
					if(atoi(str1 + pos1) != 0){
						a[atoi(str1 + i + 2)] = atoi(str1 + pos1);
					}
					else{
						if(str1[i-1] == '-')	a[atoi(str1 + i + 2)] = -1;
						else	a[atoi(str1 + i + 2)] = 1;
					}
					if(atoi(str1 + i + 2) >= 10)	pos1 = i + 4;
					else	pos1 = i + 3;
					if(h1 == 0)	h1 = atoi(str1 + i + 2);
				}
				else{
					if(atoi(str1 + pos1) != 0){
						a[1] = atoi(str1 + pos1);
					}
					else{
						if(str1[i-1] == '-')	a[1] = -1;
						else	a[1] = 1;
					}
					pos1 = i + 1;
					if(h1 == 0)	h1 = 1;
				}
			}
		}
		a[0] = atoi(str1 + pos1);
		for(i = 0; i < l2; ++i){
			if(str2[i] == 'x'){
				if(str2[i+1] == '^'){
					if(atoi(str2 + pos2) != 0){
						b[atoi(str2 + i + 2)] = atoi(str2 + pos2);
					}
					else{
						if(str2[i-1] == '-')	b[atoi(str2 + i + 2)] = -1;
						else	b[atoi(str2 + i + 2)] = 1;
					}
					if(atoi(str1 + i + 2) >= 10)	pos2 = i + 4;
					else	pos2 = i + 3;
					if(h2 == 0)	h2 = atoi(str2 + i + 2);
				}
				else{
					if(atoi(str2 + pos2) != 0){
						b[1] = atoi(str2 + pos2);
					}
					else{
						if(str2[i-1] == '-')	b[1] = -1;
						else	b[1] = 1;
					}
					pos2 = i + 1;
					if(h2 == 0)	h2 = 1;
				}
			}
		}
		b[0] = atoi(str2 + pos2);
/*		for(i = h1; i >= 0; --i)	printf("%d ", a[i]);
		printf("\n");
		for(i = h2; i >= 0; --i)	printf("%d ", b[i]);
		printf("\n");*/
		for(i = h1; i >= 0; --i){
			for(j = h2; j >= 0; --j){
				c[i+j] += a[i] * b[j];
			}
		}
		for(i = h1 + h2; i >= 0; --i){
			if(c[i])	printf("%d ", c[i]);
		}
		printf("\n");
	}
	return 0;
}