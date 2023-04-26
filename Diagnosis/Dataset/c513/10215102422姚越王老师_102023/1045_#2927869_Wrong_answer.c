#include<stdio.h>
#include<string.h>
#include<math.h>
int min(int a,int b)
{
	if(a<b)return a;
	else return b;
}
typedef struct{char str[110];char tmp[110];int cnt[110];} string;
string a[100001];

void get_record(const char* str,char* tmp,int* cnt)
{
	int len=strlen(str),i,j,k=0;
	for(i=0;i<len;i++)
		if(str[i]!=str[0])
		{
			tmp[k]=str[0];
			cnt[k++]=i;
			break;
		}
	i--;
	for(i;i<len;i++)	
	{
		if(str[i]!=str[i+1])
		{
			tmp[k]=str[i+1];
			for(j=i+1;j<len;++j)
				if(str[j]!=tmp[k])break;
			cnt[k++]=j-i;
			if(j==len)break;
			i=j-2;
		}
	}
	tmp[k]=0;
}


int main()
{
	char str[110];
	int n;scanf("%d",&n);
	int i,j,k;
	for(i=0;i<n;++i)
	{
		scanf("%s",a[i].str);
		get_record(a[i].str,a[i].tmp,a[i].cnt);
	}
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			if(j==i)continue;
			else
			{
				if(strcmp(a[i].tmp,a[j].tmp))
				{
					printf("%d",-1);
					return 0;
				}
			}
		}
	}
	int l=strlen(a[0].tmp);
	int b[110],cnt;
	int ans[110],ans1,ans2;
	for(i=0;i<l;++i)
	{
		cnt=0;ans1=ans2=0;
		for(j=0;j<n;++j)
			cnt+=a[j].cnt[i];
		if(!cnt%n)
		{
			for(j=0;j<n;++j)
				ans1+=abs(cnt/n-a[j].cnt[i]);
			ans[i]=ans1;
		}
		else
		{
			for(j=0;j<n;++j)
		    {
				ans1+=abs(cnt/n-a[j].cnt[i]);
				ans2+=abs(cnt/n+1-a[j].cnt[i]);}
			ans[i]=min(ans1,ans2);
		}
	}
	ans1=0;
	for(i=0;i<l;++i)
		ans1+=ans[i];
	printf("%d",ans1);
	return 0;
}