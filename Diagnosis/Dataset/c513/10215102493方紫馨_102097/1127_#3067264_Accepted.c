#include<stdio.h>
struct data{
	int n,m;
};

int GCD(int x,int y){
	int t=1;
	while(t!=0){
		t=x%y;
		x=y;
		y=t;
	}	
	return x;
}

int LCM(int x,int y){
	return x*y/GCD(x,y);
}
int main()
{
	int n;
	scanf("%d",&n);
	
	struct data num[100];
	scanf("%d/%d",&num[0].n,&num[0].m);
	int M=num[0].m;
	for(int k=1;k<n;k++){
		scanf("%d/%d",&num[k].n,&num[k].m);
		M=LCM(M,num[k].m);
	}
	int S=0;
	for(int i=0;i<n;i++){
		S+=num[i].n*(M/num[i].m);
	}
	int d=GCD(S,M);
	S/=d;M/=d;
	printf("%d/%d",S,M);
	return 0;
}