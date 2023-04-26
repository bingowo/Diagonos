#include<stdio.h>
int num(int A,int B){
	int i=0;
	while(A!=0){
		A=A/B;
		i++;
	}
	return i;
}
int main(){
	int T;
	scanf("%d",&T);
	int Z[100];
	int i=1;
	while(T!=0){
		scanf("%d%d",&Z[i],&Z[i+1]);
		i=i+2;
		T--;
	}
	int n=1;
	printf("%d",Z[2]);
	while(n<i){
		int a,b,c,d;
		a=Z[n];
		b=Z[n++];
		d=0;
		if(a<0){
			a=-a;
			printf("-");
		}
		c=num(a,b);
		char z[100];
		char f[]="0123456789ABCDEFG";
		while(a!=0){
			int e;
			e=a%b;
			a=a/b;
			printf("%c",f[e]);
		printf("\n");
		}

	}
	return 0;}
	
