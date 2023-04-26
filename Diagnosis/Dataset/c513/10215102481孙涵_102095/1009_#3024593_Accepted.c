#include <stdio.h>
#include <string.h>
/*
1.输入字符串
2.字符串的储存
3.计算总1和总位数
	计算总1:位运算
4.求最大公约数
5.输出 
*/
int gcd(int up, int down);

int main() {
	int T,t;
	scanf("%d",&T);
	getchar();
	for(t = 0; t < T; t++){
		//1.输入 2.储存 
		char s[121];
		gets(s);
		int up = 0;
		int down = 0;
		int j;
		//3.计算 
		for(j = 0; j < strlen(s); j++){
			unsigned char ch = s[j];
			while(ch != 0){
				up = up + (ch & 1);
				ch = ch >> 1; 
			}
			down += 8; 
		}
		//4.求最大公约数
		int gcdnum = gcd(up, down); 
		//5.输出	
		printf("%d/%d\n",up/gcdnum, down/gcdnum); 
	} 
}

int gcd(int up, int down){
	int temp;
	while(down != 0){
		temp = up % down;
		up = down;
		down = temp; 
	} 
	return up; 
} 