#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct data{
	long long a;
	int number;
}; 
int cmp(const void*a,const void*b){
	struct data d1,d2;
	d1=*((struct data *)a);
	d1=*((struct data *)b);
	if(d2.number!=d1.number)return d2.number-d1.number;
	else {
		if(d1.a>d2.a)
		return 1;
		else return -1;
	}
	
}
int main(){
	int T,N;
	int d;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		printf("case #%d:",i);
		scanf("%d",&N);
		struct data p[10000]; 
		for(int i=0;i<N;i++){
			scanf("%lld",p[i].a);
			p[i].number=0,d=0;
			for(int t=0;t<64;t++){
			if(p[i].a&d){
			p[i].number++;
			d<<=1;
		   }	
		}
		qsort(p,N,sizeof(p[0]),cmp);//qsort排序函数，第一个参数为首元素指针，第二个参数为元素个数，第三个参数为元素大小，第四个参数为比较函数 
		for(int i-0;i<n-1;i++){
			printf("%lld",p[i].a);
			printf("\n");
		}
	  }
	} 
	return 0;
}