#include<stdio.h>

typedef struct{
	int cnt;
	int v[1000];
}BIGINT;

BIGINT ADD(BIGINT x,BIGINT y){
	int i,carry=0,t;
	BIGINT z={(x.cnt>y.cnt)?x.cnt:y.cnt,{0}};
	for(i=0;i<x.cnt||i<y.cnt;i++){
		t=carry+x.v[i]+y.v[i];
		z.v[i]=t%10;
		carry=t/10;
	}
	if(carry>0)
		z.v[z.cnt++]=carry;
	return z;
}

void myprint(BIGINT c){
	int k;
	for(k=c.cnt-1;k>=0;k--)
		printf("%d",c.v[k]);
	printf("\n");	
}

int main(){
	int i,j,k,n,T;
	scanf("%d",&T);
	for(i=0;i<T;i++){
		scanf("%d",&n);
		printf("case #%d:\n",i);
		BIGINT a={1,{0}},b={1,{1}},c;
		if(n==0){
			myprint(a);
			continue;
		}
		if(n==1){
			myprint(b);
			continue;
		}
		for(j=2;j<=n;j++){
			if(j%2==0){
				c=ADD(a,b);
				a=c;
			}
			if(j%2==1){
				c=ADD(a,b);
				b=c;	
			}
		}
		myprint(c);
	}
	return 0;
}