#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	int T;
	scanf("%d",&T);
	for(int t=0;t<T;t++)
	{
		printf("case #%d:\n",t);
		int cnt=0;
		char ans[1000];
		for(int i=8;i>=0;i--)
		{
			int a,sig=0;
			scanf("%d",&a);
			if(a==0)
			{
				if(i==0)
					ans[cnt++]='0';
				else
					continue;
			}
			else if(a<0)
			{
				if(sig==1)
					ans[cnt++]='-';
				a=-a;
				ans[cnt++]=a-'0';
				sig=1;
				if(i>0)
				{
					ans[cnt++]='x';
					if(i>1)
					{
						ans[cnt++]='^';
						ans[cnt++]=i-'0';
					}
				}
			}
			else
			{
				if(sig==1)
					ans[cnt++]='+';
				a=-a;
				ans[cnt++]=a-'0';
				sig=1;
				if(i>0)
				{
					ans[cnt++]='x';
					if(i>1)
					{
						ans[cnt++]='^';
						ans[cnt++]=i-'0';
					}
				}
			}
		}
		ans[cnt]='\0';
		printf("%s\n",ans);
	}
	return 0;
 } 