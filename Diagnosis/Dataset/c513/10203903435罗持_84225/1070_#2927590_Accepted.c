#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int n;
int check(int x){
	int bit[32] = {0};
	int num = x;
	int idx = 0;
	while(num){
		if(num&1) bit[idx++] = 1;
		else bit[idx++] = 0;
		num >>= 1;
	}
	for(int i=0;i+3<=idx;i++){
		if(bit[i]==1 && bit[i+1]==0 && bit[i+2]==1) return 0;
	}
	return 1;
}
int main(void)
{
	while(scanf("%d",&n)!=EOF)
	{
		if(n==-1) break;
		int num = 1;
		for(int i=1;i<=n;i++) num *= 2;
		num--;
		int cnt = 0;
		for(int i=0;i<=num;i++){
			if(check(i)) cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}