#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	unsigned long long re;
	if(n==1){
		re=1;
	}
	else if(n==2){
		re=2;
	}
	else if(n==3){
		re=3;
	}
	else if(n==4){
		re=6;
	}
	else{
		unsigned long long a=1,b=2,c=3,d=6;
		for(int i=0;i<n-4;i++)
		{
			re=a+c+d;
			a=b;
			b=c;
			c=d;
			d=re;
		}
	}
	printf("%llu",re);
	return 0;
}
