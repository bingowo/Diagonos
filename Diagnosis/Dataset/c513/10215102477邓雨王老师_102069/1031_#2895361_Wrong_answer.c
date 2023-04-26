#include<stdio.h>
int cmp1(const void*a,const void*b){
	int x,y;
	x=*(int*)a;
	y=*(int*)b;
	if(x>=y){
		return 1;
	}
	else return -1;
}
int cmp2(const void*a,const void*b){
	int x,y;
	x=*(int*)a;
	y=*(int*)b;
	if(x>=y){
		return -1;
	}
	else return 1;
}
int main(){
	int chance;
	scanf("%d",&chance);
	int i;
	for(i=0;i<chance;i++){
		long long sum=0;
		int n;
		scanf("%d",&n);
		printf("case #%d:\n",i);
		int j;
		int x[n],y[n];
		for(j=0;j<n;j++){
			scanf("%d",&x[j]);
		}
		for(j=0;j<n;j++){
			scanf("%d",&y[j]);
		}
		qsort(x,n,sizeof(x[0]),cmp1);
		qsort(y,n,sizeof(y[0]),cmp2);
		for(j=0;j<n;j++){
			sum=x[j]*y[j];
		}
		printf("%lld\n",sum);
	}
}