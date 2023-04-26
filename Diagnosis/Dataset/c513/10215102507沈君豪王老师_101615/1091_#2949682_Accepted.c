/*
	Created by Shizumu on 2022-03-21
	ÓÉÓÚ×Ô¼ºË®Æ½µÄÏÞÖÆ£¬Õâ¸öÌâÄ¿×öµÃÌ«¸´ÔÓÁË£¬²»¹»¼òµ¥£¬²»¹»ÓÅÑÅ¡£·´Õý×îºó´óÁ¦³öÆæ
¼£µ¹ÊÇ×ö³öÀ´ÁË£¬¶øÇÒÑ§µ½ÁËºÜ¶à¶«Î÷¡£²»µÃ²»¸Ð¿®»¹ÊÇÒª²©ÀÀÈºÊé²ÅÄÜºñ»ý±¡·¢°¡¡­¡­ 
	¶øÇÒÕâÃ´¶àÒ²ËãÊÇÐ´ÁËÒ»¸ö±È½ÏÍê±¸µÄ¸ß¾«¶È¼ÆËãµÄÄ£°å°É 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LEN 4000
//Ò»¸öNumber½á¹¹£¬Ò»²¿·ÖÊÇÊý£¬Ò»²¿·ÖÊÇ·ûºÅ 
typedef struct{
	int num[LEN];
	int sgn;
}Number;
//¶ÁÈ¡¸´Êý 
void ReadComplex(char s[], int *i, int *r);
//°ÑÕûÊý×ª»¯ÎªNumber 
Number* itod(int n);
//±È½ÏÁ½¸öNumberÀàÐÍµÄ´óÐ¡ 
int cmp(Number *a, Number *b);
//ÅÐ¶ÏNumberÊÇ·ñÎª0 
int is0(Number *a);
//ÅÐ¶ÏNumberÊÇ·ñÎª1 
int is1(Number *a);
//»ñµÃNumberÊýµÄ³¤¶È 
int GetLen(Number *a);
//Á½¸öNumberÏà¼Ó 
Number* add(Number *a, Number *b);
//Á½¸öNumberÏà¼õ 
Number* sub(Number *a, Number *b);
//Á½¸öNumberÏà³Ë 
Number *multi(Number *a, Number *b);
//¸´Êý³Ë·¨ 
void multicpx(Number *rel, Number *img, Number *orel, Number *oimg);
//´òÓ¡NumberÀàÐÍ 
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
// add()ºÍsub()ºÍ¼ä½ÓµÝ¹éµ÷ÓÃ£¨ÒòÎªÒª´¦ÀíÕýºÅºÍ¸ººÅ£© 
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
		//µ¹ÖÃÊäÈë 
		for(int i = 0 , idx = LEN - 1; i < lena; idx --, i++){
			ta[i] = a->num[idx];
		}
		for(int i = 0 , idx = LEN - 1; i < lenb; idx --, i++){
			tb[i] = b->num[idx];
		}		
		int lenc = lena + lenb, tc[lenc];
		memset(tc, 0, sizeof(tc));
		//Ä£ÄâÊÖËã³Ë·¨µÄ¹ý³Ì 
		for(int i = 0 ; i < lenb; i ++){
			for(int j = 0; j < lena; j ++){
				tc[i + j] += ta[j] * tb[i];
				tc[i + j + 1] += tc[i + j] / 10;
				tc[i + j] %= 10;
			}
		}
//		for(int i = 0 ; i < lenc; i ++){printf("%d", tc[i]);}
//		printf("\n");
		//µ¹ÖÃÊä³ö 
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
	//ÓÃÁËÌ«¶àmalloc()£¬±ØÐëÒªfree()£¬²»È»¾Í»áMemory limit exceeded 
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

