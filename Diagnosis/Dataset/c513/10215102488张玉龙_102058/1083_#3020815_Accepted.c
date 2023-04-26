#include<stdio.h>
int main()
{
	int m,n,t=0;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{	
		scanf("%d",&n);
		t=n/5;
		if(n/25>0)
			t+=n/25;
		if(n/125>0)
			t+=n/125;
		if(n/625>0)
			t+=n/625;
	printf("case #%d:\n%d\n",i,t);
	}
}