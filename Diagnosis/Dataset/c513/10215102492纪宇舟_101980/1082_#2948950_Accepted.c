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
	scanf("%d",&N);int carry=0;
	for(int i=MAX(N+1,MAX(a2[0],b2[0]));i>=1;i--)
	{
		a2[i]+=carry+b2[i];
		carry=a2[i]/10;
		a2[i]%=10;
		if(i==N+1&&a2[i]>=5)carry++;
	}
	for(int i=1;i<=a1[0]/2;i++){int t=a1[i];a1[i]=a1[a1[0]-i+1];a1[a1[0]-i+1]=t;}
	for(int i=1;i<=b1[0]/2;i++){int t=b1[i];b1[i]=b1[b1[0]-i+1];b1[b1[0]-i+1]=t;}
	for(int i=1;i<=MAX(a1[0]+1,b1[0]+1);i++)
	{
		a1[i]+=carry+b1[i];
		carry=a1[i]/10;
		a1[i]%=10;
	}
	int pos=1;
	for(int i=MAX(a1[0]+1,b1[0]+1);i>=1;i--)
	if(a1[i]!=0){pos=i;break;}
	for(int i=pos;i>=1;i--)printf("%d",a1[i]);
	printf(".");
	for(int i=1;i<=N;i++)printf("%d",a2[i]);
	return 0;
}