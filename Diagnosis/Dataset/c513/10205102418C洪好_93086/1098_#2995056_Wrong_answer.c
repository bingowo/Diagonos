#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,k;
	int t;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		char str[100];
		scanf("%s",str);
		int flag[4]={0,0,0,0},ans[4];
		int len=strlen(str);
		if(len==4)
		{
			flag[0]=1;
			flag[1]=1;
			flag[2]=1;
			flag[3]=1;
			for(j=0;j<4;j++)
			{
				if(str[j]=='R')
					flag[0]=0;
				if(str[j]=='B')
					flag[1]=0;
				if(str[j]=='Y')
					flag[2]=0;
				if(str[j]=='G')
					flag[3]=0;
			}
			printf("case #%d:\n%d %d %d %d\n",i,ans[0],ans[1],ans[2],ans[3]);
			continue;
		}
		for(j=0;j<len/4;j++)
		{
			if(str[j*4]=='!')
				flag[0]++;
			if(str[j*4+1]=='!')
				flag[1]++;
			if(str[j*4+2]=='!')
				flag[2]++;
			if(str[j*4+3]=='!')
				flag[3]++;
		}
		for(j=(len/4)*4;j<len;j++)
		{
			if(str[j]=='!')
			{
				if(j%4==1)
					flag[1]++;
				if(j%4==2)
					flag[2]++;
				if(j%4==3)
					flag[3]++;
			}
		}
		for(j=0;j<len;j++)
		{
			if(str[j]=='R')
			{
				ans[0]=flag[j%4];
				break;
			}
		}
		for(j=0;j<len;j++)
		{
			if(str[j]=='B')
			{
				ans[1]=flag[j%4];
				break;
			}
		}
		for(j=0;j<len;j++)
		{
			if(str[j]=='Y')
			{
				ans[2]=flag[j%4];
				break;
			}
		}
		for(j=0;j<len;j++)
		{
			if(str[j]=='G')
			{
				ans[3]=flag[j%4];
				break;
			}
		}
		printf("case #%d:\n%d %d %d %d\n",i,ans[0],ans[1],ans[2],ans[3]);
	}
	return 0;
}
