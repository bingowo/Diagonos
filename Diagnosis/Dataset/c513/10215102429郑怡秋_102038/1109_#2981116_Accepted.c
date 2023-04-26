#include <stdio.h>
#include <stdlib.h>
void solve(int a[],int j)
{
	int x=a[j];
	if(x==0) return;
	if(j==1)
	{
		if(x==1) printf("x");
		else if(x==-1) printf("-x");
		else printf("%dx",x); 
	}
	else if(j==0)
	{
		printf("%d",x);
	}
	else 
	{
		if(x==1) printf("x^%d",j);
		else if(x==-1) printf("-x^%d",j);
		else printf("%dx^%d",x,j);
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int a[20];
		for(int j=8;j>=0;j--) scanf("%d",&a[j]);
		printf("case #%d:\n",i);
		int k=8,l=8;
		while(a[k]==0&&k>0) k--;//printf("k:%d\n",k);
		if(k==0&&a[k]==0) printf("0\n");
		else
		{
			l=k-1;
			solve(a,k);
		
			for(;l>=0;l--)
			{
				if(a[l]>0) printf("+"),solve(a,l);
				else solve(a,l);
			}
			printf("\n");
			
		}
 	}
 	return 0;
}