#include <stdio.h>
#include <stdlib.h>

int numberof1(long long m){
	int n=0,b=1;
	if (m==0) return n;
	else{
		if(m<0) n+=32;
		unsigned a=m;
		while (a){
			if (a&b) n++;
			a=a>>1;
		}
		return n;
	}
}

int cmp(const void *p1,const void *p2){
	long long x=*(long long*)p1,y=*(long long*)p2;
	int a=numberof1(x),b=numberof1(y);
	if (a==b){
		if (x-y>0) return 1;
		else return -1;
	}
	else return (b-a);
}
int main(){
	int T,N;
	scanf("%d",&T);
	for (int i=0;i<T;i++){
		scanf("%d",&N);
		long long a[N];
		for (int j=0;j<N;j++) scanf("%lld",&a[j]);
		qsort(a,N,sizeof(a[0]),cmp);
		printf("case #%d:\n",i);
		for (int j=0;j<N;j++) printf("%lld ",a[j]);
		printf("\n");
	}
	return 0;
}