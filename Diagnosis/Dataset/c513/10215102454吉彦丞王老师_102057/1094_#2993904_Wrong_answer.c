#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct data
{
	char s[121];
	int l;
};
int cmp1(const void *pa,const void *pb)
{
	struct data a,b;
	a=*((struct data *)pa);
	b=*((struct data *)pb);
	if(a.l==b.l)
	{
		return strcmp(b.s,a.s);
	}
	else
	{
		return b.l-a.l;
	}
}
int main()
{
	int number;
	scanf("%d",&number);
	struct data p[number];
	int t=0;
	for(int i=0;i<number;i++)
	{
		scanf("%s",&p[i].s);
		p[i].l=strlen(p[i].s);
		if(p[i].s[0]=='-')
		{
			t++;
		}
	}
	if(t==0)
	{
		qsort(p,number,sizeof(p[0]),cmp1);
		int a[p[0].l];
		int b[p[0].l];
		for(int i=0;i<p[0].l;i++)
		{
			a[i]=0;
			b[i]=0;
		}
		for(int i=p[0].l-1;i>=0;i--)
		{
			a[i]=p[0].s[i]-'0';
		}
		for(int i=p[0].l-1;i>=p[0].l-p[number-1].l;i--)
		{
			b[i]=p[number-1].s[p[0].l-1-i]-'0';
		}
		for(int i=p[0].l-1;i>=0;i--)
		{
			if(a[i]<b[i])
			{
				a[i]=a[i]+10-b[i];
				a[i-1]-=1;
			}
			else
			{
				a[i]=a[i]-b[i];
			}
		}
		int n=0;
		for(int i=0;i<p[0].l;i++)
		{
			if(a[i]==0)
			{
				n++;
			}
			else
			{
				break;
			}
		}
		for(int i=n;i<p[0].l;i++)
		{
			printf("%d",a[i]);
		}
	}
	else if(t==number)
	{
		qsort(p,number,sizeof(p[0]),cmp1);	
	}
	return 0;
} 