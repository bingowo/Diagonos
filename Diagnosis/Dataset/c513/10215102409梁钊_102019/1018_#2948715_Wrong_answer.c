#include<stdio.h>

#define N 40

void mul(int* p , int d)
{
	int carry = 0 ;
	int i ;
	for(i = N - 1; i > 0; i--)
		p[i] *= d ;
	for(i = N - 1; i > 0; i--){
		p[i-1] += p[i] / 10 ;
		p[i] %= 10 ;
	}
}

void add(int* res , int* p)
{
	int i ;
	for(i = N - 1; i > 0; i--){
		res[i] += p[i] ;
		res[i-1] += res[i] / 10 ;
		res[i] %= 10 ;
	}
}

int main()
{
	int Primenum[25] = {2,3,5,7,11,13,17,19,23,29,
	31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	int n[25] ; int i=0;
	while(scanf("%d",&n[i++]) != EOF && getchar() != '\n') ;
	int num = i ;
	int res[N] ={0} ;
	for(i = 0; i < num; i++){
		int p[N] = {0} ;
		p[N-1] = n[i] ;
		for(int j = 0; j < num - i -1; j++){
			mul(p,Primenum[j]) ;
		}
		add(res,p) ;
	}
	int* q = res ;
	while(*(++q) == 0) ;
	while(q < res + N) printf("%d",*(q++)) ;
}