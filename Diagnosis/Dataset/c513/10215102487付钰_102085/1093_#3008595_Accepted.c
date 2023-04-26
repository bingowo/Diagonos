/*
	Created by Shizumu on 2022-03-21
	有点类似于1087的思路，找到不符合的那一位然后做加法
*/
#include <stdio.h>
#define LEN 110

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

int Scan9(int d[])
{
	int ret = -1;
	for(int i = 0 ; i < LEN; i ++){
		if(d[i] == 9){
			ret = i;
			break;
		}
	}

	return ret;
}

int Multi9(int d[])
{
	int sum = 0;
	for(int i = 0 ; i < LEN; i ++){
		sum += d[i];
	}
	return sum % 9 == 0;
}

void add(int d[], int n, int i)
{
	if(i < 0){
		i = LEN - 1;
	}
	d[i] += n;
	for(int k = i; d[k] >= 10; k --){//191->201 把9消除 因为有9肯定都不对
		d[k] %= 10;
		d[k- 1] += 1;
	}
	//加位后之后低位均为0保证最小  201->200
	for(int k = i;i != LEN - 1/*这个地方要保证最后一位加了后不要为0*/ &&  k < LEN; k ++){
		d[k] = 0;
	}


}

int main(void)
{
	char s[LEN];
	int d[LEN] = {0}, idx9, idx;
	scanf("%s", s);
	stod(s, d);
	idx9 = Scan9(d);
	do{
		add(d, 1, idx9);
	}while((idx9 = Scan9(d)) != -1 || Multi9(d));
	for(idx = 0 ; d[idx] == 0; idx ++);
	for(; idx < LEN; idx ++){
		printf("%d", d[idx]);
	}

	return 0;
}
