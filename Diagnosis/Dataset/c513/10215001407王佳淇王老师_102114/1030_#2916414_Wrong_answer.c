#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct {
	long long int x;
	long long int y;
	int bit;
	
}DATA;
int ana(long long int n){
	while(n>9) n=n/10;
	return n;
}
int cmp(const void*a,const void*b){
	int a1=((DATA*)a)->bit,b1=((DATA*)b)->bit;
	if(a1==b1) {
	return ((((DATA*)a)->x)>(((DATA*)b)->x));
	}
	else if(a1!=b1) return (b1>a1)?1:-1;
}
int main(){
	int T,N;
	DATA data[100001];
	scanf("%d\n",&T);
	for(int i=0;i<T;i++){
		scanf("%d\n",&N);
		for(int j=0;j<N;j++){
			scanf("%lld ",&data[j].x);
			data[j].y=abs(data[j].x);
			data[j].bit=ana(data[j].y);
		}
		qsort(data,N,sizeof(DATA),cmp);
		printf("case #%d:\n",i);
		for(int k=0;k<N;k++) printf("%lld ",data[k].x);
		printf("\n");
		memset(data,0,sizeof(DATA)*100001);
	}
	return 0;	
}