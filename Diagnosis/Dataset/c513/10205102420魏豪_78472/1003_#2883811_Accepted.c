#include<stdio.h>
#include<stdlib.h> 
#define MAXSIZE 10010
typedef struct num{
	long long val;
	int count;
}NUM;
int cmp(const void*a,const void*b){
	NUM x,y;
	x=*(NUM*)a;
	y=*(NUM*)b;
	if(x.count==y.count){
		if(x.val>y.val) return 1;
		else return -1;
	}
	else return y.count-x.count;
}
int main(){
	int t;
	scanf("%d",&t);
	for(int k=0;k<t;k++){
		int n;
		long long temp;
		scanf("%d",&n);
		NUM a[MAXSIZE];
		for(int i=0;i<n;i++){
			scanf("%lld",&a[i].val);
			a[i].count=0;
			temp=a[i].val;
			while(temp){
				temp=temp&(temp-1);
				a[i].count++;
			}
		}
		qsort(a,n,sizeof(a[0]),cmp);
		printf("case #%d:\n",k);
		for(int j=0;j<n;j++){
			printf("%lld ",a[j].val);
		}
		printf("\n"); 
	}
	return 0;
}
