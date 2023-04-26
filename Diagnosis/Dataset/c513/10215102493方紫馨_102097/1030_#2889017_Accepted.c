#include<stdio.h>
#include<stdlib.h>
typedef struct{
	long long int n;
	int a;
}NUM;
int first_num(long long n){
	if(n<0)
		n=-n;
	while(n>=10){
		n/=10;
	}
	return n;
}
int cmp(const void* p1,const void* p2){
	NUM* a=(NUM*)p1;
	NUM* b=(NUM*)p2;
	if(a->a!=b->a)
		return b->a-a->a;
	if(a->n>b->n)
		return 1;
	return -1;
}
int main()
{
	int T,N;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		scanf("%d",&N);
		NUM num[N];
		//long long int num[10000]; 
		for(int j=0;j<N;j++){
			scanf("%lld",&num[j].n);
			num[j].a=first_num(num[j].n);
		}
		qsort(num,N,sizeof(NUM),cmp);
		printf("case #%d:\n",i);
		for(int j=0;j<N-1;j++){
			printf("%lld ",num[j].n);
		}
		printf("%lld\n",num[N-1].n);
		
	}
	return 0;
}