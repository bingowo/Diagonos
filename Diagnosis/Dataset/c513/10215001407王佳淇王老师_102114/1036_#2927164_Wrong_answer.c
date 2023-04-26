#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct{
	long long int x;
	long long int y;
	long long int dis;
}DIS;
int cmp(const void*a,const void*b){
long long int da=((DIS*)a)->dis;long long int db=((DIS*)b)->dis;
long long int xa=((DIS*)a)->x;long long int xb=((DIS*)b)->x;
long long int ya=((DIS*)a)->y;long long int yb=((DIS*)b)->y;
if(da!=db) return da>db?1:-1;
else if(da==db&&xa!=xb)	return xa>xb?1:-1;
else if(da==db&&xa==xb&&ya!=yb)	return ya>yb?1:-1;
else return 0;
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
	/*printf("case#\n");*/
	printf("%lld\n",abs(d[0].x-d[1].x)+abs(d[0].y-d[1].y));
}