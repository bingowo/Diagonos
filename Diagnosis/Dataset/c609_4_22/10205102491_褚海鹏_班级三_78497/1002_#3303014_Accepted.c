#include<stdio.h>
int main()
{
	int t;
	unsigned long long int n;
	int p=0;
	scanf("%d",&t);
	while(scanf("%llu",&n)!=EOF){
		int b,m;
		b=1;
		m=1;
		int i=0;
		char a[100]={0}; 
		while(n>0)
		{
			
			a[i]=n%2;
			i=i+1;
			n=n/2;
		}
	for(;i>0;i--){
		if(a[i-1]!=a[i-2]&&i>=2)b=b+1;
		else{
			if(b>m){m=b;}
			b=1;
		}}
	printf("case #%d:\n",p);
	printf("%d\n",m);
	p=p+1;}
	return 0;
 } 