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
	int x[1001],y[1001];
	for(i=0;i<chance;i++){
		long long sum=0;
		int t=0;
		int p=0;
		printf("case #%d:\n",i);
		while(scanf("%d",&x[t++])!=EOF);
		while(scanf("%d",&y[p++])!=EOF);
		qsort(x,t,sizeof(x[0]),cmp1);
		qsort(y,t,sizeof(y[0]),cmp2);
		int j;
		for(j=0;j<t;j++){
			sum=x[j]*y[j];
		}
		printf("%lld\n",sum);
	}
}