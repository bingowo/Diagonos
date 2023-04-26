#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int prime[26]={97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
void Readnumber(char *s,int *a)
{
	int n=strlen(s)-1,cnt=0;
	for(n;n>=0;n--)
	{
		if(s[n]==',')
		{
			char* p=s+n+1;
			char num[1005];
			strcpy(num,p);
			a[25-cnt]=atoi(num);
			cnt++;
			s[n]=0;
		}
	}
	a[25-cnt]=atoi(s);
}
void ADD(int* a,int* b,int* c)
{
	int carry=0;
	int i;
	for(i=25;i>=0;i--)
	{
		c[i]=a[i]+b[i]+carry;;
		if(c[i]>=prime[i])
		{
			c[i]%=prime[i];
			carry=1;
		}
		else carry=0;
	}
	for(i=0;i<26;i++)if(c[i]!=0)break;
	for(i;i<26;i++)
	{
		if(c[i]!=25)printf("%d,",c[i]);
		else printf("%d\n",c[i]);
	}
}
int main()
{
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		char s[100];
		int a[26]={0},b[26]={0},c[26]={0};
		scanf("%s",s);
		Readnumber(s,a);
		scanf("%s",s);
		Readnumber(s,b);
		printf("case #%d:\n",i);
		ADD(a,b,c);
	}
	return 0;
}