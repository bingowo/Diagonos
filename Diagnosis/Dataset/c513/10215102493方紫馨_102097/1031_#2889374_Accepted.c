#include<stdio.h>
#include<stdlib.h>
int cmp_up(const void* p1,const void* p2){
	int a=*((int*)p1);
	int b=*((int*)p2);
	return a-b;
}
int cmp_down(const void* p1,const void* p2){
	int a=*((int*)p1);
	int b=*((int*)p2);
	return b-a;
}
int main()
{
	int T,N;
	scanf("%d",&T);
	
	for(int i=0;i<T;i++){
		long long sum = 0;
		scanf("%d",&N);
		int s[N],t[N];
		for(int j=0;j<N;j++){
			scanf("%d",&s[j]);
		}
		qsort(s,N,sizeof(int),cmp_up);
		for(int j=0;j<N;j++){
			scanf("%d",&t[j]);
		}
		qsort(t,N,sizeof(int),cmp_down);
		for(int j=0;j<N;j++){
			sum += s[j]*t[j];
		}
		printf("case #%d:\n",i);
		printf("%lld\n",sum);
		
	}
	return 0;
}