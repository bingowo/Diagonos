#include<stdio.h>
int main()
{
	int t,i,j,k,n,r,ans[33],flag;
	char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		j=0;
		scanf("%d%d",&n,&r);
		if(n<0)
		{
			n=-n;
			flag=1;
		}
		do
		{
			ans[j++]=n%r;
			n=n/r;
		}while(n);
		if(flag)
			printf("-");
		for(k=j-1;k>=0;k--)
			printf("%c",table[ans[k]]);
		printf("\n");
	}
	return 0;
}