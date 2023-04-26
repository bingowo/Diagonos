#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int T,i,j,n,temp;
	char c;
	int flag=0;
	int table[123];
	long long int ans[61];
	int k=2;
	long long int ret=1;
	char s[61];
	for (int i=0;i<=122;i++)	table[i]=-1;
	scanf("%d",&T);
	
	for (i=0;i<T;i++)
	{
		for (int i=0;i<=122;i++)	table[i]=-1;
		n=0;//进制 
		j=0;
		scanf ("%s",&s);
		k=2;
		for(j=0;j<=strlen(s)-1;j++)
		{
			char c=s[j];
			if (table[c]==-1)
			{
				n++;
				if (j==0)
				{
					table[c]=1;
					ans[j]=1;
					flag=1;
				}
				else if((flag==1)&&(table[c]==-1))
				{
					flag=0;
					table[c]=0;
					ans[j]=0;
				}
				else 
				{
					table[c]=k;
					ans[j]=k;
					k++;
				}
			}
			else
			{
				ans[j]=table[c];
			}
		}
		if(n==1) n=2;
		ret = 1;
		for (int z=1;z<j;z++)
		{
			ret = ret*n+ans[z];
		}
		printf("case #%d:\n",i);
		printf("%lld\n",ret);
	}
}
