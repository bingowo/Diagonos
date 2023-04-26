#include<stdio.h>
int gcd(int a, int b){
    return b == 0 ? a:gcd(b, a%b);
}
int main()
{
	int T;
	scanf("%d",&T);
	int i=0,j=0;
	for(i=0;i<T;i++)
	{
		int N;
		scanf("%d",&N);
		int data[N]={0};
		int flg[1001]={0};
		int len=0,num=0;
		for(j=0;j<N;j++)
		{
			scanf("%d",&num);
			if(flg[num]==0)
			{
				flg[num]=1;
				data[len++]=num;
		    }
		}
		int ans=0;
		for(int k=0;k<len;k++)
		{
			for(int t=k+1;t<len;t++)
			{
				if(gcd(data[k],data[t])==1)
				{
					ans++;
				}
			}
		}
		printf("case #%d:\n",i);
		printf("%d\n",ans);
	}
}