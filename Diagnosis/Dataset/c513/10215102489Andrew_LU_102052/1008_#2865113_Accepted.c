#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int n,i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		int a,b;
		int ans=0;
		scanf("%d%d",&a,&b);
		while(a>0 || b>0){
			if(a%2!=b%2) ans++;
			a=a/2;
			b=b/2;
		}
		printf("%d\n",ans);
	}
} 

