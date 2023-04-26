#include<stdio.h>
#include<stdlib.h>

typedef struct{
			long long num;
			int nof1;
		} team;

int cmp(const void* A,const void* B){
	team a=*(team*)A,b=*(team*)B;
	if(a.nof1==b.nof1)
		return a.num-b.num;
	else return b.nof1-a.nof1;
}

int cnt(long long x){
	int cnt=0;
	if(x<0){
		x=~x;
		while(x){
			if(x%2)cnt++;
			x/=2;
		}
		return 64-cnt;
	}
	else{
		while(x){
			if(x%2)cnt++;
			x/=2;
		}
		return cnt;
	}
}

int main(){
	int N,T,i,j;
	scanf("%d",&T);
	for(i=0;i<T;i++){
		scanf("%d",&N);
		team *a=(team*)malloc(N*sizeof(team));
		for(j=0;j<N;j++){
			scanf("%lld",&a[j].num);
			a[j].nof1=cnt(a[j].num);
		}
		qsort(a,N,sizeof(team),cmp);
		printf("case #%d:",T)
		for(j=0;j<N-1;j++)
			printf("%lld ",a[j].num);
		printf("%lld\n",a[N-1].num);
	}
	return 0;
}