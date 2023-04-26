#include<stdio.h>
int cal(long long x){
	if(x<0) x=-x;
	while(x>=10){
		x/=10;
	}
	return x;
}
int cmp(const void*a,const void*b){
	long long x,y;
	x=*(long long*)a;
	y=*(long long*)b;
	if(cal(x)>cal(y)) return -1;
	else if(cal(x)<cal(y)) return 1;
	else{
		if(x>=y) return 1;
		else return -1;
	}
}
int main(){
	int chance;
	scanf("%d",&chance);
	int i;
	for(i=0;i<chance;i++){
		printf("case #%d:\n",i);
		int n;
		scanf("%d",&n);
		long long a[n];
		int j;
		for(j=0;j<n;j++){
			scanf("%lld",&a[j]);
		}
		qsort(a,n,sizeof(long long),cmp);
		for(j=0;j<n;j++){
			printf("%lld ",a[j]);
		}
		printf("\n");
	}
	
}