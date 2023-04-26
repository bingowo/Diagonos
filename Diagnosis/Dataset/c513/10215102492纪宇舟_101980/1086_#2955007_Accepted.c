#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int a1[505],a2[505],b1[505],b2[505];
int MAX(int x,int y)
{
	if(x>y)return x;return y;
}
int CMP()
{
	if(a1[0]>b1[0])return  1;
	if(a1[0]<b1[0])return -1;
	for(int i=1;i<=a1[0];i++)
	if(a1[i]>b1[i])return 1;
	else if(a1[i]<b1[i])return -1;
	for(int i=1;i<=MAX(a2[0],b2[0]);i++)
	if(a2[i]>b2[i])return 1;
	else if(a2[i]<b2[i])return -1;
	return 0;
}
int main()
{
	char s[505];
	scanf("%s",s);
	int N,n=strlen(s),flag=0;
	memset(a1,0,sizeof(a1));memset(a2,0,sizeof(a2));
	memset(b1,0,sizeof(b1));memset(b2,0,sizeof(b2));
	for(int i=0;i<n;i++)
	{
		if(s[i]=='.'){flag=1;continue;}
		if(!flag)a1[++a1[0]]=s[i]-'0';
		else a2[++a2[0]]=s[i]-'0';
	}
	scanf("%s",s);n=strlen(s),flag=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='.'){flag=1;continue;}
		if(!flag)b1[++b1[0]]=s[i]-'0';
		else b2[++b2[0]]=s[i]-'0';
	}
	scanf("%d",&N);int sig=0,carry=0;
	if(CMP()==-1)
	{
		sig=1;int t,L;
		L=MAX(a1[0],b1[0]);
		for(int i=0;i<=L;i++){t=a1[i];a1[i]=b1[i];b1[i]=t;}
		L=MAX(a2[0],b2[0]);
		for(int i=0;i<=L;i++){t=a2[i];a2[i]=b2[i];b2[i]=t;}    
	}
	//for(int i=1;i<=a2[0];i++)printf("%d",a2[i]);printf("\n");
	//for(int i=1;i<=b2[0];i++)printf("%d",b2[i]);printf("\n");
	for(int i=MAX(N+1,MAX(a2[0],b2[0]));i>=1;i--)
	{
		a2[i]-=b2[i];
		if(a2[i]<0)
		{
			a2[i]+=10;
			if(i==1)
			{
				carry=1;break;
			}
			a2[i-1]-=1;
		}
	}
	//for(int i=1;i<=a1[0]/2;i++){int t=a1[i];a1[i]=a1[a1[0]-i+1];a1[a1[0]-i+1]=t;}
	//for(int i=1;i<=b1[0]/2;i++){int t=b1[i];b1[i]=b1[b1[0]-i+1];b1[b1[0]-i+1]=t;}
	//if(carry)printf("fuck");
	if(carry)a1[a1[0]]-=1;int pos=b1[0];b1[0]=0;
	for(int i=a1[0];i>=1;i--)
	{
		if(pos==-1)pos=0;
		a1[i]-=b1[pos--];//printf("%d\n",a1[i]);
		if(a1[i]<0)
		{
			a1[i]+=10;
			a1[i-1]-=1;
		}
	}
	if(a2[N+1]>4)++a2[N];carry=0;
	for(int i=N;i>=1;i--)
	{
		a2[i]+=carry;
		carry=a2[i]/10;
		a2[i]%=10;
	}
	for(int i=a1[0];i>=1;i--)
	{
		a1[i]+=carry;
		carry=a1[i]/10;
		a1[i]%=10;
	}
	pos=a1[0];if(sig)printf("-");
	if(carry)printf("1");
	for(int i=1;i<=a1[0];i++)
	if(a1[i]!=0){pos=i;break;}
	for(int i=pos;i<=a1[0];i++)printf("%d",a1[i]);
	printf(".");
	for(int i=1;i<=N;i++)printf("%d",a2[i]);
	return 0;
}