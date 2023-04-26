#include<stdio.h>
#include<string.h>
unsigned int pow(int a,int p)
{
	unsigned int ans=1;
	while(p>0)
	{
		ans*=a;
		p--;
	}
	return ans;
}
unsigned int s2h(const char* a)
{
	char  s[1010];
	int i,j;
	for(i=2,j=0;i<strlen(a);i++)
	{
		if((a[i]>='0'&&a[i]<='9')||(a[i]>='a'&&a[i]<='f'))s[j++]=a[i];
	}
	s[j]=0;
	int b[j];
	for(j=0;j<strlen(s);j++)
	{
		if(s[j]>='0'&&s[j]<='9')b[j]=s[j]-48;
		else b[j]=s[j]-87;
	}
	unsigned int ans;
	i=j-1;
	j--;
	while(i>=0)
	{
		ans+=b[i]*pow(16,j-i);
		i--;
	}
	return ans;
}
int main()
{
	char s[1010];
	scanf("%s",s);
	int len=strlen(s),i,j=0,k,cnt=0;
	for(i=0;i<len;i++)
	{
		if(s[i]=='0'&&s[i+1]=='x')cnt++;
	}
	if(cnt==0)
	{
		printf("%d",-1);
		return 0;
	}
	unsigned int a[cnt];//a用来存储每个十六进制字符串对应的16进制 
	int b[cnt];//b数组用于存储十六进制开始的位置0 
	for(i=0;i<len;i++)
	{
		if(s[i]=='0'&&s[i+1]=='x')b[j++]=i;
	}
	for(i=0;i<cnt;i++)
	{
		char str[1010];
		k=0;
		if(i!=cnt-1)
		{
			for(j=b[i];j<b[i+1];j++)
			{
				str[k++]=s[j];
			}
			str[k]=0;
		}
		else
		{
			for(j=b[i];j<len;j++)
			{
				str[k++]=s[j];
			}
			str[k]=0;
		}
		//printf("%s\n",str);
		printf("%u ",s2h(str));
	}
	return 0;
}