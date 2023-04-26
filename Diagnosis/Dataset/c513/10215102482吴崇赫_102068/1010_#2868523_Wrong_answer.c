#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
1.把给定数字从左到右每三个分成一组：012 345 67
2.把他们转成二进制，每三个数字转换成10位二进制：012 转成 0000001100，345 转成 0101011001；
3.末尾如果是一位或两位数字，则分别转换成4位或7位二进制，67 转成 1000011。
把上述二进制串起来 : 000000110001010110011000011。
4.把数字的个数转成二进制(10 bits) : 8的二进制是 0000001000
5.把数字编码的标志0001和第4步的编码加到前面 : 00010000001000000000110001010110011000011
*/

#define N 505 // max input string length
#define M 200

char* transtring(char* s) {
	int n = strlen(s);
	char* ret; ret = (char*)malloc(10);
	for (int i = 0;i < 10;++i)ret[i] = '\0';
	int a = atoi(s);
	
	if (n == 1) {
		int index = 3;
    	while (a) {
		ret[index--] = a % 2 + '0';
		a >>= 1;
	    }
	    for(int i=0;i<=index;++i)ret[i]='0';
	}
	else if (n == 2) {
	    int index = 6;
	    while (a) {
		ret[index--] = a % 2 + '0';
		a >>= 1;
	    }
	    for(int i=0;i<=index;++i)ret[i]='0';
	}
	else {
		int index = 9;
	    while (a) {
		ret[index--] = a % 2 + '0';
		a >>= 1;
	    }
	    for(int i=0;i<=index;++i)ret[i]='0';
	}
	return ret;
}

char* transint(int a) {
	char* ret; ret = (char*)malloc(10);
	for (int i = 0;i < 10;++i)ret[i] = '\0';
	int index = 9;
	while (a) {
		ret[index--] = a % 2 + '0';
		a >>= 1;
	}
	
	while (index > -1)ret[index--] = '0';
	return ret;
}

int main() {
	char input[N] = { '\0' };
	scanf("%s", input);
	int length = strlen(input);
	char temp[M][3];
	for (int i = 0;i < M;++i) {
		for (int j = 0;j < 3;++j)temp[i][j] = '\0';
	}
	int pi = 0;//pointer of input
	while (pi < length) {
		for (int i = 0;i < M;++i) {
			for (int j = 0;j < 3;++j)temp[i][j] = input[pi++];
		}
	}
	char ans[5005]={'\0'};
	ans[0] = ans[1] = ans[2] = '0';ans[3] = '1';
	strcat(ans, transint(length));
	
	for(int k=0;k<=(length-1)/3;++k){
	    strcat(ans,transtring(temp[k]));
	}
	
	printf("%s", ans);
	return 0;
}