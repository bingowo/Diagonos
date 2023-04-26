#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef long long int lli;

typedef struct{
	char s[20];
	lli MinNum; 
}Str;

int ChangeIndex(char c)
{
	int ret;
	if(isdigit(c)){
		ret = c - '0';
	}else if(isupper(c)){
		ret = c - 'A' + 10;
	}else{
		ret = c - 'a' + 36;
	}
	
	return ret;
}

int cmp(const void *a, const void *b)
{
	Str *pa = (Str *)a;
	Str *pb = (Str *)b;
	if(pa->MinNum != pb->MinNum){
		return pa->MinNum > pb->MinNum ? 1 : -1;
	}else{
		return strcmp(pa->s, pb->s);
	}
}

lli Calculate(char s[])
{
	int isFind[62], CroNum[62];
	memset(isFind, -1, sizeof(isFind));
	memset(CroNum, -1, sizeof(CroNum));
	int len = strlen(s);
	for(int j = 0 ; j < len; j ++){
		isFind[j] = ChangeIndex(s[j]);
	}
	lli Number = 0, outNum = 0;
	for(int j = 0 ; j < len; j ++){
		if(CroNum[isFind[j]] == -1){
			if(j == 0){
				CroNum[isFind[j]] = 1;
			}else if(j != 0 && Number == 0){
				CroNum[isFind[j]] = Number;
				Number = 2;
			}else{
				CroNum[isFind[j]] = Number;
				Number ++;
			}
		}
	}
	if(Number == 0){
		Number = 2;
	}
	for(int j = 0 ; j < len ; j ++){
		outNum = outNum * Number + CroNum[isFind[j]];
	}
	return outNum;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	Str in[n];
	for(int i = 0 ; i < n ; i ++){
		scanf("%s", in[i].s);
		in[i].MinNum = Calculate(in[i].s);
	}
	qsort(in, n, sizeof(Str), cmp);
	for(int i = 0 ; i < n ; i ++){
		printf("%s\n", in[i].s);
	}
	return 0;
}