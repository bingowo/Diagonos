#include<stdio.h>
typedef struct{
	long long r;
	long long h;
}yuan;
int cmp1(const void*a,const void*b){
	yuan x,y;
	x=*(yuan*)a;
	y=*(yuan*)b;
	if(x.r*x.h>y.r*y.h) return -1;
	else return 1;
}
int cmp2(const void*a,const void*b){
	yuan x,y;
	x=*(yuan*)a;
	y=*(yuan*)b;
	if(x.r>y.r) return -1;
	else return 1;
}
int main(){
	long long sum=0;
	int number,choice;
	scanf("%d %d",&number,&choice);
	yuan a[number];
	int i;
	for(i=0;i<number;i++){
		scanf("%lld %lld",&a[i].r,&a[i].h);
	}
	qsort(a,number,sizeof(yuan),cmp1);
	yuan b[choice];
	for(i=0;i<choice;i++){
		b[i].r=a[i].r;
		b[i].h=a[i].h;
	}
	qsort(b,choice,sizeof(yuan),cmp2);
	sum=sum+b[0].r*b[0].r;
	for(i=0;i<choice;i++){
		sum=sum+2*b[i].h*b[i].r;
	}
	printf("%lld",sum);
}