#include<stdio.h>
#include<string.h>
long long n,m,s;
long long trans(char* N)//读取n反数m 
{
	long long int temp1=0,temp2=0;
	int len=strlen(N);
	for(int i=strlen(N)-1;i>=0;i--)
	{
		temp1*=10;
		temp1+=(N[i]-'0');
	}
	m=temp1;
	for(int j=0;j<strlen(N);j++)
	{
		temp2*=10;
		temp2+=(N[j]-'0');
	}
	n=temp2;
}
int back(long long s)//判断是否为回文数 
{
	long long b=0,d=0;
	b=s;
	while(b)
	{
		d*=10;
	    d+=b%10;
	    b/=10;
	}
	if(d==s)
	{
		return 0;
	}
	else return 1;
}
int main()
{
	char N[10]={0};
	scanf("%s",N);
	trans(N);
	int cnt=0;
	s=n+m;
	cnt++;
	while(back(s))
	{
		long long k=s;
		char s1[20]={0},s2[20]={0};
		int j=0;
		while(k>0)
		{
			s1[j++]=(k%10)+'0';//是倒序的 
			k/=10; 
		}
		int t=0; 
		j--;
		while(j>=0)//整数转成字符串 
		{
			s2[t++]=s1[j];
			j--;
		}
		trans(s2);
		s=n+m;
		cnt++;
	}
	printf("%d %lld",cnt,s);
}