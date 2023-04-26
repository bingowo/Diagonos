#include<stdio.h>
int a[100006];

int main(){
	int T;
	long long int n;
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&n);
		int i=0;
		do{
			a[i]=n%2333;
			i++;
		}while(n/=2333);
		for(int k=i-1;k>=0;k--)
		printf("%d ",a[k]);
		printf("\n");
}
	return 0; 
} 