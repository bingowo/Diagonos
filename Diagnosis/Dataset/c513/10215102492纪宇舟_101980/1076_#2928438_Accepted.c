#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int n,ans;
char a[105];
void dfs(int l,int r,int x)
{
	if(l==r)ans=0;
	if(ans==0||l>r)return;
	int i=l,j=l+1;
	if(x==-1)
	{
		while(i<=r)
		{
			int ct=1;
			if(a[i]=='(')
			{
				while(j<=r&&ct!=0)
				{
					if(a[j]=='(')ct++;
					if(a[j]==')')ct--;
					if(ct!=0)j++;
				}
				if(ct!=0){ans=0;break;}
				dfs(i+1,j-1,3);
				i=++j;j++;
			}
			else if(a[i]=='[')
			{
				while(j<=r&&ct!=0)
				{
					if(a[j]=='[')ct++;
					if(a[j]==']')ct--;
					if(ct!=0)j++;
				}
				if(ct!=0){ans=0;break;}
				dfs(i+1,j-1,1);
				i=++j;j++;
			}
			else if(a[i]=='{')
			{
				while(j<=r&&ct!=0)
				{
					if(a[j]=='{')ct++;
					if(a[j]=='}')ct--;
					if(ct!=0)j++;
				}
				if(ct!=0){ans=0;break;}
				dfs(i+1,j-1,2);
				i=++j;j++;
			}
			else{ans=0;break;}
		}
		return;
	}
	if(x==1)
	{
		while(i<=r)
		{
			int ct=1;
			if(a[i]=='(')
			{
				while(j<=r&&ct!=0)
				{
					if(a[j]=='(')ct++;
					if(a[j]==')')ct--;
					if(ct!=0)j++;
				}
				if(ct!=0){ans=0;break;}
				dfs(i+1,j-1,3);
				i=++j;j++;
			}
			else{ans=0;break;}
		}return;
	}
	if(x==2)
	{
		while(i<=r)
		{
			int ct=1;
			if(a[i]=='[')
			{
				while(j<=r&&ct!=0)
				{
					if(a[j]=='[')ct++;
					if(a[j]==']')ct--;
					if(ct!=0)j++;
				}
				if(ct!=0){ans=0;break;}
				dfs(i+1,j-1,1);
				i=++j;j++;
			}
			else{ans=0;break;}
		}return;
	}
	if(x==3)
	{
		while(i<=r)
		{
			int ct=1;
			if(a[i]=='{')
			{
				while(j<=r&&ct!=0)
				{
					if(a[j]=='{')ct++;
					if(a[j]=='}')ct--;
					if(ct!=0)j++;
				}
				if(ct!=0){ans=0;break;}
				dfs(i+1,j-1,2);
				i=++j;j++;
			}
			else{ans=0;break;}
		}return;
	}
}
int main()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		ans=1;
		scanf("%s",a);
		n=strlen(a);
		dfs(0,n-1,-1);
		if(ans)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
} 