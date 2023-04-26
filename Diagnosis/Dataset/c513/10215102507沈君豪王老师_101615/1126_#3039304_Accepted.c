#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

typedef unsigned long long int llu;

typedef struct{
	llu n;
	char s[100];
	char sn[100];
}Num;

void itob(llu n, char s[], int b)
{
	int i;
	for(i = 98 ; i && n; n/= b){
		s[i--] = n % b + '0';
	}
	memmove(s, s + i + 1, 98 - i);
	s[98 - i] = '\0';
}

void BigIntSum(char s1[], char s2[], char s[])
{
	size_t len1 = strlen(s1), len2 = strlen(s2);
	for(int i = 0 ; i < 100; i ++){
		s[i] = 0;
	}
	if(len2 < len1){
		memmove(s2 + (len1 - len2), s2, len2 + 1);
		for(int i = 0 ; i < len1 - len2; i ++){
			s2[i] = '0';
		}
		len2 = len1;
	}else if(len2 > len1){
		memmove(s1 + (len2 - len1), s1, len1 + 1);
		for(int i = 0 ; i < len2 - len1; i ++){
			s1[i] = '0';
		}
		len1 = len2;		
	}
	for(int i = len1 - 1 ; i >= 0 ; i --){
		if(s[i + 1] == 0){
			s[i + 1] = (s1[i] - '0') + (s2[i] - '0');
			if(s[i + 1] >= 10){
				s[i + 1] -= 10;
				s[i] = '1';
			}
			s[i + 1] += '0';
		}else{
			s[i + 1] = (s1[i] - '0') + (s2[i] - '0') + (s[i + 1] - '0');
			if(s[i + 1] >= 10){
				s[i + 1] -= 10;
				s[i] = '1';
			}
			s[i + 1] += '0';			
		}
	}
	if(s[0] == 0){
		memmove(s, s + 1, len1 + 1);
	}
}

void sum(char s1[], char s2[], char s[])
{
	size_t len1 = strlen(s1), len2 = strlen(s2);
	if(len2 < len1){
		memmove(s2 + (len1 - len2), s2, len2 + 1);
		for(int i = 0 ; i < len1 - len2; i ++){
			s2[i] = '0';
		}
		len2 = len1;
	}else if(len2 > len1){
		memmove(s1 + (len2 - len1), s1, len1 + 1);
		for(int i = 0 ; i < len2 - len1; i ++){
			s1[i] = '0';
		}
		len1 = len2;		
	}
	for(int i = 0 ; i < len1; i ++){
		if(s1[i] == '0' && s2[i] == '0'){
			s[i] = '0';
		}else if(s1[i] == '1' && s2[i] == '1'){
			s[i] = '0';
		}else{
			s[i] = '1';
		}
	}
	s[len1] = '\0';
}

int cmp(const void *a, const void *b)
{
	Num *pa = (Num *)a;
	Num *pb = (Num *)b;
	return pa->n > pb->n ? 1 : -1;
}

int isZero(char s[])
{
	int ret = 1;
	char *p = s;
	while(*p){
		if(*p != '0'){
			ret = 0;
			break;
		}
		p ++;
	}
	
	return ret;
}



int main(void)
{
	int n;
	scanf("%d", &n);
	Num in[n];
	for(int i = 0 ; i < n ; i ++){
		scanf("%llu", &in[i].n);
		itob(in[i].n, in[i].s, 2);
		itob(in[i].n, in[i].sn, 10);
	}
	char s[100], temp[100];
	char res[100];
	sum(in[0].s, in[1].s, s);
	if(n == 2){
		if(isZero(s)){
			if(in[0].n > in[1].n){
				printf("%llu", in[0].n);
			}else{
				printf("%llu", in[1].n);
			}
		}else{
			printf("-1");
		}
	}else{
		for(int i = 2 ; i < n ; i ++){
			strcpy(temp, s);
			sum(in[i].s, temp, s);
		}
		if(isZero(s)){
			memset(temp, 0, sizeof(temp));
			qsort(in, n, sizeof(Num), cmp);
			BigIntSum(in[1].sn, in[2].sn, res);
			for(int i = 3; i < n ; i ++){
				strcpy(temp, res);
				BigIntSum(in[i].sn, temp, res);
			}
			printf("%s", res);				
		}else{
			printf("-1");
		}
	}
	
	return 0;
}