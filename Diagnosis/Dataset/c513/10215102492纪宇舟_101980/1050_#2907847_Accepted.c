#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int MAX(int x,int y)
{
	if(x>y)return x;return y;
}
int main()
{
	int ct=0,T;scanf("%d\n",&T);
	char s1[80],s2[80],s[80];
	while(T--)
	{
		int fron1=-1,fron2=-1,last1=-1,last2=-1;
		scanf("%s%s%s",s1,s2,s);
		int n1=strlen(s1),n2=strlen(s2),n=strlen(s);
		for(int i=0;i<n;i++)
		{
			if(fron1==-1&&s[i]==s1[0])
			{
				for(int j=0;j<n1;j++)
				{
					if(i+j>=n||s[i+j]!=s1[j])break;
					if(j==n1-1)fron1=i;
				}
			}
			if(fron2==-1&&s[i]==s2[0])
			{
				for(int j=0;j<n2;j++)
				{
					if(i+j>=n||s[i+j]!=s2[j])break;
					if(j==n2-1)fron2=i;
				}
			}
		}
		for(int i=n-1;i>=0;i--)
		{
			if(last1==-1&&s[i]==s1[0])
			{
				for(int j=0;j<n1;j++)
				{
					if(i+j>=n||s[i+j]!=s1[j])break;
					if(j==n1-1)last1=i;
				}
			}
			if(last2==-1&&s[i]==s2[0])
			{
				for(int j=0;j<n2;j++)
				{
					if(i+j>=n||s[i+j]!=s2[j])break;
					if(j==n2-1)last2=i;
				}
			}
		}
		int ans=0;
		if(fron1!=-1&&last2!=-1)ans=MAX(ans,last2-(fron1+n1));
		if(fron2!=-1&&last1!=-1)ans=MAX(ans,last1-(fron2+n2));
		printf("case #%d:\n",ct++);
		printf("%d\n",ans);
	}
	return 0;
}