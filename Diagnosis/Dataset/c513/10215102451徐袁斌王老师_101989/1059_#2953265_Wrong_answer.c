#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
struct stu
	{
		int a;
		int b;
	};
int cmp(const void *a,const void *b)
{
	int* A=(int*)a;
	int* B=(int*)b;
	return *A-*B;
	
}
int GCD(int m,int n)
{
	if(n==0) return m;
	return GCD(n,m%n);
}
int main()
{
	int n,s,d;
	scanf("%d%d",&n,&s);
	struct stu x[1000];
	for(int i=0;i<1000;i++)
	{
		x[i].a=-1;x[i].b=0;
	}
	int a[1000];
	int *p=a;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	qsort(p,n,sizeof(a[0]),cmp);
	d=a[0];x[0].a=a[0];x[0].b=0;
	for(int i=0,j=0;i<n;i++)
	{
		if(a[i]==d)
		{
			x[j].b++;
		}
		else
		{
			j++;x[j].a=a[i];x[j].b=1;d=a[i];
		}
	}
	int i=0,ans=x[i].a;
	while(x[i+1].a!=-1&&((x[i+1].a-x[i].a)*x[i].b<=s))
	{
		ans=x[i+1].a;s=s-(x[i+1].a-x[i].a)*x[i].b;x[i+1].b+=x[i].b;i++;
	}
	int y=1;
	if(x[i+1].a!=-1) 
	{
		y=GCD(s,(x[i+1].a-x[i].a)*x[i].b);
	}
	else
	{
		
		if(s>=x[i].b)
		{
			ans=x[i].a+s/x[i].b;s=s%x[i].b;
		}
		else 
		{
			y=GCD(s,x[i].b);
		}
	}
	printf("%d",ans);
	if(s!=0)
	{
		if(x[i+1].a!=-1)
		{
			printf("+%d/%d",s/y,(x[i+1].a-x[i].a)*x[i].b/y);
		}
		else
		{
			printf("+%d/%d",s/y,x[i].b/y);
		}
	}
	
	
	
}