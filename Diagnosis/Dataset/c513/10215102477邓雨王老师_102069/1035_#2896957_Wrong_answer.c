#include<stdio.h>
typedef struct{
	int r;
	int h;
}yuan;
int cmp(const void*a,const void*b){
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
		scanf("%d %d",&a[i].r,&a[i].h);
	}
	qsort(a,number,sizeof(yuan),cmp);
	int j=0;
	sum=sum+a[0].r*a[0].r;
	while(j<choice){
		sum=sum+2*a[j].r*a[j].h;
		j++;
	}
	printf("%lld",sum);
}