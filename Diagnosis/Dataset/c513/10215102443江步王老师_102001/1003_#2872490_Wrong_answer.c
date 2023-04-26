#include<stdio.h>
#include<stdlib.h>

int cmp(const void* _a , const void* _b); 
long long int comp(long long int n);
int main()
{
	int T;
	scanf("%d",&T);
	int N;
	int i,j;
	for(i=0;i<T;i++){
		scanf("%d",&N);
		long long int *a = (long long int *)malloc(sizeof(long long int)*N);
		for (j=0;j<N;j++){
			scanf("%lld",&a[j]);
		}
		qsort(a,N,sizeof(long long int),cmp) ;
		printf("case #%d:\n",i);
		for (j=0;j<N;j++){
			printf("%lld ",a[j]);
		}
		putchar('\n');
		free(a);
	}
	
	return 0;
}

int cmp(const void* _a , const void* _b)
{
	long long int *a = (long long int *)_a;
	long long int *b = (long long int *)_b;
	long long int temp1,temp2;
	long long int t,num1=0,num2=0;
	temp1=comp(*a);
	temp2=comp(*b);
	while(temp1>0){
		t=temp1&1;
		num1=num1+t;
		temp1=temp1>>1;
	}
	while(temp2>0){
		t=temp2&1;
		num2=num2+t;
		temp2=temp2>>1;
	}
	if (num2 != num1)
	    return (num2-num1);
	else if(num2 == num1 && b<a)
	    return 1;
	else
	    return -1;
}

long long int comp(long long int n)
{
	long long int t=0;
	int i;
	for(i=0;i<64;i++){
		t=t<<1;
		t++;
	}
	n=n^t;
	n++;
	return n;
}