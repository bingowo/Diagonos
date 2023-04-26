#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int T,n;

int main(){
	scanf("%d",&T);
	for(int c=0;c<T;c++){
		int cnt2=0,cnt5=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int x=i;
			while(x%2==0) cnt2++,x/=2;
			while(x%5==0) cnt5++,x/=5;
		}
		if(cnt2>cnt5) cnt2=cnt5;
		printf("case #%d:\n%d\n",c,cnt2);
	}
	return 0;
}