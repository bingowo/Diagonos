#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int n,ans,tab[101];
char ori[101],tran[101];
void cal()
{
	int sum=0,sig;
	memset(tab,0,sizeof(tab));
	char last;int last_pos;
	while(1)
	{
		last=0;sig=0;
		for(int i=0;i<=n;i++)
		{
			if(tab[i]==1)continue;
			if(tran[i]==last)
			{
				sig=1;
				if(last_pos!=-1)
				{
					sum+=2;
					tab[last_pos]=tab[i]=1;
					last_pos=-1;
				}
				else 
				{
					sum+=1;tab[i]=1;
				}
			}
			else 
			{
				last=tran[i];last_pos=i;
			}
		}
		if(sig==0)break;
	}
	if(sum>ans)ans=sum;
}
int main()
{
	int ct=0,T,cnt;scanf("%d",&T);
	while(T--)
	{
		ans=0;
		scanf("%s",ori);
		n=strlen(ori);
		for(int i=0;i<=n;i++)
		{
			cnt=0;tran[i]='A';
			for(int j=0;j<n;j++)
			{
				if(cnt==i)cnt++;
				tran[cnt++]=ori[j];
			}cal();
			cnt=0;tran[i]='B';
			for(int j=0;j<n;j++)
			{
				if(cnt==i)cnt++;
				tran[cnt++]=ori[j];
			}cal();
			cnt=0;tran[i]='C';
			for(int j=0;j<n;j++)
			{
				if(cnt==i)cnt++;
				tran[cnt++]=ori[j];
			}cal();
		}
		printf("case #%d:\n",ct++);
		printf("%d\n",ans);
	}
	return 0;
} 