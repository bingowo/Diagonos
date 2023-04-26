#include <stdio.h>

int main()
{
	int t,e;
	scanf("%d",&t);
	for(e=0;e<t;e++)
	{
		int r,c,n,k,count=0;
		scanf("%d %d %d %d",&r,&c,&n,&k);
		int a[12][12]={0};
		int i=0;
		for(i;i<n;i++)
		{
			int x1,y1;
			scanf("%d %d",&x1,&y1);
			a[x1][y1]=1;
		}
		
		int s[12][12]={0};
		int k1=1,m=1;
		for(k1;k1<=r;k1++)
		{
			for(m;m<=c;m++)
			{
				s[k1][m]=s[k1-1][m]+s[k1][m-1]+a[k1][m]-s[k1-1][m-1];
				if(s[k1][m]>=k) count++; 
			}
			m=1;
		}
		//printf("%d\n",count);
		int x2=1,y2=2;
		while(x2<=r&&y2<=c)
		{
			//printf("h\n");
			
			for(k1=x2;k1<=r;k1++)
			{
				for(m=y2;m<=c;m++)
				{
					if(s[k1][m]-s[x2-1][m]-s[k1][y2-1]+s[x2-1][y2-1]>=k) count++;
				}
				m=y2;
			}
			if(y2==c&&x2<r)
			{
				x2++;y2=1;
			}
			else
			{
				y2++;
			}
		}
		printf("case #%d:\n",e);
		printf("%d\n",count);
		
	}
	return 0;
}