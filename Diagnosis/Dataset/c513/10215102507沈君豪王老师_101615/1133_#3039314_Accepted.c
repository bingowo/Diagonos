#include <stdio.h>
#include <string.h>
#define N 100000

void anti(char s[])
{
	char *p = s;
	while(*p){
		if(*p == '0'){
			*p = '1';
		}else{
			*p = '0';
		}
		
		p ++;
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);
	char s1[N] = {'0'}, s2[N] = {'0'};
	char *res = NULL;
	if(n == 0){
		printf("%s", s1);
	}else{
		for(int i = 0 ;i < n; i ++){
			strcpy(s2, s1);
			anti(s1);
			strcat(s2, s1);
			strcpy(s1, s2);
		}
		printf("%s", s1);
	}
	
	return 0;
}