#include<stdio.h>
int T,n,ans[1000],t,cnt;
int main()
{
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		scanf("%d",&n);
		int j=0,maxn=1;
		while(n)
		{
			t=n%2;
			n/=2;
			ans[j++]=t;					
		}
		cnt=0;	
		for(int k=0;k<j;k++)
		{
			if(k==0)
				cnt++;
			else
			{
				if(ans[k]!=ans[k-1])
				{
					cnt++;
					if(maxn<cnt)
						maxn=cnt;
				}
				else
				{
					if(maxn<cnt)
						maxn=cnt;
					cnt=1;
				}
			}
		}
		printf("case #%d:\n",i);
		printf("%d\n",maxn);
	}
	return 0;
 } 