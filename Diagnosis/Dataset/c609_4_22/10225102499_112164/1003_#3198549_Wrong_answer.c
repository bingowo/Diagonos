#include <stdio.h>
int main(){
	int n,i,b[10],j;
	long long a[300];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
		for(j=0;a[i]/2333>0||a[i]%2333!=0;j++){
			b[j]=a[i]%2333;
			a[i]/=2333;
		}
		for(;j>1;j--)
			printf("%d ",b[j-1]);
		printf("%d\n",b[0]);
	}
} 