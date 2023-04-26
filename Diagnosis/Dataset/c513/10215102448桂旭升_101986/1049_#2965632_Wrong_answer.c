#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
char s[501];
char temp[501];
typedef struct {
	char *str;
}SHENG;

int cmp(const void *a, const void *b){
	SHENG *pa = (SHENG*)a, *pb = (SHENG*)b;
	return strcmp(pa ->str, pb -> str);
}

SHENG* Input(int n){
    SHENG *a = (SHENG*)malloc(sizeof(SHENG)*n);
    int i, j = 0, k = 0, len;//printf("%d\n", n);
    for(i = 0; i < n; i++){
    	k = 0;
		for(; j < strlen(s); j++){
			if(!isalpha(s[j]) && k != 0){
				temp[k] = '\0';
				a[i].str = (char*)malloc(sizeof(char)*strlen(temp));
				strcpy(a[i].str, temp);//printf("%s\n", temp);
				j++;
				break;
			}
			else
				if(isalpha(s[j]))temp[k++] = s[j];
		}
	}
    return a; 
}
int main()
{
	int t, i, j, n;
	scanf("%d", &t);gets(s);
	for(i = 0; i < t; i++){
		SHENG *A = NULL;
		gets(s); n = 0;
		for(j = 0; j < strlen(s); j++){
			if(!isalpha(s[j]) && isalpha(s[j-1]))n++;
		}
		if(n == 0)n++;
		if(n != 1){
			A = Input(n);
			qsort(A, n, sizeof(SHENG), cmp);
			printf("case #%d:\n", i);
			printf("%s", A[0].str);
			if(n != 1)printf(" ");
			for(j = 1; j < n; j++){
				if(strcmp(A[j].str, A[j-1].str) != 0){
					printf("%s", A[j].str);if(j != n-1)printf(" ");
				}
			}
		if(i != t-1)printf("\n");
		}
		else{
			printf("case #%d:\n", i);
			for(j = 0; j < strlen(s); j++){
				if(isalpha(s[j]))printf("%c", s[j]);
			}
		}
		free(A);
	} 
	
	
	
	return 0;
}