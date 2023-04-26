#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int T,r,c,n,k;
	int i,j;
	int x,y,x1,y1,x2,y2,s1;
	int s[11][11];
	
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		scanf("%d%d%d%d",&r,&c,&n,&k);
		memset(s,0,sizeof(s));
		for(j=0;j<n;j++)
		{
			scanf("%d%d",&x,&y);
			for(x1=x;x1<=r;x1++)
			{
				for(y1=y;y1<=c;y1++)
				{
					s[x1][y1]++;
				}
			}
		/*	printf("s[]:\n");
			for(int z1=0;z1<11;z1++)
			{
				for(int z2=0;z2<11;z2++)
				{
					printf("%d ",s[z1][z2]);
				}
			}*/
	    }
			s1=0;//记录满足条件的矩形个数
			 for(x1=1;x1<=r;x1++)
			 {
			 	for(y1=1;y1<=c;y1++)
			 	{
			 		for(x2=x1;x2<=r;x2++)
			 		{
			 			for(y2=y1;y2<=c;y2++)
			 			{
			 				if(s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1]>=k)
			 				s1++;
						 }
					 }
				 }
			 }
		printf("case #%d:\n",i);
		printf("%d\n",s1);
	}

	
}
 