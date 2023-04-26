#include<stdio.h>
#include<math.h>
int main(){
	int T;
	scanf("%d",&T);
	for(int j=0;j<T;j++){
		long long n;
		scanf("%lld",&n);
		double m=(double)n;
		int key=0;
		printf("%lld",n);
		for(int i=2;i<=62;i++){
			double temp=pow(m,1.0/i);
			if(fabs(temp-(long long)temp)>1e-6);
			else {
			      printf("=%lld^%d",(long long)temp,i);
			      key=1;
				}
		}
		if(key==0) printf(" is powerless.",n);
		printf("\n");
	}
} 