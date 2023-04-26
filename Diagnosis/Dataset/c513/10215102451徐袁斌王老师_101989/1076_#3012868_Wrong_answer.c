#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int a[100],ans=0;
		for(int k=0;k<100;k++) a[k]=0;
		char s[101];
		scanf("%s",s);
		int j=0;
		for(int k=0;s[k]!='\0';k++)
		{
			if(s[k]=='{')
			{
				if(j==0||a[j-1]==3)
				{
					a[j]=1;j++;
				}
				else {ans++;break;}
			}
			else if(s[k]=='[')
			{
				if(j==0||a[j-1]==1)
				{
					a[j]=2;j++;
				}
				else
				{
					ans++;break;
				}
			}
			else if(s[k]=='(')
			{
				if(j==0||a[j-1]==2)
				{
					a[j]=3;j++;
				}
				else
				{
					ans++;break;
				}
			}
			else if(s[k]=='}')
			{
				if(a[j-1]==1)
				{
					a[j-1]=0;j--;
				}
				else {ans++;break;}
			}
			else if(s[k]==']')
			{
				if(a[j-1]==2)
				{
					a[j-1]=0;j--;
				}
				else {ans++;break;}
			}
			else
			{
				if(a[j-1]==3)
				{
					a[j-1]=0;j--;
				}
				else {ans++;break;}
			}
		}
		if(ans==0) printf("Yes\n");
		else printf("No\n");
	}
}
