#include <stdio.h>
#include <string.h>

const int primes[27] = {97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2,1};
const int LEN = 100;
/*
依旧采用秦九韶算法去解决，但是在细节上，由于自己的脑容量
不够，写得很罗嗦，把每次加法的乘法都开了一个新的数组去计
算来降低写高精度运算的难度 
*/ 

void ReadNumber(char s[], int num[])
{
	char *p = s;
	int temp = 0, index = 0;
	while(*p){
		if(*p == ','){
			num[index++] = temp;
			temp = 0;
		}else{
			temp = temp * 10 + (*p - '0');	
		}
		p ++;
	}
	num[index++] = temp;
	memmove(num + (26 - index), num, sizeof(int) * index);
	memset(num, -1, sizeof(int) * (26 - index));
}

void Addition(char s1[], char s2[], char res[])
{
	for(int i = LEN - 1; i >= 0 ; i --){
		res[i] = res[i] + s1[i] + s2[i] - 3 * '0';
		if(res[i] >= 10){
			res[i] -= 10;
			res[i - 1] += 1;
		}
		res[i] += '0';
	}
}

void Multiply(char s1[], char s2[], char res[])
{
	int len = 0;
	while(s2[len] == '0'){
		len ++;	
	}
	int temp;
	if(LEN - len == 2){
		char s21[LEN], s22[LEN];
		char res1[LEN], res2[LEN], s10[LEN];
		memset(s21, '0', sizeof(s21));
		memset(s22, '0', sizeof(s22));
		s21[LEN - 1] = s2[LEN - 1];
		s22[LEN - 1] = s2[LEN - 2];
		memset(res1, '0', sizeof(res1));
		memset(res2, '0', sizeof(res2));
		memmove(s10, s1 + 1, LEN - 1);
		s10[LEN - 1] = '0';
		Multiply(s1, s21, res1);
		Multiply(s10, s22, res2);
		Addition(res1, res2, res);
	}else if(LEN - len == 1){
		for(int i = LEN - 1; i >= 0; i --){
			temp = (s1[i] - '0') * (s2[LEN - 1] - '0');
			res[i] += temp % 10;
			if(temp >= 10){
				res[i - 1] += temp / 10;
			}
		}
	}
}

void Parallel(int n, char res[])
{
	for(int i = LEN - 1; i >= 0; i --){
		res[i] = n % 10 + '0';
		n /= 10;
	}
}

void PrimeToDec(int num[], char res[])
{
	char temp1[LEN], temp2[LEN], temp3[LEN], temp4[LEN];
	memset(temp2, '0', sizeof(temp2));
	memset(temp3, '0', sizeof(temp3));
	memset(temp4, '0', sizeof(temp4));
	Parallel(0, temp1);
	for(int i = 0 ; i < 26; i ++){
		if(num[i] != -1){
			Parallel(num[i], temp2);
			Addition(temp1, temp2, temp3);
			Parallel(primes[i + 1], temp4);
			memset(temp1, '0', sizeof(temp1));
			Multiply(temp3, temp4, temp1);
			memset(temp3, '0', sizeof(temp3));	
		}
	}
	int len = 0;
	while(temp1[len] == '0'){
		len ++;
	}
	memmove(res, temp1 + len, LEN - len);
	res[LEN - len] = '\0';
}

int main(void)
{
	char s[LEN], res[LEN];
	int num[26];
	memset(num, -1, sizeof(num));
	memset(res, '0', sizeof(res));
	scanf("%s", s);
	if(strcmp(s, "0") == 0){
		printf("0");
	}else{
		ReadNumber(s, num);
		PrimeToDec(num, res);
		printf("%s", res);		
	}
	return 0;
}