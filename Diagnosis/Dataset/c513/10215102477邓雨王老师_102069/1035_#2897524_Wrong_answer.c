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
	else if(x.r*x.h==y.r*y.h){
		if(x.r>=y.r) return -1;
		else return 1;
	}
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
	yuan b[number];   //b是以侧面积来排序的 
	for(i=0;i<number;i++){
		b[i].r=a[i].r;
		b[i].h=a[i].h;
	}
	qsort(a,number,sizeof(yuan),cmp2);   //a是以半径来排序的 
	sum=sum+a[0].r*a[0].r;
	int j=0;
	i=0;
	int t=-1;
	while(j<choice){
		if(b[i].r==a[0].r&&t==-1){sum=sum+2*b[i+1].h*b[i+1].r;i++;j++;t=0;}
		else{
			sum=sum+2*b[i].h*b[i].r;
			i++;
			j++;
		}
	}
	printf("%lld",sum);
}