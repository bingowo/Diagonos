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
LL var[150][150],zancun[150];
int find()
{
	for(int i=1;i<=Lchr;i++)
	if(strcmp(chr[i],a[cnt])==0)
	return i;
	return 0;
}
int return_type=0;
int vec[150],vecnum=0;
LL cal_first()
{
	
	LL cur_num=0,ans=0;
	while(a[--cnt][0]!='('&&cnt!=0)
	{
		if(a[cnt][0]>='a'&&a[cnt][0]<='z')
		{
			int findx=find();//printf("dick %d %lld\n",findx,var[findx][1]);
			if(num[findx]==1)
			{
				//printf("%lld %lld\n",cur_num,ans);
				if(a[cnt+1][0]=='*'){cur_num=var[findx][1]*(cur_num+ans);ans=0;}
				else cur_num=var[findx][1];
			}
			if(a[cnt-1][0]=='/')
			{
				cnt-=2;
				if(a[cnt][0]=='-')
				{
					cur_num=var[findx][num[findx]];//printf("%d %d %d %d\n",var[findx][1],var[findx][2],var[findx][3],num[findx]);
					for(int i=num[findx]-1;i>=1;i--)cur_num=var[findx][i]-cur_num;
				}
				else if(a[cnt][0]=='+')
				{
					cur_num=var[findx][num[findx]];
					for(int i=num[findx]-1;i>=1;i--)cur_num+=var[findx][i];
				}
				else 
				{
					cur_num=var[findx][num[findx]];
					for(int i=num[findx]-1;i>=1;i--)cur_num*=var[findx][i];
				}
			}
			if(num[findx]>1&&a[cnt][0]>='a'&&a[cnt][0]<='z')
			{
				for(int i=1;i<=num[findx];i++)vec[++vecnum]=var[findx][i];
				return_type=findx;
			}//printf("fuck %d\n",return_type);
		}
		else if(a[cnt][0]>='0'&&a[cnt][0]<='9')
		{
			if((a[cnt-1][0]>='0'&&a[cnt-1][0]<='9')||a[cnt-1][0]=='=')
			{
				zancuncnt=0;
				while(a[cnt][0]!='=')zancun[++zancuncnt]=atoll(a[cnt--]);--cnt;
				int findx=find();
				if(findx==0)
				{
					findx=++Lchr;
					strcpy(chr[Lchr],a[cnt]);
				}
				num[findx]=zancuncnt;
				for(int i=1;i<=zancuncnt;i++)var[findx][i]=zancun[zancuncnt-i+1];
				if(zancuncnt==1)cur_num=zancun[1];
				if(zancuncnt>=2){for(int i=1;i<=num[findx];i++)vec[++vecnum]=var[findx][i];return_type=findx;}
			} 
			else if(a[cnt+1][0]=='*'){cur_num=atoll(a[cnt])*(cur_num+ans);ans=0;}//{ans*=atoll(a[cnt]);cur_num=0;}
			else cur_num=atoll(a[cnt]);
		}
		else if(a[cnt][0]=='-')
		{
			if(a[cnt-1][0]>='a'&&a[cnt-1][0]<='z')
			{
				--cnt;int findx=find();
				if(num[findx]==1)
				{
					ans+=cur_num;ans=-ans;cur_num=var[findx][1];
				}
				else
				{
					for(int i=1;i<=num[findx];i++)vec[++vecnum]=var[findx][i]-cur_num;
					return_type=findx;
				}
			}
			else 
			{
				ans+=cur_num;
				ans=-ans;
			}
		}
		else if(a[cnt][0]=='+')
		{
			if(a[cnt-1][0]>='a'&&a[cnt-1][0]<='z')
			{
				--cnt;int findx=find();//printf("fuck %d\n",findx);
				if(num[findx]==1)
				{
					ans+=cur_num;cur_num=var[findx][1];
				}
				else
				{
					for(int i=1;i<=num[findx];i++)vec[++vecnum]=var[findx][i]+cur_num;
					return_type=findx;
				}
			}
			else ans+=cur_num;
		}
		else if(a[cnt][0]=='*')
		{
			if(a[cnt-1][0]>='a'&&a[cnt-1][0]<='z')
			{
				--cnt;int findx=find();
				if(num[findx]>1)
				{
					for(int i=1;i<=num[findx];i++)vec[++vecnum]=var[findx][i]*cur_num;
					return_type=findx;
				}
				else ++cnt;
			}
		}
		else if(a[cnt][0]==')')
		{
			if(a[cnt+1][0]=='*')cur_num*=cal_first();//{ans*=cal_first();cur_num=0;}
			else cur_num=cal_first();
		}
		else if(a[cnt][0]=='=')
		{
			--cnt;int findx=find();
			if(findx==0)
			{
				findx=++Lchr;
				strcpy(chr[Lchr],a[cnt]);
			}
			num[findx]=1;var[findx][1]=cur_num;findx=find();//printf("fuck %lld %lld\n",cur_num,findx);
		}
	}ans+=cur_num;
	if(return_type!=0)
	{
		for(int i=1;i<=vecnum;i++)printf("%lld ",vec[i]);
		printf("\n");
	}
	return ans;
}
int main()
{
	char c;
	int T;scanf("%d\n",&T);
	while(T--)
	{
		int ct=0;cnt=1;vecnum=return_type=0;
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
		long long output=cal_first();
		if(return_type==0)printf("%lld\n",output);
	}
} 