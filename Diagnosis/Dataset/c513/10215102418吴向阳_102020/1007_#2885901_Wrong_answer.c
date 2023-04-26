#include <stdio.h>

int main(){
	int T;
	scanf("%d",&T);
	unsigned int n;
	for (int i=0;i<T;i++){
		scanf("%d",&n);
		int a[32],j=0;
		while(n){
			a[j++]=n%2;
			n/=2;
		}
		int m=1,max=0,k=0;
		while(k<j-1){
			while((a[k]!=a[k+1])&&(k<j-1)){
				m++;
				k++;
			}
			k++;
			if(m>max){
				max=m,m=1;
			}
		}
		printf("case #%d:\n%d\n",i,max);
	}
	return 0;
} 