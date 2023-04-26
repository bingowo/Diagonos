#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int prime[26]={97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
char chr1[55],chr2[55];
int ans[26];
int main()
{
	int ct=0,T;scanf("%d",&T);
	while(T--)
	{
		int cnt1=0,cnt2=0,x=0;
		scanf("%s%s",chr1,chr2);
		memset(ans,0,sizeof(ans));
		int l1=1,l2=1;
		int leth1=strlen(chr1),leth2=strlen(chr2);
		for(int i=0;i<leth1;i++)if(chr1[i]==',')++l1;
		for(int i=0;i<leth2;i++)if(chr2[i]==',')++l2;
		//printf("l1=%d l2=%d\n",l1,l2);
		for(int i=0;i<leth1;i++)
		if(chr1[i]!=',')
		{
			x=x*10+chr1[i]-'0';
		}
		else 
		{
			++cnt1;ans[25-l1+cnt1]+=x;x=0;
		}++cnt1;ans[25-l1+cnt1]+=x;x=0;
		for(int i=0;i<leth2;i++)
		if(chr2[i]!=',')
		{
			x=x*10+chr2[i]-'0';
		}
		else 
		{
			++cnt2;ans[25-l2+cnt2]+=x;x=0;
		}++cnt2;ans[25-l2+cnt2]+=x;x=0;
		//for(int i=1;i<=25;i++){printf("%d,",ans[i]);if(i==25)printf("\n");}
		for(int i=25;i>=1;i--)
		if(ans[i]>=prime[i])
		{
			ans[i-1]+=ans[i]/prime[i];ans[i]%=prime[i];
		}
		printf("case #%d:\n",ct++);
		int flag=0;
		for(int i=1;i<=25;i++)
		{
			if(ans[i]!=0)flag=1;
			if(flag)
			{
				printf("%d",ans[i]);
				if(i!=25)printf(",");
				else printf("\n");
			}
		}
	}
	return 0;
}