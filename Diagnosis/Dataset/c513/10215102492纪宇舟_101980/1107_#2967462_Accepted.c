#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int a[4][4];
int main()
{
	int ct=0,T;scanf("%d",&T);
	while(T--)
	{
		int x;
		memset(a,0,sizeof(a));
		for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
		{
			scanf("%d",&x);
			a[i][j]+=x;
			a[i-1][j]+=x;
			a[i+1][j]+=x;
			a[i][j-1]+=x;
			a[i][j+1]+=x;
		}
		printf("case #%d:\n",ct++);
		for(int i=1;i<=3;i++)
		{
			for(int j=1;j<=3;j++)
			{
				if(a[i][j]&1)printf("0");
				else printf("1");
				if(j!=3)printf(" ");
			}printf("\n");
		}
	}
	return 0;
}