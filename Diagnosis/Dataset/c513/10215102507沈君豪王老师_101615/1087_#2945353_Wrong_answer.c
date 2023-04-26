#include <stdio.h>
#define LEN 110

void stod(char s[], int d[])
{
	char *p = NULL;
	int idx = LEN - 1;
	for( p = s; *p; p ++);
	while(1){
		p --;
		d[idx --] = *p - '0';
		if(p == s){
			break;
		}		
	}
}

void add(int d[], int n, int begin)
{
	d[begin] += n;
	for(int k = begin ; k && d[k] >= 10; k --){
		d[k] %= 10;
		d[k - 1] += 1;
	}
}

int isDiff(int d[])
{
	int idx, ret = -1;
	for(idx = 0 ; d[idx] == 0; idx ++);
	for(; idx < LEN; idx ++){
		if(d[idx] == d[idx - 1]){
			ret = idx;
			break;
		}
	}
	
	return ret;
}

int main(void)
{
	int t;
	scanf("%d", &t);
	for(int i = 0 ;i < t; i ++){
		char s[LEN];
		scanf("%s", s);
		int d[LEN] = {0,}, idx;
		stod(s, d);
		add(d, 1, LEN - 1);
		int k;
		while((k = isDiff(d)) != -1){
			add(d, 1, k);
//			for(idx = 0 ; d[idx] == 0; idx ++);
//			for( ; idx < LEN; idx ++){
//				printf("%d", d[idx]);
//			}
//			printf("\n");
		}
		printf("case #%d:\n", i);
		for(idx = 0 ; d[idx] == 0; idx ++);
		for( ; idx < LEN; idx ++){
			printf("%d", d[idx]);
		}
		printf("\n");
	}
	
	return 0;
}