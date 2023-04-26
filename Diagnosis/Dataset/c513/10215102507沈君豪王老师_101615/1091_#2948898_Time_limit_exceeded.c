#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LEN 4000
typedef struct{
	int num[LEN];
	int sgn;
}Number;
void ReadComplex(char s[], int *i, int *r);
void stod(char s[], Number *n);
Number* itod(int n);
int cmp(Number *a, Number *b);
int is0(Number *a);
int is1(Number *a);
Number* add(Number *a, Number *b);
Number* sub(Number *a, Number *b);
Number *multi(Number *a, int n);
//Number *fpow(Number *a, Number *b, int n);
void multicpx(Number *rel, int orel, Number *img, int oimg);
void PrintNumber(Number *a);


int main(void)
{
	int n, oimg, orel;
	char cpx[20];
	scanf("%s %d", cpx, &n);
	ReadComplex(cpx, &oimg, &orel);
	Number *img, *rel;
	img = itod(oimg), rel = itod(orel);
	if(n == 0){
		printf("1");
	}else{
		for(int i = 0; i < n - 1; i ++){
			multicpx(rel, orel, img, oimg);
		}
		if(!is0(rel)){ PrintNumber(rel);}
		if(!is0(img)){
			if(is1(img)){
				printf("%si", img->sgn == -1 ? "-" : "");
			}else{
				if(!is0(rel) && img->sgn == 1){ printf("+");}
				PrintNumber(img), printf("i");					
			}

		}
	}
	return 0;
}

void ReadComplex(char s[], int *i, int *r)
{
	char *p = s;
	*i = 0, *r = 0;
	int isMinus = 1, isPure = 1, isOne = 1, temp = 0;
	while(*p){
		if(*p && (*p == '+' || *p == '-')){
			isMinus = *p == '-' ? -1 : 1;
			p ++;
		}
		if(*p && isdigit(*p)){
			isOne = 0;
			while(*p && isdigit(*p)){
				temp = temp * 10 + (*p - '0');
				p ++;
			}
		}
		if(*p && *p == 'i'){
			if(isPure){ *r = 0;}
			if(isOne){
				*i = isMinus * 1;
			}else{
				*i = isMinus * temp;
			}
			break;
		}
		if(*p == '+' || *p == '-' || *p == '\0'){
			isPure = 0;
			*r = temp * isMinus;
			temp = 0, isMinus = 1, isOne = 1;
		}		
	}
}
Number* itod(int n)
{
	Number *ret = (Number *)malloc(sizeof(Number));
	memset(ret, 0, sizeof(Number));
	int idx = LEN - 1;
	ret->sgn = n < 0 ? -1 : 1;
	n = n < 0 ? -n : n;
	while(n){
		ret->num[idx --] = n % 10;
		n /= 10;
	}
	
	return ret;
}
void stod(char s[], Number *n)
{
	char *p = NULL;
	int idx = LEN - 1;
	for(p = s; *p; p ++);
	while(1){
		p --;
		if(*p != '-'){ n->num[idx--] = *p - '0';}
		if(p == s){ break;}
	}
	n->sgn = s[0] == '-' ? -1 : 1;
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

Number *multi(Number *a, int n)
{
	Number *temp = (Number*)malloc(sizeof(Number)), *ret;
	memmove(temp, a, sizeof(Number));
	int sgn = n > 0 ? 1 : -1;
	n = n < 0 ? -n : n;
	if(n == 0){
		memset(temp, 0, sizeof(Number));
		ret = temp;
		ret->sgn = 1;
	}else{
		for(int i = 0 ; i < n - 1; i ++){
			ret = temp;
			temp = add(temp, a);
			free(ret);
		}
		ret = temp;
		ret->sgn = sgn * a->sgn;		
	}

	return ret;
}

void multicpx(Number *rel, int orel, Number *img, int oimg)
{
	Number *t1, *t2;
	t1 = sub(multi(rel, orel), multi(img, oimg));
	t2 = add(multi(img, orel), multi(rel, oimg));
	memmove(rel, t1, sizeof(Number));
	memmove(img, t2, sizeof(Number));
	free(t1), free(t2);
}

//Number *fpow(Number *a, Number *b, int n)
//{
//	if(n == 1){
//		return 
//	}else{
//		if(n % 2 == 0){
//			return fpow(Number *a, Number *b, n / 2);
//		}else{
//			return fpow(Number *a, Number *b, n / 2- 1);
//		}
//	}
//}

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

