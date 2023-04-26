#include<stdio.h>
#include<stdlib.h> 
struct data{
	int cnt;
	long long int num;
}; 

int cmp(const void*p1,const void*p2){
	struct data a,b;
	a=*((struct data*)p1);
	b=*((struct data*)p2);
	if(a.cnt!=b.cnt)
		return b.cnt-a.cnt;
	return a.num-b.num;	
}

int count(long long int t){
	int a=0;
	long long d=1;
	for(int b=0;b<64;b++){
		if(t&d)
			a++;
		d=d<<1;
	}
	return a;
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int k=0;k<T;k++){
		int N,i;
		long long t;
		struct data p[10000];
		scanf("%d",&N);
		for(i=0;i<N;i++){
			scanf("%lld",&t);
			p[i].num=t;
			p[i].cnt=count(t);
		}
		qsort(p,N,sizeof(p[0]),cmp);
		printf("case #%d:\n",k);
		for(int j=0;j<N;j++){
			printf("%lld%c",p[j].num,j==N-1?'\n':' ');
		}		
	}	
	return 0;
 } 