#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int T,ct=0;scanf("%d",&T);
	char ipt[1005];
	int ans[1005];
	while(T--)
	{
		scanf("%s",ipt);
		int n=strlen(ipt);
		int maxm=0;
		memset(ans,0,sizeof(ans));
		for(int i=n-1;i>=2;i--)
		{
			int mod=ipt[i]-'0';//进位 
			int pos=0,x;
			while(pos<maxm||mod>0)//超出位数进位继续运算 
			{
				if(pos>maxm)x=mod*10;
				else x=mod*10+ans[pos];
				mod=x%8;ans[pos++]=x/8;
			}
			maxm=pos;
		}
		printf("case #%d:\n0.",ct++);
		for(int i=0;i<maxm;i++)printf("%d",ans[i]);
		printf("\n");
	} 
	return 0;
} 