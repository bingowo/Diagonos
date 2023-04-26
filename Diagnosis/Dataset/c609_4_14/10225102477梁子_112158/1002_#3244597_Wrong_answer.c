#include<stdio.h>
#include<stdlib.h>
int main()
{
	int t;
	scanf("%d",&t);
	int i;
	long long int n,cnt=1,temp=1;
	int a,b;
	for(i=0;i<t;i++){
		scanf("%lld",&n);
		a=n%2;
		while(n){
			n=n/2;
			b=n%2;
			if(a!=b){temp++;}
			else {
				if(temp>cnt)cnt=temp;
				temp=1;
			}
			a=b;
		}
		printf("case #%d\n",i);
		printf("%d\n",cnt);
	}
	return 0;
}