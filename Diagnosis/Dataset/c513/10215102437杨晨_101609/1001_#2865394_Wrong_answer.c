#include<stdio.h>
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
	while(n<i){
		char z[100];
		int a,b,c;
		c=0;
		a=Z[n];
		b=Z[n++];
		int f=0;
		int e=0;
		while(a!=0){
			int d;
			if(a<0){
				f=1;
				a=-a;
			}
			e=0;
			d=a%b;
			a=a/b;
			if(d<10) z[e++]='d';
			if(d>=10){
				z[e++]='A'+d-10;
			}
		}
		if(f==1) z[e++]='-';
		while(e>=0){
			printf("%c",z[e--]);}
		n++;
		e=0;
		}
	return 0;
}