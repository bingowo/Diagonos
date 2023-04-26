#include <stdio.h>
#include <stdlib.h>
long long list[10000];

int cmp(const void *a,const void *b);
int number(long long x);

int main()
{
	int T,i,N,j;
	scanf("%d",&T);
	for(i=0;i<T;i++){
		scanf("%d",&N);
		for (j=0;j<N;j++){
			scanf("%lld",&list[j]);
		}
		printf("case #%d:\n",i);
		qsort(list,N,sizeof(long long),cmp);
		for (j=0;j<N-1;j++){
			printf("%lld ",list[j]);
		}
		printf("%lld\n",list[j]);
	}
	return 0;
}

int cmp(const void *a,const void *b)
{
	long long x,y;
	x=*(long long*)a;
	y=*(long long*)b;
	if (number(y)<number(x)){
		return -1;
	}
	else if (number(y)>number(x)){
		return 1;
		
	}
	else{
		if(x>y){
			return 1;
		}
		else{
			return -1;
		}
	}
}

int number(long long x)
{
	int cnt=0,i;
	for (i=0;i<64;i++){
		if (x&1==1){
			cnt+=1;
		}
		x=x>>1;
	}
	return cnt;
}