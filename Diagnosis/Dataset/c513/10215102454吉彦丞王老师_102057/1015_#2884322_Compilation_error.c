#include<stdio.h>
#include<string.h>
void Readnumber(char s[],int a[])
{
	int l=strlen(s);
	for(int i=0;i<l;i++)
	{
		a[i]=s[i]-'0';
	}
	return; 
}
int max(int a,int b)
{
	if(a>=b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
int min(int a,int b)
{
	if(a>=b)
	{
		return b;
	}
	else
	{
		return a;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		char s[100];
		int a[26]={0};
		int b[26]={0};
		scanf("%s",&s);
		int la=strlen(s);
		Readnumber(s,a);
		scanf("%s",&s);
		int lb=strlen(s);
		Readnumber(s,b);
		int prime[26]={97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
		int lc=max(la,lb)+1;
		int ll=min(la,lb);
		int c[lc]={0};
		int deep=(a[la-1]+b[lb-1])/prime[25];
		c[lc-1]=(a[la-1]+b[lb-1])%prime[25];
		for(int j=1;j<ll;j++)
		{
			c[lc-j-1]=(a[la-j-1]+b[lb-j-1]+deep)%prime[25-i];
			deep=(a[la-j-1]+b[lb-j-1]+deep)/prime[25-j];
		}
		
		
		
		printf("case #%d:\n",i);
	}
