#include<stdio.h>
#include<string.h>
void insert(char c,char *s,int i,char *a)
{
	int len=strlen(s),k;
	if(i==0)
	{
		a[0]=c;
		k=1;
		for(int j=0;j<len;j++)
		{
			a[k++]=s[j];
		}
		a[k]=0;
	}
	else if(i==len)
	{
		strcpy(a,s);
		a[len]=c;
		a[len+1]=0;
	}
	else
	{
		k=0;
		for(int j=0;j<i;j++)
		{
			a[k++]=s[j];
		}
		a[k++]=c;
		for(int j=i;j<len;j++)
		{
			a[k++]=s[j];
		}
		a[k]=0;
	}
}
int repeat(const char* s)
{
	if(strlen(s)==0)return 0;
	int flag=0,cnt=1,ans=0;
	for(int i=0;i<strlen(s)-1;i++)
	{
		if(s[i+1]==s[i])
		{
			if(flag==0)
			{
				flag=1;
				cnt++;
			}	
			else cnt++;
		}
		else if(flag==1){ans+=cnt;flag=0;cnt=1;}
	}
	if(flag==1){ans+=cnt;flag=0;cnt=1;}
	return ans;
}
void remove(char *s)
{
	while(repeat(s))
	{
		char a[110];
		//printf("in remove,s=%s,repeat(s)=%d\n",s,repeat(s));
		int flag=0,start,e;
		for(int i=0;i<strlen(s)-1;i++)
		{
			if(s[i+1]==s[i])
			{
				if(flag==0)
				{
					start=i;
					flag=1;
				}	
			}
			else if(flag==1){e=i;flag=0;break;}
		}
		if(flag==1){s[start]=0;}
		else
		{
			int k=0;
			for(int i=0;i<start;i++)a[k++]=s[i];
			for(int i=e+1;i<strlen(s);i++)a[k++]=s[i];
			a[k]=0;
			strcpy(s,a);
		}
	}
	return;
}
int max(int a,int b)
{
	if(a>b)return a;
	else return b;
}
int main()
{
	int T;scanf("%d\n",&T);
	for(int cnt=0;cnt<T;cnt++)
	{
		char s[110];
		scanf("%s\n",s);
		int len=strlen(s),dlen=0,ans=0;
		for(int i=0;i<=len;i++)
		{
			for(char c='A';c<='C';c++)
			{
				char str[110];
				insert(c,s,i,str);//在s字符串索引为i之前加上c字符； 
				remove(str);
				//printf("out of remove,str=%s\n",str);
				dlen=len-strlen(str);
				//printf("dlen=%d\n",dlen);
				ans=max(ans,dlen);
			}
		}
		printf("case #%d:\n%d\n",cnt,ans);
	}
	return 0;
}