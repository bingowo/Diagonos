#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int a[9],b=0;
		for(int j=0;j<9;j++) scanf("%d",&a[j]);
		printf("case #%d:\n",i);
		int j=0;
		while(a[j]==0&&j<8) j++;
		if(j==8) printf("%d\n",a[8]);
		else
		{
			if(j==7) b=1;
			else if(a[j]==1) printf("x^%d",8-j);
			else if(a[j]==-1) printf("-x^%d",8-j);
			else printf("%dx^%d",a[j],8-j);
			j++;
			for(;j<7;j++)
			{
				if(a[j]==0) continue;
				else if(a[j]>0) printf("+");
				if(a[j]==1) printf("x^%d",8-j);
				else if(a[j]==-1) printf("-x^%d",8-j);
				else printf("%dx^%d",a[j],8-j);
			}
			if(a[7]!=0&&b!=1)
			{
				if(a[7]>0) printf("+");
				if(a[7]==1) printf("x");
				else if(a[7]==-1) printf("-x");
				else printf("%dx",a[7]);
			}
			if(b==1)
			{
				if(a[7]==1) printf("x");
				else if(a[7]==-1) printf("-x");
				else printf("%dx",a[7]);		
			}
			if(a[8]!=0)
			{
				if(a[8]>0) printf("+");
				printf("%d",a[8]);
			}
			printf("\n");
			b=0;
		}
	}
	
}