#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int len,cnt;
char ori[105],ans[800];
int main()
{
	int tran[50],detran[50];
	int ct=0,T,sum;scanf("%d",&T);
	while(T--)
	{
		len=cnt=0;
		scanf("%s",ori);
		int n=strlen(ori);
		for(int i=0;i<n;i++)
		{
			int x=ori[i];
			int CT=0;
			while(x||CT<8)
			{
				detran[CT++]=x%2;x/=2;
			}
			for(int j=7;j>=0;j--)
			{
				tran[cnt++]=detran[j];//printf("%d ",tran[cnt-1]);
			}//printf("\n");
			if((i+1)%3==0||i==n-1)
			{
				while(cnt%6!=0)tran[cnt++]=0;
				sum=0;
				for(int j=0;j<6;j++)
				{
					sum=sum*2+tran[j];
					//printf("%d ",tran[j]);
				}if(sum<=25)sum+='A';else if(sum<=51)sum=sum-26+'a';else if(sum<=61)sum=sum-52+'0';else if(sum==62)sum='+';else sum='/';ans[len++]=(char)sum;
				sum=0;
				if(cnt>=12)
				{
					for(int j=6;j<12;j++)
					{
						sum=sum*2+tran[j];//printf("%d ",tran[j]);
					}//printf("\n");//printf("%d\n",sum);
					if(sum<=25)sum+='A';else if(sum<=51)sum=sum-26+'a';else if(sum<=61)sum=sum-52+'0';else if(sum==62)sum='+';else sum='/';
				}
				else sum='=';ans[len++]=(char)sum;
				sum=0;
				if(cnt>=18)
				{
					for(int j=12;j<18;j++)
					{
						sum=sum*2+tran[j];//printf("%d ",tran[j]);
					}//printf("\n");//printf("%d\n",sum);
					if(sum<=25)sum+='A';else if(sum<=51)sum=sum-26+'a';else if(sum<=61)sum=sum-52+'0';else if(sum==62)sum='+';else sum='/';
				}
				else sum='=';ans[len++]=(char)sum;
				sum=0;
				if(cnt>=24)
				{
					for(int j=18;j<24;j++)
					{
						sum=sum*2+tran[j];//printf("%d ",tran[j]);
					}//printf("\n");//printf("%d\n",sum);
					if(sum<=25)sum+='A';else if(sum<=51)sum=sum-26+'a';else if(sum<=61)sum=sum-52+'0';else if(sum==62)sum='+';else sum='/';
				}
				else sum='=';ans[len++]=(char)sum;
				cnt=0;//printf("%d\n",sum);
			}
		}
		ans[len]=0;
		printf("case #%d:\n",ct++);
		printf("%s\n",ans);
	}
	return 0;
}