#include<stdio.h>

typedef struct{
	int cnt;
	int v[501];
}BIGINT;

void myprint(BIGINT c){
	int k;
	for(k=c.cnt-1;k>=0;k--)
		printf("%d",c.v[k]);
	printf("\n");	
}

BIGINT minus(BIGINT x,BIGINT y){
	int i;
	BIGINT z={(x.cnt>y.cnt)?x.cnt:y.cnt,{0}};
	for(i=0;i<x.cnt||i<y.cnt;i++){
		z.v[i]=x.v[i]-y.v[i];
	}
	for(i=0;i<x.cnt||i<y.cnt;i++){
		if(z.v[i]<0){
			z.v[i]+=10;
			z.v[i+1]--;
		}
	}
	return z;
}

int main(){
	BIGINT a={1,{0}},b={1,{0}};
	do{
		do{
			scanf("%c",&s);
			if(s!=' ')
			a.v[i]=s-'0';
		}
	}
//		myprint(minus(a,b));

	return 0;
}