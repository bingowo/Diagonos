#include<stdio.h>
long long count_step(int n);
int main(){
	int T;
	scanf("%d",&T);
	int n;
	for(int i = 0;i < T;i++){
		scanf("%d",&n);
		printf("case #%d:\n",i); 
		printf("%lld\n",count_step(n));
	}
} 
long long count_step(int n){
	if(n < 0)
		return 0;
	if(n == 0)
		return 1;
	if(n == 1)
		return 1;
	else
		return count_step(n-1) + count_step(n-2) + count_step(n-3) + count_step(n-4);
}