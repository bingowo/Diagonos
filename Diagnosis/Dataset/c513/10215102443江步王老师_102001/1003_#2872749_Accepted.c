#include<stdio.h>
#include<stdlib.h>


int cmp(const void* _a , const void* _b); 
long long int comp(long long int n);
int count(long long int n);
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
	long long int a = *((long long int *)_a);
	long long int b = *((long long int *)_b);
	long long int temp,temp1=a,temp2=b;
	long long int num1=0,num2=0,num=0;
	long long int t=1;
    while (num<64){
        temp=a&t;
        if (temp)
            num1++;
        t=t<<1;
        num++;
    }
    num=0;
    t=1;
    while (num<64){
        temp=b&t;
        if (temp)
            num2++;
        t=t<<1;
        num++;
    }
    /*temp1=comp(*a);
    printf("temp1=%lld\n",temp1);
	temp2=comp(*b);
    printf("temp2=%lld\n",temp2);
	num1=count(temp1);
    printf("num1=%lld\n",num1);
    num2=count(temp2);
	while(temp2>0){
		t=temp2&1;
		num2=num2+t;
		temp2=temp2>>1;
	}
    printf("num2=%lld\n",num2);
	*/
    if (num2 != num1)
	    return (num2-num1);
	else{
	    if(temp2<temp1)
	        return 1;
	    else
	        return -1;
	}
    

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
int count(long long int n)
{
    int i;
    long long int t=1;
    int num=0;
    for (i=0;i<64;i++){
        if (n&t)
            num++;
        t=t<<1;
    }
    return num;
}