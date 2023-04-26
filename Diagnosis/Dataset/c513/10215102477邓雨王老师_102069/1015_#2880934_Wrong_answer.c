#include<stdio.h>
#include<string.h>
const int primes[26] = {97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
void Readnumber(char s[], int num[])
{
	char *p = s;
	int temp = 0, index = 0;
	while(*p!=0){
		if(*p == ','){
			num[index++] = temp;
			temp = 0;
		}else{
			temp = temp * 10 + (*p - '0');	
		}
		p ++;
	}
	num[index++] = temp;
}
void ADD(int num1[], int num2[], int sum[])
{
	int i;
	for(i = 25; num1[i] != -1 || num2[i] != -1 || sum[i] != -1; i --){
		if(num1[i] == -1){
			num1[i] = 0;
		}
		if(num2[i] == -1){
			num2[i] = 0;
		}
		if(sum[i] == -1){
			sum[i] = 0;
		}
		sum[i] = num1[i] + num2[i] + sum[i];
		if(sum[i] >= primes[i]){
			sum[i] -= primes[i];
			sum[i - 1] = 1;
		}
	}
}
void output(int s[])
{
	int i;
	for(i = 0 ; i < 26 ; i ++){
		if(s[i] != -1){
			printf("%d%c", s[i], i == 25 ? '\n' : ',');
		}
	}
}
int main(void)
{
	int t;
	scanf("%d", &t);
	int i;
	for(i = 0 ;i < t; i ++){
		char s1[100], s2[100];
		int num1[26], num2[26], sum[26];
		memset(num1, -1, sizeof(sum));
		memset(num2, -1, sizeof(sum));
		memset(sum, -1, sizeof(sum));
		//用-1作为标识符，便于控制循环。 
		scanf("%s %s", s1, s2);
		Readnumber(s1, num1);
		Readnumber(s2, num2);
		ADD(num1, num2, sum);
		printf("case #%d:\n", i);
		output(sum);
	}
	
	return 0;
}
