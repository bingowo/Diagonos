#include<stdio.h>
int main(){
	int T;
	scanf("%d",&T);
	int n;
	int a;
	int cnt = 1;
	int maxcnt = 1;
	for(int i = 0;i < T;i++){
		scanf("%d",&n);
		while(n){
			a = n % 2;
			n >>= 1;
			if(!n || (n % 2 == a)){
				if(cnt > maxcnt)
					maxcnt = cnt;
				cnt = 1;
			}else
				cnt++; 
		}
		printf("case #%d:\n",i);
		printf("%d\n",maxcnt);
		cnt = 1;
		maxcnt = 1; 
	}
	return 0;
} 