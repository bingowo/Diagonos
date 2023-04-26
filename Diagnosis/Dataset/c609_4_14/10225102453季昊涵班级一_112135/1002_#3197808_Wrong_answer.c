#include<stdio.h>
int a[100006];

int main(){
	int T;
	scanf("%d",&T);
	int k=0;
	while(T--){
		int n;
		scanf("%d",&n);
		int i=0;
		while(n){
			a[i]=n%2;
			i++;
			n/=2;
		}
		int j=i-1;
		while(a[j]!=a[j-1])
		j--;
		printf("case #%d:\n",k);
		k++;
		printf("%d\n",i-j);
	}
	
	
	
	return 0; 
} 