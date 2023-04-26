#include <stdio.h>

typedef struct
{
	int x,y;
}Point;


int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int r,c,n,k;
		scanf("%d %d %d %d",&r,&c,&n,&k);
		Point p[n];
		for(int j=0;j<n;j++)
		{
			scanf("%d %d",&p[j].x,&p[j].y);
			p[j].x--;
			p[j].y--;
		}
		int ans = 0;
		for(int l1=0;l1<r;l1++)
		{
			for(int l2=0;l2<c;l2++)
			{
				for(int l3=l1;l3<r;l3++)
				{
					for(int l4=l2;l4<c;l4++)
					{
						int cnt = 0;
						for(int j=0;j<n;j++)
						{
							if(p[j].x>=l1&&p[j].x<=l3&&p[j].y>=l2&&p[j].y<=l4)
							{
								cnt ++;
								if(cnt>=k)  break;
							}
						}
						if(cnt>=k)  ans++;
					}
				}
			}
		}
		printf("case #%d:\n",i);
		printf("%d\n",ans);
	}
	return 0;
}