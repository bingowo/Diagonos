#include<stdio.h>
#include<stdlib.h>
int cmp(const void* _a , const void* _b)
{
	long long* a = (long long*)_a ;	
	long long* b = (long long*)_b ;
	int a_bit = 0 , b_bit = 0 ;
	long long tmp = *a ;
	while(tmp){
		tmp = tmp & (tmp-1) ;
		a_bit ++ ;
	}
	tmp = *b ;
	while(tmp){
		tmp = tmp & (tmp-1) ;
		b_bit ++ ;
	}
	if(a_bit == b_bit){
		return *a > *b ? 1 : -1 ;
	}
	else{
		return b_bit - a_bit > 0 ? 1 : -1 ;
	}
}
int main()
{
	int T=0;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		int N=0;
		scanf("%d",&N);
		long long n[N];
		for(int j=0;j<N;j++) scanf("%lld",&n[j]);
		qsort(n,N,sizeof(n[0]),cmp);
		for(int k=0;k<N;k++) printf("%lld ",n[k]);
	}
}