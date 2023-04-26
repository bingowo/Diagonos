#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int n,i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		int a;
		int l=0;
		int ans=0;
		scanf("%d",&a);
		int q=1;
		l=a%2;
		a=a/2;
		int cnt=1;
		while(a>0){
			if(a%2!=l) cnt++;
			else if(cnt>ans){
				ans=cnt;
				cnt=1;
			}
			l=a%2;
			a=a/2;	
		}
		if(cnt>ans) ans=cnt;
		printf("case #%d:\n%d\n",i-1,ans);
	}
} 

