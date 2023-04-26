#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int n,i,j,k;
	char a[65];
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		char li[63];
		int l=0;
		scanf("%s",a);
		for(j=0;j<strlen(a);j++){
			int f=0;
			for(k=0;k<l;k++){
				if(a[j]==li[k]) f=1;
			}
			if(f==0){
				li[l]=a[j];
				l++;
			}
		}
		int q=1,ans=0;
		for(j=strlen(a)-1;j>=0;j--){
			int t=0;
			for(k=0;k<l;k++){
				if(a[j]==li[k]){
					t=k;
					break;
				}
			}
			if(t==0) t=1;
			else if(t==1) t=0;
			ans=ans+q*t;
			q=q*l;
		}
		printf("case #%d:\n%d\n",i-1,ans);
	}
} 

