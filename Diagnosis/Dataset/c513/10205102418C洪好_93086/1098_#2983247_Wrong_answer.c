#include<stdio.h>
#include<string.h>
int main()
{
	int t;
	scanf("%d",&t);
	int i,j,k;
	int b[10][4];
	for(i=0;i<t;i++)
	{
		char s[100];
		for(j=0;j<4;j++)
			b[i][j]=0;
		scanf("%s",s);
		int len=strlen(s);
		//printf("%d\n",len);
		for(j=0;j<len/4;j++)
		{
			int flag1=0,flag2=0,flag3=0,flag4=0;
			for(k=0;k<4;k++)
			{
				if(s[j*4+k]=='R')
					flag1=1;
				if(s[j*4+k]=='B')
					flag2=1;
				if(s[j*4+k]=='Y')
					flag3=1;
				if(s[j*4+k]=='G')
					flag4=1;
			}
			if(flag1==0)
				b[i][0]++;
			if(flag2==0)
				b[i][1]++;
			if(flag3==0)
				b[i][2]++;
			if(flag4==0)
				b[i][3]++;
		}
		
	}
	for(i=0;i<t;i++)
		printf("%d %d %d %d\n",b[i][0],b[i][1],b[i][2],b[i][3]);
} 