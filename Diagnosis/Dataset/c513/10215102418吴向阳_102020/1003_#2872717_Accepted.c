#include <stdio.h>
#include <stdlib.h>

struct data{
	long long a;
	int b;
};

int numberof1(long long m){
	int n=0;
	if (m==0) return n;
	else{
		unsigned long long a=m;
		while (a){
			if (a&1) n++;
			a=a>>1;
		}
		return n;
	}
}

int cmp(const void *p1,const void *p2){
	struct data x=*(struct data*)p1,y=*(struct data*)p2;
	if (x.b==y.b){
		if (x.a-y.a>0) return 1;
		else return -1;
	}
	else return (y.b-x.b);
}
int main(){
	int T,N;
	scanf("%d",&T);
	for (int i=0;i<T;i++){
		scanf("%d",&N);
		struct data p[N];
		for (int j=0;j<N;j++){
			scanf("%lld",&p[j].a);
			p[j].b=numberof1(p[j].a);
		}
		qsort(p,N,sizeof(p[0]),cmp);
		printf("case #%d:\n",i);
		for (int j=0;j<N;j++) printf("%lld ",p[j].a);
		printf("\n");
	}
	return 0;
}