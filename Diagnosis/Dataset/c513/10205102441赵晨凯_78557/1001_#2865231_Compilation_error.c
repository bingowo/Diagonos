#include<stdio.h>
int main()
{
	int t,n,r,m;
	int o[100];
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		m=0;
		scanf("%d %d",&n,&r);
		if(n<0)
		{
			printf("%c",'-');
			n=-n;
		}
		while(n!=0)
		{
			o[m]=n%r;
			n=n/r;
			m++;
		}
		for(int j=m-1;j>=0;j--)
		{
			if(o[j]<10 )printf("%d",o[j]);
			else  printf("%c",char(o[j]+55));
		}
		printf("\n");
	}
	
} 