#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef long long int lli;
typedef struct CNode* Complex;

struct CNode{
	lli rel;
	lli img;
};

Complex CreateComplex(lli rel, lli img)
{
	Complex temp = (Complex)malloc(sizeof(struct CNode));
	temp->rel = rel;
	temp->img = img;
	
	return temp;
}

lli llabs(lli x)
{
	return x > 0? x : -x;
}

void PrintComplex(Complex c)
{
	if(c->rel != 0){
		if(c->rel < 0){
			printf("-");
		}
		printf("%lld", llabs(c->rel));
	}else if(c->img == 0){
		printf("0");
	}
	if(c->img != 0){
		if(c->img < 0){
			printf("-");
		}else if(c->img > 0 && c->rel != 0){
			printf("+");
		}
		if(c->img != 1 && c->img != -1){
			printf("%lld", llabs(c->img));
		}
		printf("i\n");
	}
}

void HexToBin(char s[], char b[])
{
	int len = strlen(s);
	int digit = 0, index = 3, count = 0;
	for(int i = 0 ; i < len ; i ++){
		if(isdigit(s[i])){
			digit = s[i] - '0';
		}else{
			digit = s[i] - 'A' + 10;
		}
		if(digit == 0){
			for(int j = 0 ; j < 4; j ++){
				b[index--] = '0';
				count ++;
			}
		}else{
			while(digit > 0 || count % 4 != 0){
				if(digit > 0){
					b[index --] = digit % 2 + '0';
					digit /= 2;
				}else{
					b[index--] = '0';
				}
				count ++;
			}			
		}
		index += 8;
	}
	b[index - 3] = '\0';
}

int main(void)
{
	char s[40], bi[160];
	scanf("%s", s);
	int len = strlen(s);
	memmove(s, s + 2, len - 1);
	HexToBin(s, bi);
	lli qr = 0, qi = 0, a, b;
	for(int i = 0; bi[i]; i ++){
		lli remainder = bi[i] - '0';
		a = -qr - qi + remainder;
		b = qr - qi;
		qr = a;
		qi = b;
	}
	Complex out = CreateComplex(a, b);
	PrintComplex(out);
	
}