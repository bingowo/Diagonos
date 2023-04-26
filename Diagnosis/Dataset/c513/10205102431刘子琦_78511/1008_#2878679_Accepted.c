#include<stdio.h>
int main()
{
	int t,i,p,q,result;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		result=0;
		scanf("%d%d",&p,&q);
		while(p!=0&&q!=0)
		{
			if(p%2!=q%2)result++;
			p=p/2;q=q/2;
		}
		while(p!=0)
		{
			
			if(p%2==1)result++;
			p=p/2;
		}
		while(q!=0)
		{
			if(q%2==1)result++;
			q/=2;
		}
		printf("%d\n",result);
	}
}