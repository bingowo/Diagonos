#include<stdio.h>
typedef struct {long long x;int count;}num;
int cmp(const void *a, const void *b){
	int ma = (*(num*)a).count,mb = (*(num*)b).count  ;
	if(ma == mb) 
		return  (*(num*)a).x > (*(num*)b).x ? 1 : -1;//位数相同则升序
	else
		return mb - ma;		//位数不同则降序
}
int count_1(long long p){
	int one = 0;
	
	for(int i=0;i<=63;i++){
		if((p & (1 << i)) == (1 << i))
			one++;
	}

	return one;
}
int main(){
	int t,n;
	scanf("%d ",&t);
	
	
	for(int i=0;i<t;i++){
		scanf("%d",&n);
		num p[10010];
		for(int j=0;j<n;j++){
			scanf("%lld",&(p[j].x));
			
			p[j].count=count_1(p[j].x);
		}
		qsort(p,n,sizeof(p[0]),cmp);
		
		printf("case #%d:\n",i);
		for(int j=0;j<n;j++){
			printf("%lld%c",(p+j)->x,j==n-1?'\n':' ');
		}

	}
	return 0;


	}
	return 0;
}
