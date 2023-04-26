#include<stdio.h>
#include<stdlib.h>
int min(int a,int b)
{
	if(a<b)return a;
	else return b;
}
int main()
{
	int T,i,j,k,N,tmp,cnt2,cnt5;scanf("%d",&T);
	for(int cas=0;cas<T;++cas)
	{
		scanf("%d",&N);
		cnt2=0;cnt5=0;
		for(i=2;i<=N;++i)
		{
			tmp=i;
			if(!(tmp%2))
			{
				while(!(tmp%2))
				{
					cnt2++;
					tmp/=2;
				}
			}
			if(!(tmp%5))
			{
				while(!(tmp%5))
				{
					cnt5++;
					tmp/=5;
				}
			}
		}
		printf("case #%d:\n%d\n",cas,min(cnt2,cnt5));
	}
	return 0;
}