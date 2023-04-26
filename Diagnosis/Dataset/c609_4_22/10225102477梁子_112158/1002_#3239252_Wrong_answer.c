#include<stdio.h>
#include<stdlib.h>
int main()
{
	int t;
	scanf("%d",&t);
	int i;
	int n,cnt=0;
	int a,b;
	for(i=0;i<t;i++){
		scanf("%d",&n);
		a=n%2;
		while(n){
			n=n/2;
			b=n%2;
			if(a!=b)cnt++;
			else break;
		}
		printf("case #%d\n",i);
		printf("%d\n",cnt);
	}
	return 0;
}