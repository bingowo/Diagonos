#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int T,n,num[105];
int main(){
	scanf("%d",&T);
	for(int c=0;c<T;c++){
		scanf("%d",&n);
		int cnt=0;
		while(n) num[++cnt]=n%2,n/=2;
		for(int i=cnt;i;i--){
			int flag=0;
			for(int j=1;j+i-1<=cnt;j++){
				for(int k=1;k<i;k++){
					if(num[j+k]==num[j+k-1]) break;
					if(k==i-1) flag=1;
				}
				if(flag||i==1) break;
			}
			if(flag || i==1){
				printf("case #%d:\n%d\n",c,i);
				break;
			}
		} 
	}
	return 0; 
} 