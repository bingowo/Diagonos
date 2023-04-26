#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LEN 4000
//一个Number结构，一部分是数，一部分是符号 
typedef struct{
	int num[LEN];
	int sgn;
}Number;
//读取复数 
void ReadComplex(char s[], int *i, int *r);
//把整数转化为Number 
Number* itod(int n);
//比较两个Number类型的大小 
int cmp(Number *a, Number *b);
//判断Number是否为0 
int is0(Number *a);
//判断Number是否为1 
int is1(Number *a);
//获得Number数的长度 
int GetLen(Number *a);
//两个Number相加 
Number* add(Number *a, Number *b);
//两个Number相减 
Number* sub(Number *a, Number *b);
//两个Number相乘 
Number *multi(Number *a, Number *b);
//复数乘法 
void multicpx(Number *rel, Number *img, Number *orel, Number *oimg);
//打印Number类型 
void PrintNumber(Number *a);

int main(void)
{
	int n, timg, trel;
	char cpx[20];
	scanf("%s %d", cpx, &n);
	ReadComplex(cpx, &timg, &trel);
	Number *img, *rel, *oimg, *orel;
	img = itod(timg), rel = itod(trel);
	oimg = itod(timg), orel = itod(trel);
	if(n == 0){
		printf("1");
	}else{
		for(int i = 0; i < n - 1; i ++){
			multicpx(rel, img, orel, oimg);
//			PrintNumber(rel), printf(" "), PrintNumber(img), printf("\n");
		}
		if(!is0(rel)){ PrintNumber(rel);}
		if(!is0(img)){
			if(is1(img)){
				printf("%s", img->sgn == -1 ? "-" : "");
				if(!is0(rel) && img->sgn == 1){printf("+");}
				printf("i");
			}else{
				if(!is0(rel)){printf("%s", img->sgn == -1 ? "" : "+");}
				if(!is1(img)){PrintNumber(img);}
				printf("i");
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
int GetLen(Number *a)
{
	int ret = 0, idx;
	for(idx = 0 ; a->num[idx] == 0 ; idx ++);
	for(; idx < LEN ; idx ++){ ret ++;}
	return ret;
}
// add()和sub()和间接递归调用（因为要处理正号和负号） 
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

Number *multi(Number *a, Number *b)
{
	Number *ret;
	if(is0(a) || is0(b)){
		Number *temp = (Number*)malloc(sizeof(Number));
		memset(temp, 0, sizeof(Number));
		ret = temp;
		ret->sgn = 1;
	}else{
		ret = (Number*)malloc(sizeof(Number));
		memset(ret, 0, sizeof(Number));
		int lena = GetLen(a), lenb = GetLen(b);
		int ta[lena], tb[lenb], idx = 0;
		//倒置输入 
		for(int i = 0 , idx = LEN - 1; i < lena; idx --, i++){
			ta[i] = a->num[idx];
		}
		for(int i = 0 , idx = LEN - 1; i < lenb; idx --, i++){
			tb[i] = b->num[idx];
		}		
		int lenc = lena + lenb, tc[lenc];
		memset(tc, 0, sizeof(tc));
		//模拟手算乘法的过程 
		for(int i = 0 ; i < lenb; i ++){
			for(int j = 0; j < lena; j ++){
				tc[i + j] += ta[j] * tb[i];
				tc[i + j + 1] += tc[i + j] / 10;
				tc[i + j] %= 10;
			}
		}
//		for(int i = 0 ; i < lenc; i ++){printf("%d", tc[i]);}
//		printf("\n");
		//倒置输出 
		for(int i = 0, j = LEN - 1; i <  lenc ; i ++, j --){
			ret->num[j] = tc[i];
		}
		ret->sgn = a->sgn * b->sgn;		
	}

	return ret;
}

void multicpx(Number *rel, Number *img, Number *orel, Number *oimg)
{
	Number *t1, *t2;
	Number *ta, *tb, *tc, *td;
	ta = multi(rel, orel);
	tb = multi(img, oimg);
//	PrintNumber(ta), printf(" "), PrintNumber(tb), printf("\n");
	t1 = sub(ta, tb);
	tc = multi(img, orel), td = multi(rel, oimg);
	t2 = add(tc, td);
	memmove(rel, t1, sizeof(Number));
	memmove(img, t2, sizeof(Number));
	//用了太多malloc()，必须要free()，不然就会Memory limit exceeded 
	free(t1), free(t2);
	free(ta), free(tb), free(tc), free(td);
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

