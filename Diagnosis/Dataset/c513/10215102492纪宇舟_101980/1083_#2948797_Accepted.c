#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int main()
{
	int ct=0,T;scanf("%d",&T);
	while(T--)
	{
		int n,ans=0;scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			int x=i;
			while(x%5==0)
			{
				x/=5;++ans;
			}
		}
		printf("case #%d:\n",ct++);
		printf("%d\n",ans);
	}
	return 0;
}