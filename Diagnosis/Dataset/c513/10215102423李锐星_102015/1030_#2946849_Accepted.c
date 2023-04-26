#include <stdio.h>
#include <stdlib.h>

int front(long long a)
{
	if(a<0){
		a=-a;
	}
	while(a>9){
		a=a/10;
	}
	return a;
}

int cmp(const void* a,const void* b)
{
	long long x,y;
	x=*(long long*)a;
	y=*(long long*)b;
	int pa,pb;
	pa=front(x);
	pb=front(y);
	if(pa<pb){
		return 1;
	}
	if(pa>pb){
		return -1;
	}
	else{
		if(x<y){
			return -1;
		}
		else{
			return 1;
		}
	}
}


int main()
{
	int T;
	scanf("%d",&T);
	int i;
	int N;
	long long num[10001];
	for (i=0;i<T;i++){
		scanf("%d",&N);
		int j;
		for(j=0;j<N;j++){
			scanf("%lld",&num[j]);
		}
		qsort(num,N,sizeof(num[0]),cmp);
		printf("case #%d:\n",i);
		for (j=0;j<N-1;j++){
			printf("%lld ",num[j]);
		}
		printf("%lld\n",num[j]);
	}
	return 0;
}