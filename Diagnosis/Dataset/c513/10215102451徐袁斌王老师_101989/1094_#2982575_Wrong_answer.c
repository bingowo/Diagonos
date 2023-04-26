#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
struct stu
	{
		char a[150];
		int b;
	};
int cmp(const void *a,const void *b)
{
	struct stu* A=(struct stu*)a;
	struct stu* B=(struct stu*)b;
	if(A->a[0]=='-'||B->a[0]=='-')
	{
		if(A->a[0]=='-'&&B->a[0]=='-')
		{
			if(A->b!=B->b) return A->b-B->b;
			else return strcmp(A->a,B->a);
		}
		else if(A->a[0]=='-') return 1;
		else if(B->a[0]=='-') return -1;
	} 
	else
	{
		if(A->b!=B->b) return B->b-A->b;
		else return strcmp(B->a,A->a);
	}
}

int main()
{
	int t,ans[150],d,e=0;
	struct stu x[50];
	struct stu *p=x;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%s",x[i].a);
		x[i].b=strlen(x[i].a);
	}
	qsort(p,t,sizeof(x[0]),cmp);
	int j=0;
	if(x[t-1].a[0]=='-'&&x[0].a[0]!='-')
	{
		if(x[t-1].b>x[0].b) {d=x[t-1].b;}
		else d=x[0].b;
		for(int i=d;i>=0;i--)
		{
			if(x[t-1].b>1&&x[0].b>0)
			{
				ans[i]=x[t-1].a[x[t-1].b-1]-'0'+x[0].a[x[0].b-1]-'0'+e;
				e=ans[i]/10;
				ans[i]=ans[i]%10;
				x[t-1].b--;x[0].b--;
			}
			else if(x[t-1].b<=1)
			{
				ans[i]=x[0].a[x[0].b-1]-'0'+e;
				e=ans[i]/10;
				ans[i]=ans[i]%10;
				x[t-1].b--;x[0].b--;
				
			}
			else if(x[0].b<=0)
			{
				j=1;
				ans[i]=x[t-1].a[x[t-1].b-1]-'0'+e;
				e=ans[i]/10;
				ans[i]=ans[i]%10;
			}
		}
	}
	else
	{
		if(x[t-1].b>x[0].b) d=x[t-1].b;
		else d=x[0].b;
		for(int i=d;i>=0;i--)
		{
			if(x[t-1].b>0&&x[0].b>0)
			{
				ans[i]=x[0].a[x[0].b-1]-x[t-1].a[x[t-1].b-1]-e;
				if(ans[i]<0) {ans[i]+=10;e=1;}
				else e=0;
				x[t-1].b--;x[0].b--;
			}
			else if(x[t-1].b<=0)
			{
				ans[i]=x[0].a[x[0].b-1]-'0'-e;
				if(ans[i]<0) {ans[i]+=10;e=1;}	
				else e=0;
				x[t-1].b--;x[0].b--;	
			}
		}
	}
	if(ans[j]<=0) j++;
	for(;j<d;j++)
	{
		printf("%d",ans[j]);
	}
	
	
}