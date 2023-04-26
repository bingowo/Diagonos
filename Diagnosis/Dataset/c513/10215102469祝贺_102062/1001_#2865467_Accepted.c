#include<stdio.h>
int main()
{
	int t,n,r;
	scanf("%d",&t);
	while(t--)
	{
		int num[32],p=0; 
		scanf("%d%d",&n,&r);
		if(n<0)
		{
			printf("%c",'-');n=-n;
		}
		do
		{
			num[p++]=n%r;
			n/=r;
		}
		while(n!=0);
		for(int i=p-1;i>=0;i--)
		{
			if(num[i]>9)
			printf("%c",num[i]+'A'-10);
		else printf("%d",num[i]);
		}
		printf("\n");
	}
	return 0;
}