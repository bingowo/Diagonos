#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>

int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int r=10,c=10,n,k;
		scanf("%d%d%d%d",&r,&c,&n,&k);
		int ans[r][c];
		//memset(ans,0,sizeof(ans));
		for(int j=0;j<r;j++) for(int k=0;k<c;k++) ans[j][k]=0;
		for(int j=0;j<n;j++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			ans[x-1][y-1]=1;
		}
		int s=0;
		for(int a=0;a<r;a++)
			for(int b=0;b<c;b++)
			{
				for(int d=a;d<r;d++)
					for(int e=b;e<c;e++)
					{
						int m=0;
						for(int f=a;f<=d;f++)
							for(int g=b;g<=e;g++)
								if(ans[f][g]==1) m++;
						if(m>=k) s++;
					}
			}
		printf("case #%d:\n%d\n",i,s);
	}	
	return 0;
}