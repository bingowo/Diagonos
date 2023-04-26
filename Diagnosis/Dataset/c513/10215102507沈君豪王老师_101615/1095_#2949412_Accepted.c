#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define LEN 8000
typedef struct{
	int num[LEN];
	int sgn;
}Number;
int cmp(Number *a, Number *b);
Number* add(Number *a, Number *b);
Number* sub(Number *a, Number *b);
void HexToBin(char s[], char bi[]);
int is0(Number *a);
int is1(Number *a);
void PrintNumber(Number *a);
const char *binary[16] = {	"0000", "0001", "0010", "0011",
							"0100", "0101", "0110", "0111",
							"1000", "1001", "1010", "1011",
							"1100", "1101", "1110", "1111"	};

int main(void)
{
	char s[LEN], bi[LEN] = {0};
	scanf("%s", s);
	HexToBin(s, bi);
	Number qr, qi;
	memset(&qr, 0, sizeof(Number)), memset(&qi, 0, sizeof(Number));
	qr.sgn = 1, qi.sgn = 1;
	Number *a, *b;
	for(int i = 0; bi[i]; i++){
		Number r, *t;
		memset(&r, 0, sizeof(Number));
		r.num[LEN - 1] = bi[i] - '0';
		r.sgn = 1;
		t = sub(&r, &qr);
		a = sub(t, &qi);
		b = sub(&qr, &qi);
		memmove(&qr, a, sizeof(Number));
		memmove(&qi, b, sizeof(Number));
		free(a), free(b), free(t);
	}
	if(is0(&qr) && is0(&qi)){
		printf("0");
	}else{
		if(!is0(&qr)){ PrintNumber(&qr);}
		if(!is0(&qi)){
			if(is1(&qi)){
				printf("%s", qi.sgn == -1 ? "-" : "");
				if(!is0(&qr) && qi.sgn == 1){printf("+");}
				printf("i");
			}else{
				if(!is0(&qr)){printf("%s", qi.sgn == -1 ? "" : "+");}
				if(!is1(&qi)){PrintNumber(&qi);}
				printf("i");
			}
		}		
	}

	return 0;
}


void HexToBin(char s[], char bi[])
{
	char *p = s;
	p += 2;
	int idx;
	while(*p){
		idx = (isdigit(*p) ? *p - '0' :  *p - 'A' + 10);
		strcat(bi, binary[idx]);
		p ++;
	}
}

int is0(Number *a)
{
	int ret = 1;
	for(int i = 0 ; i < LEN ; i ++){
		if(a->num[i] != 0){
			ret = 0;
			break;
		}
	}
	
	return ret;
}

int is1(Number *a)
{
	int ret = 1;
	for(int i = 0 ; i < LEN - 1; i ++){
		if(a->num[i] != 0){
			ret = 0;
			break;
		}
	}
	if(a->num[LEN - 1] != 1){
		ret = 0;
	}
	return ret;
}

int cmp(Number *a, Number *b)
{
	int ret = 0;
	for(int i = 0; i < LEN; i ++){
		if(a->num[i] > b->num[i]){
			ret = 1;
			break;
		}else if(a->num[i] < b->num[i]){
			ret = -1;
			break;
		}
	}
	
	return ret;
}

Number* add(Number *a, Number *b)
{
	Number* ret = NULL;
	if(a->sgn * b->sgn == 1){
		ret = (Number*)malloc(sizeof(Number));
		memset(ret, 0, sizeof(Number));
		for(int i = LEN - 1; i > 0 ; i --){
			ret->num[i] += a->num[i] + b->num[i];
			if(ret->num[i] >= 10){
				ret->num[i] %= 10;
				ret->num[i - 1] += 1;
			}
		}
		ret->sgn = a->sgn;
	}else{
		if(a->sgn == 1){
			Number temp;
			memmove(temp.num, b->num, sizeof(temp.num));
			temp.sgn = 1;
			ret = sub(a, &temp);
		}else if(b->sgn == 1){
			Number temp;
			memmove(temp.num, a->num, sizeof(temp.num));
			temp.sgn = 1;	
			ret = sub(b, &temp);
		}
	}
	return ret;
}

Number *sub(Number *a, Number *b)
{
	Number* ret = NULL;
	int c;
	if(a->sgn * b->sgn == 1){
		if((c = cmp(a, b)) == -1){
			ret = sub(b, a);
			ret->sgn = a->sgn * (-1);
		}else if(c == 1){
			ret = (Number*)malloc(sizeof(Number));
			memset(ret, 0, sizeof(Number));
			for(int i = LEN - 1; i > 0; i --){
				ret->num[i] = ret->num[i] + a->num[i] - b->num[i];
				if(ret->num[i] < 0){
					ret->num[i] += 10;
					ret->num[i - 1] -= 1;
				}
			}
			ret->sgn = a->sgn;
		}else{
			ret = (Number*)malloc(sizeof(Number));
			memset(ret, 0, sizeof(Number));
			ret->sgn = 1;
		}
	}else{
		if(a->sgn == 1){
			Number temp;
			memmove(temp.num, b->num, sizeof(temp.num));
			temp.sgn = 1;
			ret = add(a, &temp);			
			ret->sgn = 1;
		}else if(b->sgn == 1){
			Number temp;
			memmove(temp.num, a->num, sizeof(temp.num));
			temp.sgn = 1;
			ret = add(b, &temp);			
			ret->sgn = -1;
		}
	}
	
	return ret;
}

void PrintNumber(Number *a)
{
	if(is0(a)){
		printf("0");
	}else{
		if(a->sgn == -1){printf("-"); }
		int idx;
		for(idx = 0 ; a->num[idx] == 0 ; idx ++);
		for(; idx < LEN; idx ++){
			printf("%d", a->num[idx]);
		}
	}
}