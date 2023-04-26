/*
	Created by Shizumu on 2022-03-21
	这个题目不可能一点点+1，所以想办法提高效率 
*/
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

void add(int d[], int n, int begin/*这个参数确定n加在d的哪一位*/)
{
	d[begin] += n;
	for(int k = begin ; k && d[k] >= 10; k --){
		d[k] %= 10;
		d[k - 1] += 1;
	}
}

void setZero(int d[], int k)
{
	for(int i = k + 1; i < LEN; i ++){
		d[i] = 0;
	}
}
//这个函数一是判断数字相同的情况，二是要返回最左边（左边是高位）的俩相同数位的靠右的那一个 
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
		if(isDiff(d) == -1){
			add(d, 1, LEN - 1);
		}
		int k;
		while((k = isDiff(d)) != -1){
			add(d, 1, k);
			// 在某个数位加1后，为了让整个数字最小，其后的所有位应当为0 
			setZero(d, k);
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
