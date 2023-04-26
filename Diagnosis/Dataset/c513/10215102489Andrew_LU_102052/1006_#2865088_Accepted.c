#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int n,i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		char a[65];
		int ans=0;
		scanf("%s",a);
		int q=1;
		for(j=strlen(a)-1;j>=0;j--){
			if(a[j]=='-') ans=ans-q;
			else ans=ans+q*(a[j]-'0');
			q=q*3;
		}
		printf("case #%d:\n%d\n",i-1,ans);
	}
} 

