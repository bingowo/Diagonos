#include<stdio.h>

int cmp(const void* _a , const void* _b); 
long int comp(long int n);
int main()
{
	int T;
	scanf("%d",&T);
	int N;
	int i,j;
	for(i=0;i<T;i++){
		scanf("%d",&N);
		long int *a = (long int *)malloc(sizeof(long int)*N);
		for (j=0;j<N;j++){
			scanf("%d",&a[j]);
		}
		qsort(a,N,sizeof(long int),cmp) 
		printf("case #%d:\n",i);
		for (j=0;j<N;j++){
			printf("%d",a[j]);
		}
		printf('\n');
	}
	
	return 0;
}

int cmp(const void* _a , const void* _b)
{
	long int *a = (long int *)_a;
	long int *b = (long int *)_b;
	long int temp1,temp2;
	int t,num1=0,num2=0;
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
	return (num2-num1);
}

long int comp(long int n)
{
	long int t=0;
	int i;
	for(i=0;i<64;i++){
		t=t<<1;
		t++;
	}
	n=n^t;
	n++;
	return n;
}