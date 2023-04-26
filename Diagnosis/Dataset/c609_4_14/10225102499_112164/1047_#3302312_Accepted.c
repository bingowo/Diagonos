#include<stdio.h>

typedef struct{
	int cnt;
	int v[1000];
}BIGINT;

BIGINT times(BIGINT x,int a){
	int i,carry=0,t;
	for(i=0;i<x.cnt;i++){
		t=carry+x.v[i]*a;
		x.v[i]=t%10;
		carry=t/10;
	}
	if(carry>0)
		x.v[x.cnt++]=carry;
	return x;
}

int main(){
	int T,n,a,i,j,k;
	scanf("%d",&T);
	for(i=0;i<T;i++){
		printf("case #%d:\n",i);
		scanf("%d %d",&a,&n);
		BIGINT x={1,{1}};
		for(j=0;j<n;j++)
			x=times(x,a);
		for(k=x.cnt-1;k>=0;k--)
			printf("%d",x.v[k]);
		printf("\n");
	}
} 