#include<stdio.h>//非结构体版本
int main()
{
	int n,i,j,t,year[100],month[100],date[100],amount[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d/%d/%d%d",&year[i],&month[i],&date[i],&amount[i]);
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(year[j]<year[j+1])
			{
				t=year[j];
				year[j]=year[j+1];
				year[j+1]=t;
				t=month[j];
				month[j]=month[j+1];
				month[j+1]=t;
				t=date[j];
				date[j]=date[j+1];
				date[j+1]=t;
				t=amount[j];
				amount[j]=amount[j+1];
				amount[j+1]=t;
			}
			else if(year[j]==year[j+1])
			{
				if(month[j]<month[j+1])
				{
					t=month[j];
					month[j]=month[j+1];
					month[j+1]=t;
					t=date[j];
					date[j]=date[j+1];
					date[j+1]=t;
					t=amount[j];
					amount[j]=amount[j+1];
					amount[j+1]=t;
				}
				else if(month[j]==month[j+1])
				{
					if(date[j]<date[j+1])
					{
						t=date[j];
						date[j]=date[j+1];
						date[j+1]=t;
						t=amount[j];
						amount[j]=amount[j+1];
						amount[j+1]=t;
					}
					else if(date[j]==date[j+1])
					{
						if(amount[j]<amount[j+1])
						{
							t=amount[j];
							amount[j]=amount[j+1];
							amount[j+1]=t;
						}
					}
				}
			}
		}
	}
	for(i=0;i<n;i++)
	printf("%d/%d/%d %d\n",year[i],month[i],date[i],amount[i]);
	return 0;
 } 



