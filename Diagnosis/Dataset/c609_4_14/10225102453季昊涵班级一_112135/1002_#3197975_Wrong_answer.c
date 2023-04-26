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
		int out=0;
		int temp=0;
		while(i--){
			if(a[i]!=a[i-1])
			temp++;
			if(a[i]==a[i-1]){
				if(temp>out)
				out=temp;
				temp=0;
			}
		}
		printf("case #%d:\n",k);
		k++;
		printf("%d\n",out+1);
	}
	
	
	
	return 0; 
} 