#include <stdio.h>
#include <string.h>
#include <math.h>

const int base64[64] = {
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 
	'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 
	'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 
	'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 
	'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 
	'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 
	'w', 'x', 'y', 'z', '0', '1', '2', '3',
	'4', '5', '6', '7', '8', '9', '+', '/',
};

void PrintBase64(char s[])
{
	char *p = s;
	int digit = ceil((strlen(s) * 8) / 6.0) * 6;
	int binary[digit], number = 0, temp, index;
	memset(binary, 0, sizeof(binary));
	//把每个字符转化为二进制layout 
	while(*p){
		number += 7;
		temp = *p;
		while(1){
			binary[number] = temp % 2;
			temp /= 2;
			if(number % 8 == 0){
				break;
			}
			number --;
		}
		number += 8;
		p ++;
	}
	index = 0, temp = 0 ;
	while(index < digit){
		temp = 0;
		while(1){
			temp = temp * 2 + binary[index];
			if(index % 6 == 5){
				break;
			}
			index ++;
		}
		printf("%c", base64[temp]);
		index += 1;
	}
	int left = ((24 - (digit % 24)) / 6) % 4;
	for(int i = 0 ; i < left ; i ++){
		printf("=");
	}
}

int main(void)
{
	int t;
	scanf("%d", &t);
	for(int i = 0 ; i < t; i ++){
		char s[120];
		scanf("%s", s);
		printf("case #%d:\n", i);
		PrintBase64(s);
		printf("\n");
	}
	
	return 0;
}