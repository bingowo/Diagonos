#include<stdio.h>
#include<string.h>
int ishex(char c)
{
	//printf("in ishex,char c=%c\n",c);
	if((c>='a'&&c<='f')||(c>='0'&&c<='9'))return 1;
	else return 0;
}
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
	//printf("in s2h,a=%s\n",a);
	int len=strlen(a);
	int i,b[len];
	for(i=0;i<len;i++)
	{
		if(a[i]>='0'&&a[i]<='9')b[i]=a[i]-48;
		else b[i]=a[i]-87;
		//printf("%d ",b[i]);
	}
	unsigned int ans=0;
	for(i=len-1;i>=0;i--)
	{
		ans+=b[i]*pow(16,len-1-i);
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
	}//计算这串字符中有几个十六进制 
	//printf("cnt=%d\n",cnt) ;
	unsigned int a[cnt];//a用来存储每个十六进制字符串对应的16进制 
	int b[cnt];//b数组用于存储十六进制开始的位置0 
	for(i=0;i<len;i++)
	{
		if(s[i]=='0'&&s[i+1]=='x')b[j++]=i;
	}//记录每个16进制的开始位置 
	//for(i=0;i<cnt;i++)printf("%d ",b[i]);
	//printf("\n");
	for(i=0;i<cnt;i++)
	{
		char str[1010];
		k=0;
		if(i!=cnt-1)
		{
			for(j=b[i]+2;j<b[i+1];j++)
			{
				if(ishex(s[j]))str[k++]=s[j];
				else break;
			}
			if(k>0)str[k]=0;
			else printf("%d ",-1);
		}
		else
		{
			for(j=b[i]+2;j<len;j++)
			{
				if(ishex(s[j]))str[k++]=s[j];
				else break;
			}
			if(k>0)str[k]=0;
			else printf("%d ",-1);				
		}
		//printf("str=%s\n",str);
		printf("%u ",s2h(str));
	}
	return 0;
}