#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct{
	long long int x;
	long long int y;
	long long int dis;
}DIS;
int cmp(const void*a,const void*b){
long long int a1=((DIS*)a)->dis;
long long int b1=((DIS*)b)->dis;
if(a1==b1) return 0;
else return a1>b1?1:-1;	
}

int main(){
	int N;
	DIS d[100];
	scanf("%d",&N);
	int i=0;
	for(;i<N;i++){
		scanf("%lld %lld\n",&d[i].x,&d[i].y);
		d[i].dis=abs(d[i].x)+abs(d[i].y);
	}
	qsort(d,N,sizeof(DIS),cmp);
	printf("case#");
	printf("%lld\n",abs(d[0].x-d[1].x)+abs(d[0].y-d[1].y));
}