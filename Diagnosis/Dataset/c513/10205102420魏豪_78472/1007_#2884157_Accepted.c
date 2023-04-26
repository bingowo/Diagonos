#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	for(int k=0;k<t;k++){
		int n,i;
		int a[40]={0};
		scanf("%d",&n);
		i=0;
		while(n){
			a[i]=n%2;
			n=n/2;
			i++;
		}
		int len=1,max=1;
		for(int j=i-1;j>0;j--){
			if(a[j]!=a[j-1]) len++;
			if(len>max) max=len;
			if(a[j]==a[j-1]) len=1;
		}
		printf("case #%d:\n",k);
		printf("%d\n",max);
	}
	return 0;
	
}