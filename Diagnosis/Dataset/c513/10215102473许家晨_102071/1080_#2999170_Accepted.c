
#include <stdio.h>
#include <string.h>
#define LEN 150

void stod(char s[], int d[])
{
	char *p = NULL;
	int idx = LEN - 1;
	for(p = s; *p; p ++);
	while(1){
		p --;
		d[idx --] = *p - '0';
		if(p == s){
			break;
		}
	}
}

int isZero(int d[])
{
	int ret = 1;
	for(int i = 0 ; i < LEN; i ++){
		if(d[i] != 0){
			ret = 0;
			break;
		}
	}
	
	return ret;
}

void add(int a[], int b[])
{
	for(int i = LEN - 1; i ; i --){
		a[i] += b[i];
		for(int k = i ; a[k] >= 10; k --){
			a[k] %= 10;
			a[k - 1] += 1;
		}
	}
}

void multi(int a[], int n)
{
	int temp[LEN];
	memmove(temp, a, sizeof(temp));
 
	for(int i = 1 ; i < n ; i ++){
		add(a, temp);
	}
}

int div(int d[], int n)
{
	int idx, temp = 0;
	int res[LEN] = {0};
	for(idx= 0 ; d[idx] == 0; idx++);
	for( ; idx < LEN; idx ++){
		res[idx] = (temp * 10 + d[idx]) / n;
		temp = (temp * 10 + d[idx]) % n;
	}
	memmove(d, res, sizeof(res));
	return temp;	//返回的是最后的余数 
}

int main(void)
{
	int t;
	scanf("%d", &t);
	for(int i = 0 ; i < t; i ++){
		char s[LEN];
		int d[LEN] = {0}, bd[LEN * 3] = {0}, res[LEN] = {0};
		int idx = 0, plus[LEN] = {0}, cnt = 0;
		scanf("%s", s);
		stod(s, d);
		if(isZero(d)){
			printf("case #%d:\n", i);
			printf("0\n");
		}else{
			while(!isZero(d)){
				bd[idx ++] = div(d, 2);
				cnt ++;
			}
			for(idx = 0 ; idx < cnt; idx ++){
				multi(res, 2);
				plus[LEN - 1] = bd[idx];
				add(res, plus);
			}
			printf("case #%d:\n", i);
			for(idx = 0 ; res[idx] == 0; idx++);
			for(; idx < LEN; idx++){
				printf("%d", res[idx]);
			}
			printf("\n");			
		}
	}
	
	return 0;
}