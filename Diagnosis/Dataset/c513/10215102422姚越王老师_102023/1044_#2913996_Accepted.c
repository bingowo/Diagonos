#include<stdio.h>
#include<string.h>
int ishex(char c)
{
	if((c>='a'&&c<='f')||(c>='0'&&c<='9'))return 1;
	else return 0;
}//判断一个字符是不是十六进制的合法字符 
unsigned int pow(int a,int p)
{
	unsigned int ans=1;
	while(p>0)
	{
		ans*=a;
		p--;
	}
	return ans;
}//求16的次方 
unsigned int s2h(const char* a)
{
	int len=strlen(a);
	int i,b[len];
	for(i=0;i<len;i++)
	{
		if(a[i]>='0'&&a[i]<='9')b[i]=a[i]-48;
		else b[i]=a[i]-87;
	}
	unsigned int ans=0;
	for(i=len-1;i>=0;i--)ans+=b[i]*pow(16,len-1-i);
	return ans;
}//将一串字符转化为unsigned int 
int main()
{
	char s[100010];
	scanf("%s",s);
	int len=strlen(s),i,j=0,cnt=0; 
	for(i=0;i<=len-3;i++)if(s[i]=='0'&&s[i+1]=='x'&&ishex(s[i+2]))cnt++;//计算这串字符中有几个十六进制 
	if(cnt==0){printf("%d",-1);return 0;}//没有合法字符就输出-1 
	int b[cnt];//b数组用于存储十六进制开始的位置0 
	for(i=0;i<=len-3;i++)if(s[i]=='0'&&s[i+1]=='x'&&ishex(s[i+2]))b[j++]=i;//记录每个16进制的开始位置
	//for(i=0;i<cnt;i++)printf("%d ",b[i]);
	//printf("\n");
	for(i=0;i<cnt;i++)
	{
		char str[100010];j=0;
		int p=b[i]+2,q=i==cnt-1?len-1:b[i+1]-1;
		for(p;p<=q;p++)
		{
			if(ishex(s[p]))str[j++]=s[p];
			else break;
		}
		str[j]=0;
		//printf("%s\n",str);
		printf("%u ",s2h(str));
	}
	return 0;
}