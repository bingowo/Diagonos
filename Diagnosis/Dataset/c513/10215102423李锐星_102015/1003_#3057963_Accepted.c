#include <stdio.h>
#include <stdlib.h>

typedef struct{
	long long num;
	int sum;
}A;

A a[10000];

int cal(long long t)
{
	int s[64]={0};
	int i;
	for (i=0;i<64;i++){
		s[i]=t&1;
		t>>=1;
	} 
	int res=0;
	for (i=0;i<64;i++){
		if(s[i]==1){
			res++;
		}
	}
	return res;
}

int cmp(const void* a,const void* b)
{
	A x,y;
	x=*(A*)a;
	y=*(A*)b;
	if(x.sum>y.sum) return -1;
	if(x.sum<y.sum) return 1;
	if(x.num<y.num) return -1;
	return 1;
}

void solve()
{
	int N;
	scanf("%d",&N);
	int i;
	for (i=0;i<N;i++){
		scanf("%lld",&a[i].num);
		a[i].sum=cal(a[i].num);
	}
	qsort(a,N,sizeof(a[0]),cmp);
	for (i=0;i<N;i++){
		printf("%lld ",a[i].num);
	}
	printf("\n");
}

int main()
{
	int T;
	scanf("%d",&T);
	for (int i=0;i<T;i++){
		printf("case #%d:\n",i);
		solve();
	}
	return 0;
}