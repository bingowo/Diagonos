#include<stdio.h>

int main(){
	int T;
	scanf("%d",&T);
	int z[100];
	int i=0;
	while(T!=0){
		scanf("%d %d",&z[i],&z[i+1]);
		i=i+2;
		T--;
	}
	int n=0;
	while(n<i){
		int a,b,c,d;
		a=z[n];
        b=z[n+1];
		d=0;
		if(a<0){
			a=-a;
			printf("-");
		}
		char f[]="0123456789ABCDEFGHIJKLMNOPQR";
        int r[100];
        int m=0;
		while(a!=0){
			int e;
			e=a%b;
			a=a/b;
			r[m++]=e;
		}
		while(m>=1) printf("%c",f[r[--m]]);
        printf("\n");
		n=n+2;

	}
	return 0;
	}
