#include<stdio.h>
#include<string.h>
int digit(int n)
{
	int cnt=0;
	while(n)
	{
		n/=10;
		cnt++;
	}
	return cnt;
}
int main()
{
	char s[1005];
	int a[100];
	scanf("%s",s);
	int cnt=0;
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]=='(')a[cnt++]=-1;
		else if(s[i]=='I')a[cnt++]=1;
		else if(s[i]=='V')a[cnt++]=5;
		else if(s[i]=='X')a[cnt++]=10;
		else if(s[i]=='L')a[cnt++]=50;
		else if(s[i]=='C')a[cnt++]=100;
		else if(s[i]=='D')a[cnt++]=500;
		else if(s[i]=='M')a[cnt++]=1000;
		else a[cnt++]=-2;
	}
	//for(int i=0;i<cnt;i++)printf("%d,",a[i]);
	//printf("\n");
	int mul=1,mov=0,flag=0;
	long long sum=0;
	for(int i=cnt-1;i>=0;i--)
	{
		if(a[i]==-2)
		{
			mul*=1000;
			int j;
			for(j=i-1;;j--)
			{
				if(a[j]==-2)mul*=1000;
 				else break;
			}
			mov=i-j;
			i=j+1;
			flag=1;//要乘;	
			//printf("i=%d,j=%d,mov=%d,flag=%d,mul=%d\n",i,j,mov,flag,mul); 
		}
		else if(flag)//第一次扫到不是右括号 
		{
			int tmp=0;
			tmp+=a[i];
			i--;
			int j;
			for(j=i;;j--)
			{
				if(a[j]==-1)
				{
					sum+=tmp*mul;
					mul=1;flag=0;
					i=j;
					i-=(mov-1);
					mov=0;
					break;
				}
				else if(a[j]>0&&a[j]<tmp)
				{
					if(a[j]==1||a[j]==10||a[j]==50)tmp-=a[j];
					else tmp+=a[j];
				}
				else if(a[j]>0)tmp+=a[j];
				//printf("j=%d,mov=%d,flag=%d,mul=%d\n",j,mov,flag,mul); 
			}
		}
		else//flag=0&&a[i]>0
		{
			if(a[i]<sum)
			{
				if((digit(a[i])==digit(sum)-1)&&(a[i]=='I'||a[i]=='X'||a[i]=='C'))sum-=a[i];
				else sum+=a[i];
			}
			else
			{
				sum+=a[i];
			}
		}
	}
	printf("%lld",sum);
	return 0;
}