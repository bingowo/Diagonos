#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[1000];
long long d[1111],s1[1000];
long long num(char s[],long long begin,long long end)
{
	long long ans=0;
	for(long long i=begin;i<=end;i++)
	{
		ans*=10;
		ans+=s[i];
	}
	return ans;
}
int main()
{
	long long a=0,b=0,nowa,nowb; 
	long long ans1=0,ans2=0,flag=1;
	//int pa=-1,pb=-1;
	gets(s);
	long long l=strlen(s);
	for(long long i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9') s[i]=s[i]-'0';	
	}
	if(s[l-1]=='i')
	{
		if(s[l-2]=='+'||s[l-2]=='-')
		{
			if(s[l-2]=='+') b=1;
			if(s[l-2]=='-') b=-1;
			if(l-2!=0)
			{
				if(s[0]=='-') a=-num(s,1,l-3);
				else a=num(s,0,l-3);
			}
		}
		else
		{
			for(long long j=l-1;j>=0;j--)
			{
				if(s[j]=='+')
				{
					if(s[0]=='-')
					{
						a=-num(s,1,j-1);
						b=num(s,j+1,l-2);
					} 
					else a=num(s,0,j-1);
					b=num(s,j+1,l-2);
					flag=2;
				}
				if(s[j]=='-'&&flag==1)
				{
					if(j==0)
					{
						a=0;
						b=-num(s,1,l-2);
					}
					else
					{
						if(s[0]=='-') a=-num(s,1,j-1);
						else a=num(s,0,j-1);
						b=-num(s,j+1,l-2);
					}
					flag=3;
				}
			}
			if(flag==1) b=num(s,0,l-2);
		} 			
	}	
	else
	{
		if(s[0]=='-') a=-num(s,1,l-1);
		else a=num(s,0,l-1);
	}
	if(l==1&&s[0]=='i') b=1;
	if(a==0&&b==0) printf("0");	//cout<<"a="<<a<<"b="<<b<<endl;
	long long m=1;
	while(a!=0||b!=0)
	{
		nowa=a%2;//cout<<"nowa="<<nowa<<endl;
		nowb=b%2;//cout<<"nowb="<<nowb<<endl; cout<<endl;
		d[m]=(nowa&1)^(nowb&1);//cout<<m<<"="<<d[m]<<endl;
		long long tempa=-a+b,tempb=-a-b;
		a=tempa;
		b=tempb;
		if(a%2==1||a%2==-1)
		{
			a++;
			b++;
		}
		a/=2;
		b/=2;//cout<<"a="<<a<<"b="<<b<<endl;
		m++;
	}
	for(long long i=m-1;i>0;i--) printf("%d",d[i]);
	return 0;
	
}


