#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
char a[151][5],chr[151][5];
typedef long long LL;
int Lchr=0,cnt,zancuncnt;
int num[150];
LL var[150][150],zancun[150],rearr[150],recnt;
int find()
{
	for(int i=1;i<=Lchr;i++)
	if(strcmp(chr[i],a[cnt])==0)
	return i;
	return 0;
}
int return_type=0;
int dfssig=0;
LL cal_first()
{
	dfssig++;
	LL cur_num=0,ans=0;
	while(a[--cnt][0]!='('&&cnt!=0)
	{
		if(a[cnt][0]>='a'&&a[cnt][0]<='z')
		{
			int findx=find();
			if(a[cnt-1][0]=='/')
			{
				if(a[cnt-2][0]=='-')
				{
					cur_num=0;
					for(int i=num[findx]-1;i>=1;i--)cur_num+=var[findx][i]-var[findx][i+1];
				}
				if(a[cnt-2][0]=='+')
				{
					cur_num=0;
					for(int i=num[findx];i>=1;i--)cur_num+=var[findx][i];
					cur_num*=2;
				}
				if(a[cnt-2][0]=='*')
				{
					cur_num=0;
					for(int i=num[findx]-1;i>=1;i--)cur_num+=var[findx][i+1]*var[findx][i];
				}
				num[findx]=1;var[findx][1]=cur_num;cnt-=2;
			}
			else if(num[findx]==1)
			{
				if(a[cnt+1][0]=='*')cur_num*=var[findx][1];
				else cur_num=var[findx][1];
				//printf("fuck");
			}
			else return_type=findx;
		}
		else if(a[cnt][0]=='*'&&a[cnt-1][0]>='a'&&a[cnt-1][0]<='z')
		{
			cnt--;int findx=find();
			if(num[findx]==1)cur_num*=var[cnt][1];
			else
			{
				for(int i=1;i<=num[findx];i++)rearr[++recnt]=var[findx][i]*cur_num;
				return_type=findx;
			}
		}
		else if(a[cnt][0]>='0'&&a[cnt][0]<='9')
		{
			if((a[cnt-1][0]>='0'&&a[cnt-1][0]<='9')||a[cnt-1][0]=='=')
			{
				zancuncnt=0;//printf("fuck");
				while(a[cnt][0]!='=')zancun[++zancuncnt]=atoll(a[cnt--]);--cnt;
				int findx=find();
				if(findx==0)findx=++Lchr;
				num[findx]=zancuncnt;//printf("%d %d\n",zancuncnt,findx);
				strcpy(chr[findx],a[cnt]);
				for(int i=1;i<=zancuncnt;i++)var[findx][i]=zancun[i];
				if(zancuncnt==1)cur_num=zancun[1];
				if(zancuncnt>=2)return_type=findx;
			} 
			else if(a[cnt+1][0]=='*')cur_num*=atoll(a[cnt]);
			else cur_num=atoll(a[cnt]);
		}
		else if(a[cnt][0]=='-')
		{
			if(a[cnt-1][0]>='a'&&a[cnt-1][0]<='z')
			{
				--cnt;int findx=find();
				if(num[findx]==1)
				{
					ans-=cur_num;cur_num=var[findx][1];
				}
				else
				{
					for(int i=1;i<=num[findx];i++)rearr[++recnt]=var[findx][i]-cur_num;
					return_type=findx;
				}
			}
			else ans-=cur_num;
		}
		else if(a[cnt][0]=='+')
		{
			if(a[cnt-1][0]>='a'&&a[cnt-1][0]<='z')
			{
				--cnt;int findx=find();
				if(num[findx]==1)
				{
					ans+=cur_num;cur_num=var[findx][1];
				}
				else
				{
					for(int i=1;i<=num[findx];i++)rearr[++recnt]=var[findx][i]+cur_num;
					return_type=findx;
				}
			}
			else ans+=cur_num;
		}
		else if(a[cnt][0]==')')
		{
			if(a[cnt+1][0]=='*')cur_num*=cal_first();
			else cur_num=cal_first();
		}
	}ans+=cur_num;
	if(return_type!=0&&dfssig==1)
	{
		if(recnt!=0)for(int i=recnt;i>=1;i--)printf("%lld ",rearr[i]);
		else for(int i=num[return_type];i>=1;i--)printf("%lld ",var[return_type][i]);
		printf("\n");
	}
	dfssig--;
	return ans;
}
int main()
{
	char c;
	int T;scanf("%d\n",&T);
	while(T--)
	{
		int ct=0;cnt=1;return_type=recnt=dfssig=0;
		while(c=getchar())
		{
			if(c==' '||c=='\n')
			{
				a[cnt][ct]=0;
				if(c=='\n')break;
				cnt++;ct=0;
				continue;
			}
			a[cnt][ct++]=c;
		}
		LL cur_num;++cnt;
		/*while(cnt>=1)
		{
			if(a[cnt][0]>='0'&&a[cnt][0]<='9')
			{
				if(a[cnt+1][0]=='*')cur_num*=atoll(a[cnt]);
				else cur_num=atoll(a[cnt]);
			}
			if(a[cnt][0]=='-')ans-=cur_num;
			if(a[cnt][0]=='+')ans+=cur_num;
			if(a[cnt][0]==')')
			{
				if(a[cnt+1][0]=='*')cur_num*=cal_first();
				else cur_num=cal_first();
			}
			--cnt;
		}ans+=cur_num;*/
		LL ans=cal_first();
		if(return_type==0)printf("%lld\n",ans);
	}
} 