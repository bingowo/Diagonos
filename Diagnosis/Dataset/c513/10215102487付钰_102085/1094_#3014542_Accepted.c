/*
	Created by Shizumu on 2022-03-21
	可以先把字符串适当的排序，然后再转化为大整数运算 
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 150

typedef struct{
	char n[LEN];
	int sgn;
}Number;

void stod(char s[], int d[])
{
	char *p = NULL;
	int idx = LEN - 1;
	for(p = s; *p; p ++);
	while(1){
		p --;
		if(*p != '-'){
			d[idx --] = *p - '0';
		}
		if(p == s || *p == '-'){
			break;
		}
	}
	
}

void sub(int a[], int b[])
{
	for(int idx = LEN - 1; idx; idx --){
		a[idx] -= b[idx];
		for(int k = idx; a[k] < 0; k --){
			a[k] += 10;
			a[k - 1] -= 1;
		}
	}
}

void add(int a[], int b[])
{
	for(int idx = LEN - 1; idx; idx --){
		a[idx] += b[idx];
		for(int k = idx; a[k] >= 10; k --){
			a[k] %= 10;
			a[k - 1] += 1;
		}
	}
}

int cmp(const void *a,const void *b)
{
    Number *pa=(Number*)a;
    Number *pb=(Number*)b;
    if(pa->sgn!=pb->sgn){
        return pb->sgn-pa->sgn;
    }
    else if(pa->sgn==1){
        if(strlen(pa->n)!=strlen(pb->n)){
           return strlen(pa->n)>strlen(pb->n)?-1:1;
           }
        else{
            return strcmp(pa->n, pb->n) * (-1);
        }
    }
    else{
		if(strlen(pa->n) != strlen(pb->n)){
			return strlen(pa->n) - strlen(pb->n);
		}else{
			return strcmp(pa->n, pb->n);
		}
	}

}

int main(void)
{
	int n;
	scanf("%d", &n);
	Number in[n];
	for(int i; i < n; i ++){
		scanf("%s", in[i].n);
		if(in[i].n[0] == '-'){
			in[i].sgn = -1;
		}else{
			in[i].sgn = 1;
		}
	}
	qsort(in, n, sizeof(in[0]), cmp);
	int max[LEN] = {0}, min[LEN] = {0};
	int res[LEN] = {0};
	stod(in[0].n, max), stod(in[n - 1].n, min);
	if(in[0].sgn == in[n - 1].sgn && in[0].sgn == 1){
		sub(max, min);
		memmove(res, max, sizeof(max));
	}else if(in[0].sgn == in[n - 1].sgn && in[0].sgn == -1){
		sub(min, max);
		memmove(res, min, sizeof(min));		
	}else{
		add(max, min);
		memmove(res, max, sizeof(max));
	}
	int idx;
	for(idx = 0 ; res[idx] == 0; idx ++);
	for( ; idx < LEN; idx ++){
		printf("%d", res[idx]);
	}
	
	return 0; 
}
